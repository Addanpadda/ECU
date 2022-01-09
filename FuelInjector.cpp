#include <Arduino.h>
#include "FuelInjector.hpp"
#include "Constants.hpp"

static float FuelInjector::calculateOpenFactor(int rpm, float airFlow, float airFuelRatio) {
  float openFactor;
  float airGramsPerMinute = airFlow * 1000.0/60.0;

  if (rpm == 0 && airFlow == 7) openFactor = 0;
  //else if (rpm > 500 && rpm < 1200) openFactor = 0.706;
  else if (rpm > 20000) openFactor = .012*airFlow*3.4; // .01 - .012 ; If rpm is extremely high, noise is present and engine is starting.8
  //airFuelRatio = airGramsPerMinute / (Constants::Engine::injectorGramsPerMinute * Constants::Engine::numberOfCylinders * openFactor);
  else openFactor = (airGramsPerMinute / (Constants::Engine::injectorGramsPerMinute * Constants::Engine::numberOfCylinders * airFuelRatio))*3.0*3.4;

  if (openFactor > 1.0) openFactor = 1.0; // Injectors can't be open more than 100%

  return openFactor;
}
