#include <Arduino.h>
#include "cable.hpp"

int input[8]  = {1, 2, 3, 4, 5, 6, 7, 8};
int output[8] = {10, 20, 30, 40, 50, 60, 70, 80};

Cable cable(input, output);

void setup() {
  while (!Serial) {};
  Serial.println("Debut");
  cable.printInputPins();
  cable.printOutputPins();
  uint8_t c = 0x1;
  cable.envoi(0xFF);
  cable.reception();
  if(cable.checkCable()){
    Serial.println("Le cable est fonctionnel");
  }
  else{
    Serial.println("Le cable n'est pas fonctionnel");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}