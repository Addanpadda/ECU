#include <Arduino.h>
#include "FuelInjector.hpp"

FuelInjector::FuelInjector(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void FuelInjector::SetOpenTime(float openTime) {
  analogWrite(_pin, (int)(255.0*openTime+0.5));
}
