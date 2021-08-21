#include "Query.h"

Query::Query() { this->selected = nullptr; }

void Query::selectSynonym(Synonym s) { selected = &s; }
void Query::addSynonym(Synonym s) { synonyms.push_back(s); }
void Query::addClause(Clause c) { clauses.push_back(c); }

Synonym* Query::getSelected() { return selected; }
std::vector<Synonym> Query::getSynonyms() { return synonyms; }
std::vector<Clause> Query::getClauses() { return clauses; }