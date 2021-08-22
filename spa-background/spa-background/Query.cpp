#include "Query.h"

Query::Query():selected(DesignEntity::Undefined, "") {  }

void Query::selectSynonymByName(std::string name) { 
  for (Synonym s : synonyms) {
    if (s.getName() == name) {
      selected = s;
      return;
    }
  }
  Synonym incompleteSyn(DesignEntity::Undefined, name);
  selected = incompleteSyn;
}

void Query::addSynonym(Synonym s) { synonyms.push_back(s); }
void Query::addClause(Clause c) { clauses.push_back(c); }
Synonym Query::getSelected() { return selected; }

Synonym Query::getSynonym(std::string name) {
  for (Synonym s : synonyms) {
    if (s.getName() == name) {
      return s;
    }
  }
  Synonym emptySny(DesignEntity::Undefined, "");
  return emptySny;
}

std::vector<Synonym> Query::getSynonyms() { return synonyms; }
std::vector<Clause> Query::getClauses() { return clauses; }