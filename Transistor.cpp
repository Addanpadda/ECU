#include <Arduino.h>
#include "Transistor.hpp"

Transistor::Transistor(const unsigned int &pin) {
    this->_pin = pin;
    pinMode(pin, OUTPUT);
}

void Transistor::setOpenFactor(const float &openFactor) {
    this->setOpen((int)(255.0*openFactor+0.5));
}

void Transistor::setOpen(const int &pwm) {
    this->currentPWM = pwm;
    analogWrite(this->_pin, this->currentPWM);
}