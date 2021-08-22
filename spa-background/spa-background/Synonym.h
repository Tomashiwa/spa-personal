#include "DesignEntity.h"
#include <string>
#include <iostream>

class Synonym {
private:
  DesignEntity type;
  std::string name;

public:
  Synonym(DesignEntity type, std::string name);

  DesignEntity getType();
  std::string getName();

  void print();
};