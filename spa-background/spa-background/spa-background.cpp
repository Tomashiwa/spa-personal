#include "QueryParser.h"
#include <iostream>

int main() {
  QueryParser *parser = new QueryParser();
  std::string text = "stmt a; read a; print a; call meMaybe; while a; if a; assign kevinGroupLeader; variable v; constant c; procedure p, q, r, s; Select potato";
  //std::string text = "read r1, r2, r3, r4; variable v1, v2,v3,v4; Select r2 Select";
  //std::string text = "read r1; Select r1";
  //std::string text = "read r1, r2, r3, r4;stmt s1, s2; Select abc1abc23";
  //std::string text = "asdf x;";
  //std::string text = "read 123r1; Select r1";
  //std::string text = "stmt s1, s2 Select s1";
  //std::string text = "assign a; variable v;Select v		\n\n	 \n \n	";

  std::cout << text << "\n";
  std::cout << "Is this valid ? " << parser->parse(text) << "\n ";
}