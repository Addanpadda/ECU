#include "Arduino.h"
#include "Spark.hpp"


Spark::Spark(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Spark::SetAdvance() {
  analogWrite(_pin, 15);
}
