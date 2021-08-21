#include "QueryParser.h"
#include <iostream>

int main() {
  QueryParser *parser = new QueryParser();

  //std::string text = "stmt a; read a; print a; call meMaybe; while a; if a; assign kevinGroupLeader; variable v; constant c; procedure p, q, r, s; Select potato";
  std::string text = "stmt a; Select 1abc";

  std::cout << "Testing " << text << ": " << parser->parse(text) << "\n";
}