#include <Arduino.h>
#include "Transistor.hpp"

Transistor::Transistor(const unsigned int &pin) {
    this->_pin = pin;
    pinMode(pin, OUTPUT);
}

void Transistor::setOpenFactor(const float &openFactor) {
    analogWrite(this->_pin, (int)(255.0*openFactor+0.5));
}