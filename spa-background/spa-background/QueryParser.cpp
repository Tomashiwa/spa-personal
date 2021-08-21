#include "QueryParser.h"
#include <iostream>
#include <regex>

std::string QueryParser::scanToken() {
  std::regex token("[^a-zA-Z0-9_\\s]|(such that)|[a-zA-Z0-9]+(\\*)*|(_)?[a-zA-Z0-9]+(_)?");
  std::smatch match;

  if (std::regex_search(text, match, token)) {
    std::cout << match[0] << "\n";
    
    size_t pos = text.find(match[0]);
    if (pos != std::string::npos) {
      text.erase(pos, match[0].length());
    }

    return match[0];
  } else {
    return "\0";
  }
}

bool QueryParser::parse(std::string str) {
  text = str;

  nextToken = scanToken();

  while (nextToken != "\0") {
    nextToken = scanToken();
  }

  return true;
}