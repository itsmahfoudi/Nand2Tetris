#include <Code.hpp>
#include <stdexcept>
#include <unordered_map>

std::unordered_map<std::string, std::string> compTable = {
  {"0"   ,"0101010"},
  {"1"   ,"0111111"},
  {"-1"  ,"0111010"},
  {"D"   ,"0001100"},
  {"A"   ,"0110000"},
  {"!D"  ,"0001101"},
  {"!A"  ,"0110001"},
  {"-D"  ,"0001111"},
  {"-A"  ,"0110011"},
  {"D+1" ,"0011111"},
  {"A+1" ,"0110111"},
  {"D-1" ,"0001110"},
  {"A-1" ,"0110010"},
  {"D+A" ,"0000010"},
  {"D-A" ,"0010011"},
  {"A-D" ,"0000111"},
  {"D&A" ,"0000000"},
  {"D|A" ,"0010101"},
  {"M"   ,"1110000"},
  {"!M"  ,"1110001"},
  {"-M"  ,"1110011"},
  {"M+1" ,"1110111"},
  {"M-1" ,"1110010"},
  {"D+M" ,"1000010"},
  {"D-M" ,"1010011"},
  {"M-D" ,"1000111"},
  {"D&M" ,"1000000"},
  {"D|M" ,"1010101"},
};

std::unordered_map<std::string, std::string> destTable = {
  {"null" ,"000"},
  {"M"    ,"001"},
  {"D"    ,"010"},
  {"DM"   ,"011"},
  {"A"    ,"100"},
  {"AM"   ,"101"},
  {"AD"   ,"110"},
  {"ADM"  ,"111"}
};

std::unordered_map<std::string, std::string> jumpTable = {
  {"null" ,"000"},
  {"JGT"  ,"001"},
  {"JEQ"  ,"010"},
  {"JGE"  ,"011"},
  {"JLT"  ,"100"},
  {"JNE"  ,"101"},
  {"JLE"  ,"110"},
  {"JMP"  ,"111"}
};



std::string Code::dest(std::string dMnemonic) {
  auto it = destTable.find(dMnemonic);
  if (it == destTable.end()) {
    throw std::domain_error("dest mnemonic doesn't exits!!!");
  }
  return it->second;
}

std::string Code::jump(std::string jMnemonic) {
  auto it = jumpTable.find(jMnemonic);
  if (it == jumpTable.end()) {
    throw std::domain_error("jump mnemonic doesn't exits!!!");
  }
  return it->second;
}

std::string Code::comp(std::string cMnemonic) {
  auto it = compTable.find(cMnemonic);
  if (it == compTable.end()) {
    throw std::domain_error("comp mnemonic doesn't exits!!!");
  }
  return it->second;
}


