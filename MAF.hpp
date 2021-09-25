
#define MAF_PIN A0

class MAF {
private:
  int mapValue(int voltage);

public:
  int get(); // KG/H
};
