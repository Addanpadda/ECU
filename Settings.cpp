#include "Settings.hpp"

void Settings::apply() {
  // Set PWM frequncy to 3921.16HZ for D3 and D11
  // TCCR2B = TCCR2B & B11111000 | B00000010;
  // Set PWM frequncy to 31372.55 Hz for D3 and D11
  TCCR2B = TCCR2B & B11111000 | B00000001;
  
  // Set PWM frequncy to 62500.00 Hz Hz for D5 and D6
  TCCR0B = TCCR0B & B11111000 | B00000001;
}
