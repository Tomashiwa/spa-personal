#include "QueryParser.h"
#include <iostream>
#include <regex>

bool QueryParser::hasRemainingText() {
  return text.find_first_not_of("\s\t\r\n ") != std::string::npos;
}

std::string QueryParser::peekToken() {
  std::regex token(
      "[^a-zA-Z0-9_\\s\\n]|(such that)|[a-zA-Z0-9]+(\\*)*|(_)?[a-zA-Z0-9]+(_)?");
  std::smatch match;
  if (std::regex_search(text, match, token)) {
    return match[0];
  } else {
    return "\0";
  }
}

void QueryParser::scanToken() {
  std::regex token(
      "[^a-zA-Z0-9_\\s\\n]|(such that)|[a-zA-Z0-9]+(\\*)*|(_)?[a-zA-Z0-9]+(_)?");
  std::smatch match;

  if (std::regex_search(text, match, token)) {
    nextToken = match[0];
    //std::cout << nextToken << "\n";

    size_t pos = text.find(match[0]);
    if (pos != std::string::npos) {
      text.erase(pos, match[0].length());
    }
  } else {
    nextToken = "\0";
  }
}

Query QueryParser::retrieveQuery() { return query; }

bool QueryParser::parse(std::string str) {
  text = str;

  bool hasParseSucceed = parseSelectCl();

  std::cout << "--Synonyms--\n";
  std::vector<Synonym> synonyms = query.getSynonyms();
  for (int i = 0; i < synonyms.size(); i++) {
    synonyms[i].print();
  }

  std::cout << "--Selected Synonym--\n";
  query.getSelected().print();

  // std::cout << "--Clauses--\n";

  return hasParseSucceed;
}

bool QueryParser::parseSelectCl() {
  if (!parseDeclarations()) {
    return false;
  }

  if (!parseSelect()) {
    return false;
  }

  if (!parseSynonym()) {
    return false;
  }

  query.selectSynonymByName(nextToken);

  // Parse clauses here...

  std::cout << "Has remaining text? " << hasRemainingText() << "\n";

  if (hasRemainingText()) {
    return false;
  }

  return true;
}

bool QueryParser::parseDeclarations() {
  while (peekToken() != "Select") {
    if (!parseDE()) {
      return false;
    }

    if (!parseSynonym()) {
      return false;
    }

    query.addSynonym(Synonym(entityType, nextToken));
    scanToken();

    while (nextToken == ",") {
      if (!parseSynonym()) {
        return false;
      }
      query.addSynonym(Synonym(entityType, nextToken));
      scanToken();
    }

    if (nextToken != ";") {
      return false;
    }
  }
  return true;
}

bool QueryParser::parseSelect() {
  scanToken();
  return nextToken == "Select";
}

bool QueryParser::parseSynonym() {
  scanToken();
  std::regex regex("^[A-Za-z]([A-Za-z0-9])*$");
  return std::regex_search(nextToken, regex);
}

bool QueryParser::parseDE() {
  scanToken();
  std::regex regex("^(stmt)|(read)|(print)|(call)|(while)|(if)|(assign)|("
                   "variable)|(constant)|(procedure)$");
  if (std::regex_search(nextToken, regex)) {
    if (nextToken == "stmt") {
      entityType = DesignEntity::Statement;
    } else if (nextToken == "read") {
      entityType = DesignEntity::Read;
    } else if (nextToken == "print") {
      entityType = DesignEntity::Print;
    } else if (nextToken == "call") {
      entityType = DesignEntity::Call;
    } else if (nextToken == "while") {
      entityType = DesignEntity::While;
    } else if (nextToken == "if") {
      entityType = DesignEntity::If;
    } else if (nextToken == "assign") {
      entityType = DesignEntity::Assign;
    } else if (nextToken == "variable") {
      entityType = DesignEntity::Variable;
    } else if (nextToken == "constant") {
      entityType = DesignEntity::Constant;
    } else if (nextToken == "procedure") {
      entityType = DesignEntity::Procedure;
    } else {
      entityType = DesignEntity::Undefined;
    }
    return true;
  }
  return false;
}