#include "QueryParser.h"
#include <iostream>
#include <regex>

std::string QueryParser::peekToken() {
  std::regex token(
      "[^a-zA-Z0-9_\\s]|(such that)|[a-zA-Z0-9]+(\\*)*|(_)?[a-zA-Z0-9]+(_)?");
  std::smatch match;
  if (std::regex_search(text, match, token)) {
    return match[0];
  } else {
    return "\0";
  }
}

void QueryParser::scanToken() {
  std::regex token(
      "[^a-zA-Z0-9_\\s]|(such that)|[a-zA-Z0-9]+(\\*)*|(_)?[a-zA-Z0-9]+(_)?");
  std::smatch match;

  if (std::regex_search(text, match, token)) {
    // std::cout << match[0] << "\n";
    nextToken = match[0];

    size_t pos = text.find(match[0]);
    if (pos != std::string::npos) {
      text.erase(pos, match[0].length());
    }
  } else {
    nextToken = "\0";
  }
}

bool QueryParser::parseDeclarations() {
  while (peekToken() != "Select") {
    if (!parseDE()) {
      return false;
    }

    if (!parseSynonym()) {
      return false;
    }

    scanToken();

    while (nextToken == ",") {
      if (!parseSynonym()) {
        return false;
      }
      scanToken();
    }

    if (nextToken != ";") {
      return false;
    }
  }
  return true;
}

bool QueryParser::parseDE() {
  scanToken();
  std::cout << "[DE]: " << nextToken << "\n";

  std::regex test("(stmt)|(read)|(print)|(call)|(while)|(if)|(assign)|("
                  "variable)|(constant)|(procedure)");
  std::smatch match;
  return std::regex_search(nextToken, match, test);
}

bool QueryParser::parseSynonym() {
  scanToken();
  std::cout << "[SYN]: " << nextToken << "\n";

  std::regex test("[A-Za-z]([A-Za-z0-9])*");
  std::smatch match;
  return std::regex_search(nextToken, match, test);
}

bool QueryParser::parseSelectCl() {
  if (!parseDeclarations()) {
    return false;
  }

  scanToken();

  if (nextToken != "Select") {
    return false;
  } else {
    std::cout << "SELECT" << "\n";
  }

  if (!parseSynonym()) {
    return false;
  }

  return true;
}

bool QueryParser::parse(std::string str) {
  text = str;
  return parseSelectCl();
}