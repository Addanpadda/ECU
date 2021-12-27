#ifndef ECU_H
#define ECU_H

#include <Arduino.h>
#include "RPM.hpp"
#include "MAF.hpp"
#include "FuelInjector.hpp"
#include "Spark.hpp"
#include "Transistor.hpp"

class ECU {
private:
  RPM *rpm;
  MAF *maf;
  FuelInjector *fuelInjector;
  Spark *spark;
  Transistor *idleAirControlValve;
  Table<unsigned int, unsigned int, float> *AFRTable;

  static float calculateLoad(int rpm, int airFlow);

public:
  ECU();
  void loop();
};

#endif
