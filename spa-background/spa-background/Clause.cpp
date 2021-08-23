#include "Clause.h"

Clause::Clause(ClauseType t, std::vector<std::string> p) {
  type = t;
  params = p;
}

ClauseType Clause::getType() { return type; }
std::vector<std::string> Clause::getParams() { return params; }