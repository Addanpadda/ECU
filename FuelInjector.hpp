#ifndef FUELINJECTOR_H
#define FUELINJECTOR_H

class FuelInjector {
private:
  int _pin;
  
public:
  FuelInjector(int pin);
  void SetOpenTime(float openTime);
};

#endif
