#ifndef MAF_H
#define MAF_H

#define MAF_PIN A0

class MAF {
private:
  unsigned int mapValue(float voltage);

public:
  int get(); // KG/H
};

#endif
