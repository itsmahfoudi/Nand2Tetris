#include <string>

class Code {
  public:
 
    /* @brief :
    * Routine Name : dest
    * In : string
    * Out : string
    * Description : Returns the binary code of the dest mnemonic
    */
    std::string dest(std::string dMnemonic);
  
    
    /* @brief :
    * Routine Name : comp
    * In : string
    * Out : string
    * Description : Returns the binary code of the comp mnemonic
    */
    std::string comp(std::string cMnemonic);

    
    /* @brief :
    * Routine Name : dest
    * In : string
    * Out : string
    * Description : Returns the binary code of the jump mnemonic
    */
    std::string jump(std::string jMnemonic);
};
