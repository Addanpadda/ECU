#ifndef SPARK_H
#define SPARK_H

class Spark {
private:
  int _pin;
  
public:
  Spark(int pin);
  void SetAdvance();
};

#endif
