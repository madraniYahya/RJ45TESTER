#include <Arduino.h>
#include "cable.hpp"

// Simulation cable droit
int input[8]  = {15, 17, 18, 19, 21, 22, 5, 23};
int output[8] = {13, 14, 27, 26, 25, 33, 32, 12};


// Simulation cable croise
//int input[8]  = {15, 17, 18, 19, 21, 22, 5, 23};
//int output[8] = {27, 33, 13, 26, 25, 14, 32, 12};

/*
  code en hex pour envoi et reception pour la verification droit/croise
  S  > R
  1  > 4
  2  > 20
  4  > 1
  20 > 2
*/

Cable cable(input, output);


void setup() {
  Serial.begin(9600);
  while (!Serial) {};
  // Preparation du cable
  cable.printInputPins();
  cable.printOutputPins();
}

void loop() {

  // Tester si le cable confionne
  //cable.checkCable();

  // Verifier si le cable est droit ou croise
  cable.checkCableType();

  delay(3000);
}