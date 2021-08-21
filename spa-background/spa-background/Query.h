#include "Clause.h"
#include "Synonym.h"
#include <vector>

class Query {
private:
  Synonym* selected;
  std::vector<Synonym> synonyms;
  std::vector<Clause> clauses;

public:
  Query();

  void selectSynonym(Synonym);
  void addSynonym(Synonym);
  void addClause(Clause);

  Synonym* getSelected();
  std::vector<Clause> getClauses();
  std::vector<Synonym> getSynonyms();
};