#ifndef FUELINJECTOR_H
#define FUELINJECTOR_H
#include "Transistor.hpp"

class FuelInjector: public Transistor  {
  using Transistor::Transistor;

public:
  static float calculateOpenFactor(int rpm, float airFlow, float airFuelRatio);
};

#endif
