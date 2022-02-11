#include "cable.hpp"

Cable::Cable(){};
Cable::Cable(int inputPins[], int outputPins[]){
    
    this->dataS = 0x00;
    this->dataR = 0x00;

    for(int i = 0;i < 8; i++){
        this->inputPins[i]  = inputPins[i];
        this->outputPins[i] = outputPins[i];
    }

    // Configuration des pins
    for(int i = 0;i < 8; i++){
        pinMode(this->inputPins[i], INPUT);
        pinMode(this->outputPins[i], OUTPUT);
    }
};

void Cable::envoi(uint8_t data){
    this->dataS = data;

    for (int i = 0; i < 8; i++)
    {
        if (data & (1 << i)){
            Serial.println((String)"Le bit "+i+" est a 1 Broch output "+this->outputPins[i]);
            digitalWrite(this->outputPins[i], HIGH);
        }else{
            Serial.println((String)"Le bit "+i+" est a 0 Broch output "+this->outputPins[i]);
            digitalWrite(this->outputPins[i], LOW);
        }
    }

    Serial.print("Data envoye : ");
    Serial.println(this->dataS, HEX);
};

void Cable::reception(){
    for (int i = 0; i < 8; i++){
        if(digitalRead(this->inputPins[i]) == HIGH){
            Serial.println((String)"Le bit "+i+" est HIGH Broch input "+this->inputPins[i]);
            this->dataR |= 1 << i;
        }
        else{
            Serial.println((String)"Le bit "+i+" est LOW Broch input "+this->inputPins[i]);
            this->dataR &= ~(1 << i);
        }
    }

    Serial.print("Data recu : ");
    Serial.println(dataR, HEX);
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

bool Cable::verifyCodes(uint8_t send, uint8_t recieve){
    this->dataS = send;

    this->envoi(this->dataS);
    this->reception();

    if(recieve == this->dataR)
        return true;
  
    return false;
}

void Cable::checkCable(){
    if( this->verifyCodes(0xFF, 0xFF)){
        Serial.println("Le cable est fonctionnel");
    }
    else{
        Serial.println("Le cable n'est pas fonctionnel");
    }
};

void Cable::checkCableType(){
    bool droit = true;
    int CodeSend[] = {0x1, 0x2, 0x4, 0x20};
    int CodeReci[] = {0x4, 0x20, 0x1, 0x2};

    for(int i = 0; i < sizeof(CodeReci)/sizeof(int) ; i++){
        Serial.println(i);
        if(!this->verifyCodes(CodeSend[i], CodeReci[i])){
            droit = false;
            continue;
        }
    }

    if(droit){
        Serial.println("Le cable est croise");
    }
    else{
        Serial.println("Le cable est Droit");
    }
};