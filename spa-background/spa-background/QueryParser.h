#include "Query.h"
#include <string>

class QueryParser {
private:
  std::string text;
  std::string nextToken;
  Query* curr;

public:
  std::string peekToken();
  void scanToken();

  bool parseSelectCl();
  bool parseSynonym();
  bool parseDeclarations();


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
  bool parseDE();
  bool parse(std::string);
  // Query retrieveQuery();
};