#include "Synonym.h"

Synonym::Synonym(DesignEntity t, std::string n) {
  type = t;
  name = n;
}

void Synonym::print() {
  switch (type) {
  case DesignEntity::Statement:
    std::cout << "[STMT]:";
    break;
  case DesignEntity::Read:
    std::cout << "[READ]:";
    break;
  case DesignEntity::Print:
    std::cout << "[PRNT]:";
    break;
  case DesignEntity::Call:
    std::cout << "[CALL]:";
    break;
  case DesignEntity::While:
    std::cout << "[WHIL]:";
    break;
  case DesignEntity::If:
    std::cout << "[IF]:";
    break;
  case DesignEntity::Assign:
    std::cout << "[ASS]:";
    break;
  case DesignEntity::Variable:
    std::cout << "[VAR]:";
    break;
  case DesignEntity::Constant:
    std::cout << "[CONST]:";
    break;
  case DesignEntity::Procedure:
    std::cout << "[PROD]:";
    break;
  case DesignEntity::Undefined:
    std::cout << "[UNDEFINED]";
    break;
  }
  std::cout << " " << name << "\n";
}

DesignEntity Synonym::getType() { return type; }
std::string Synonym::getName() { return name; }