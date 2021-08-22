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

  void selectSynonymByName(std::string);
  void addSynonym(Synonym);
  void addClause(Clause);

  Synonym* getSelected();
  std::vector<Clause> getClauses();
  Synonym *getSynonym(std::string name);
  std::vector<Synonym> getSynonyms();
};