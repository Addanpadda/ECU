#ifndef MAF_H
#define MAF_H

class MAF {
private:
  unsigned int mapValue(float voltage);
  int _pin;

public:
  MAF(int pin);
  int get(); // KG/H
};

#endif
