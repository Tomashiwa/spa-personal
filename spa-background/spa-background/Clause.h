#include "ClauseType.h"
#include <string>
#include <vector>

class Clause {
private:
  ClauseType type;
  std::vector<std::string> params;

public:
  Clause(ClauseType, std::vector<std::string>);
  ClauseType getType();
  std::vector<std::string> getParams();
};