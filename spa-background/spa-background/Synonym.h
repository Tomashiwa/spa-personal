#include "DesignEntity.h"
#include <string>
#include <iostream>

class Synonym {
private:
  DesignEntity type;
  std::string name;

public:
  Synonym(DesignEntity, std::string);

  DesignEntity getType();
  std::string getName();

  void print();
};