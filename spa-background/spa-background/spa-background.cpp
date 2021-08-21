#include "QueryParser.h"
#include <iostream>

int main() {
  QueryParser *parser = new QueryParser();

  std::string text = "stmt a, ;call meMaybe, ; read r1, r2, r3, r4; stmt s1 s2;`` assign kevinGroupLeader;";
  parser->parse(text);
}