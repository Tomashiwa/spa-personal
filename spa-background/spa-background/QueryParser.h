#include "Query.h"
#include <string>

class QueryParser {
private:
  std::string text;
  std::string nextToken;
  Query* query;
  DesignEntity entityType;

public:
  bool hasRemainingText();

  std::string peekToken();
  void scanToken();

  Query retrieveQuery();
  bool parse(std::string);
  bool parseSelectCl();
  bool parseDeclarations();
  bool parseSelect();
  bool parseSynonym();

  bool parseDE();

  /* bool parseInt();
  bool parseName();
  bool parseVarName();
  bool parseFactor();
  bool parseTerm();
  bool parseExpr();
  bool parseExprSp();
  bool parseEntRef();
  bool parseSynA();
  bool parsePT();
  bool parseRel();
  bool parseST();
  bool parseIden();*/
};