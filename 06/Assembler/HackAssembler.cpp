#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <Parser.hpp>

int main(int argc, char *argv[]) {
  /* check for the number of arguments */
  if (argc < 2) {
    std::cerr << "error : file not speciefied!!\n usage -HackAssembler file.asm- " << std::endl;
  }

  /* check for file extension*/
  std::string inFileName(argv[1]);
  if (inFileName.substr(inFileName.find(".")+1).compare("asm") != 0) {
    std::cerr << "error : file wrong extension: usage -HackAssembler file.asm- " << std::endl;
    return -1;
  }

  /* Instantiate the Parser object */
  Parser parser(inFileName);
  
  // get the current, it will be used by the symbol module
  //std::cout << std::filesystem::current_path() << '\n';

  /* recover input fileName to use it as the output file name */
  std::string outFileName(inFileName.substr(0, inFileName.find("."))); 

  /* create the output file*/
  std::string line;
  std::ofstream outputFile(outFileName + ".hack", std::ios::out | std::ios::trunc);

  return 0;
}
