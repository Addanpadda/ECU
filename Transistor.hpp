#ifndef TRANSISTOR_H
#define TRANSISTOR_H

class Transistor {
protected:
    unsigned int _pin;

public:
    Transistor(const unsigned int &pin);
    void setOpenFactor(const float &openFactor);
};

#endif