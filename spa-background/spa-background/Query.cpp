#include "Query.h"

Query::Query() { this->selected = nullptr; }

void Query::selectSynonymByName(std::string name) { 
  for (Synonym s : synonyms) {
    if (s.getName() == name) {
      selected = &s;
    }
  }
  selected = new Synonym(DesignEntity::Undefined, name);
}

void Query::addSynonym(Synonym s) { synonyms.push_back(s); }
void Query::addClause(Clause c) { clauses.push_back(c); }
Synonym* Query::getSelected() { return selected; }

Synonym *Query::getSynonym(std::string name) {
  for (Synonym s : synonyms) {
    if (s.getName() == name) {
      return &s;
    }
  }
  return new Synonym(DesignEntity::Undefined, "");
}

std::vector<Synonym> Query::getSynonyms() { return synonyms; }
std::vector<Clause> Query::getClauses() { return clauses; }