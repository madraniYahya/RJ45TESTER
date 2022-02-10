#include "cable.hpp"

Cable::Cable(){};
Cable::Cable(int inputPins[], int outputPins[]){

    this->dataF = 0xFF;
    this->dataS = 0x00;

    for(int i = 0;i < 8; i++){
        this->inputPins[i]  = inputPins[i];
        this->outputPins[i] = outputPins[i];
    }

    // Configuration des pins
    for(int i = 0;i < 8; i++){
        //pinMode(this->inputPins[i], INPUT);
        //pinMode(this->outputPins[i], OUTPUT);
    }
};

void Cable::envoi(uint8_t data){

    //uint8_t test = 0x01; // 0000 0001

    for (int i = 0; i < 8; i++)
    {
        if (data & (1 << i+1)){
            Serial.println("Le bit est a 1");
            digitalWrite(this->outputPins[i], HIGH);
        }else{
            Serial.println("Le bit est a 0");
            digitalWrite(this->outputPins[i], LOW);
        }
    }
    
};

void Cable::reception(){
    uint8_t data = 0xFF;

    for (int i = 0; i < 8; i++){
        if(digitalRead(this->inputPins[i])){
            this->dataR |= (1 << i+1)
        }
        this->dataR &= data;
    }

};

void Cable::printInputPins(){
    for(int i = 0;i < 8; i++){
        Serial.print(i);
        Serial.print(" : ");
        Serial.print(this->inputPins[i]);
        Serial.print('\n');
    }
};

void Cable::printOutputPins(){
    for(int i = 0;i < 8; i++){
        Serial.print(i);
        Serial.print(" : ");
        Serial.print(this->outputPins[i]);
        Serial.print('\n');
    }
};

bool Cable::checkCable(){
    return this->dataR & 0xFF;
}