#include <fstream>
#include <string>
#include <Symbol.hpp>
#include <Code.hpp>
#include <iostream>
#include <vector>

enum instType { A_INSTRUCTION, C_INSTRUCTION, L_INSTRUCTION };

class Parser {
private:
  uint32_t cursor{0};                // current index inside commands vector
  std::ifstream inputFile;           // input file stream
  std::vector<std::string> commands; // vector of commands

public:
  /* @brief :
   * Routine Name : Constructor
   * In : Input file name
   * Out : None
   * Description : Opens the Input file and gets ready to parse it
   */
  Parser(std::string inFileName);

  /* @brief :
   * Routine Name : hasMoreCommands
   * In : None
   * Out : True/false
   * Description : Are there more line in the Input
   */

  bool hasMoreCommands(void);

  /* @brief :
   * Routine Name : advance
   * In : None
   * Out : None
   * Description : Skips over white spaces and comments, if necessary.
   *               Reads the next instruction from the Input, and makes it the
   *               current instruction. This Routine should be called only if 
   *               hasMoreLine is true. Initialy there is no current instruction
   */
  void advance(void);

  /* @brief :
   * Routine Name : instructionType
   * In : None
   * Out : Type of the instruction
   * Description : This Routine returns the type of the current instruction :
   *               A_INSTRUCTION for @xxx, where xxx is either a decimal number or a 
   *               symbol. 
   *               C_INSTRUCTION for dest=comp;jump L_INSTRUCTION for (xxx), where xxx 
   *               is a symbol
   */
  instType instructionType(void);

  /* @brief :
   * Routine Name : symbol
   * In : None
   * Out : string
   * Description : If the current instruction is (xxx), returns the symbol xxx.
   *               If the current instruction is @xxx, returns the symbol or
   *               decimal xxx (as a string). Should be called only if instructionType is
   *               A_INSTRUCTION or L_INSTRUCTION.
   */
  std::string symbol(void);

  /* @brief :
   * Routine Name : dest
   * In : None
   * Out : string
   * Description : returns the symbolic dest part of the c-instruction (8
   *               possibilities). 
   *               Should be called only if instructionType is C_INSTRUCTION.
   */
  std::string dest(void);

  /* @brief :
   * Routine Name : comp
   * In : None
   * Out : string
   * Description : Returns the symbolic comp part of the current c-instruction
   *               (28 possibilities). 
   *               Should be called only if instructionType is
   * C_INSTRUCTION.
   */
  std::string comp(void);

  /* @brief :
   * Routine Name : jump
   * In : None
   * Out : string
   * Description : Returns the symbolic jump part of the current c-instruction
   *               (8 possibilities). 
   *               Should be called only if instructionType is C_INSTRUCTION.
   */
  std::string jump(void);
};
