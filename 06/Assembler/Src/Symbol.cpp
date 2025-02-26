#include <fstream>
#include <stdexcept>
#include <sstream>
#include <Symbol.hpp>

Symbol::Symbol() {
  // initialize the symobol table with the predefined symbol
  symbolTable["SP"] = 0x0000;
  symbolTable["LCL"] = 0x0001;
  symbolTable["ARG"] = 0x0002;
  symbolTable["THIS"] = 0x0003;
  symbolTable["THAT"] = 0x0004;
  symbolTable["KBD"] = 0x6000;
  symbolTable["SCREEN"] = 0x4000;
  std::stringstream ss("");
  for (unsigned char c = 0; c < 16; c++) {
    ss << "R" << c-0;
    symbolTable[ss.str()] = c;
    ss.str("");
  }  
}

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
  if (contains(symbol)) {
    throw std::domain_error("Symbol " + symbol+ "already use");
  }
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
