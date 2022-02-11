#include <Arduino.h>
#include "cable.hpp"

int input[8]  = {15, 17, 18, 19, 21, 22, 5, 23};
int output[8] = {13, 14, 27, 26, 25, 33, 32, 12};

Cable cable(input, output);

void setup() {
  Serial.begin(9600);
  while (!Serial) {};
}

void loop() {
  
  cable.printInputPins();
  cable.printOutputPins();
  cable.envoi(0xFF);
  cable.reception();

  if(cable.checkCable()){
    Serial.println("Le cable est fonctionnel");
  }
  else{
    Serial.println("Le cable n'est pas fonctionnel");
  }

  delay(3000);
}