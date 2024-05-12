#include "./../Inc/Symbol.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>

std::string paddedString(std::string input) {
  std::stringstream res(input);
  int length = input.length();
  for (int i=length; i < 30 ; i++) {
    res << " ";
  }
  res << "| ";
  return res.str();
}

void Symbol::addEntry(const std::string& symbol, int address) {
  Symbol::symbolTable[symbol] = address;
}

bool Symbol::contains(const std::string& symbol) const {
  return symbolTable.count(symbol) > 0;
}

int Symbol::getAddress(const std::string& symbol) const {
  auto it = symbolTable.find(symbol);
  if (it == symbolTable.end()) {
    return -1;
  }
  return it->second;
}

void Symbol::generateST(void) {
  std::stringstream line;
  std::ofstream outputFile(Symbol::path, std::ios::out | std::ios::trunc);
  if (!outputFile.is_open()) {
    throw std::domain_error("Cannot open Symbol table file.\n");
  }
  for(const auto& entry : symbolTable) {
    outputFile << paddedString(entry.first) << " " << entry.second << std::endl;
  }
  outputFile.close();
}
