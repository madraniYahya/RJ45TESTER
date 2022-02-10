#ifndef CABLE_HPP
    #define CABLE_HPP

#include <Arduino.h>

class Cable
{
    private:
        int inputPins[8];
        int outputPins[8];
        uint8_t dataS;
        uint8_t dataR;

    public:
        Cable();
        Cable(int inputPins[], int outputPins[]);

        // codeur
        void envoi();
        // decodeur
        void reception();

        void printInputPins();
        void printOutputPins();

        bool checkCable();
};

#endif // CABLE_HPP