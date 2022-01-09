#ifndef TRANSISTOR_H
#define TRANSISTOR_H

class Transistor {
protected:
    unsigned int _pin;

public:
    Transistor(const unsigned int &pin);
    void Transistor::setOpen(const int &pwm);
    void setOpenFactor(const float &openFactor);

    volatile int currentPWM;
};

#endif