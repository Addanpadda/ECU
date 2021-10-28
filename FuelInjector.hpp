#ifndef FUELINJECTOR_H
#define FUELINJECTOR_H

class FuelInjector {
private:
  int _pin;
  
public:
  FuelInjector(int pin);
  void SetOpenTime(float openFactor);
  static float calculateOpenFactor(int rpm, float airFlow, float airFuelRatio);
};

#endif
