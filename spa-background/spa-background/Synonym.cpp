#include "Synonym.h"

Synonym::Synonym(DesignEntity type, std::string name) {
  this->type = type;
  this->name = name;
}

DesignEntity Synonym::getType() { return type; }

std::string Synonym::getName() { return name; }