#ifndef MAF_H
#define MAF_H
#include "Utils.hpp"
#include "Constants.hpp"

class MAF {
private:
  unsigned int mapValue(float voltage);
  int _pin;
  Graph<float, int> *graph;

public:
  MAF(int pin);
  int get(); // KG/H
};

#endif
