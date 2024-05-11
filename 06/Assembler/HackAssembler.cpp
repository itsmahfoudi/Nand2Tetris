#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string line;
  std::fstream inputFile(argv[1]);
  std::ofstream outputFile("output.txt", std::ios::out | std::ios::trunc);
  while (std::getline(inputFile, line)) {
    outputFile << line << std::endl;
    std::cout << line << std::endl;
  }

  return 0;
}
