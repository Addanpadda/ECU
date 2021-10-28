#include "Settings.hpp"

void Settings::apply() {
    // PWM frequncy to 3921.16HZ for D3 and D11
    // TCCR2B = TCCR2B & B11111000 | B00000010;
    // PWM frequncy to  31372.55 Hz for D3 and D11
    TCCR2B = TCCR2B & B11111000 | B00000001;
}
