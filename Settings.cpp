#include "Settings.hpp"

void Settings::apply() {
    // PWM frequncy to 3921HZ for D3 and D11
    TCCR2B = TCCR2B & B11111000 | B00000010;
}
