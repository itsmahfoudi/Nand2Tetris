#include <string>
#include <unordered_map>

/*
 * This class creates a symbol table to map symbols to their memory addresses.
*/
class Symbol {
  private:
    std::unordered_map<std::string, int> symbolTable;
    std::string path;
  public:
    Symbol();
    
    /* @brief :
    * Routine Name : addEntry
    * In : symbol  - The symbol to be added
    *      address - The memory address associated with th symbol
    * Out : None
    * Description : This Routine adds a new entry to the symbol table
    */
    void addEntry(const std::string& symbol, int address);
    
    /* @brief :
    * Routine Name : contains
    * In : symbol  - The symbol to look-for
    * Out : True if the symbol does exits int the symbol table, False otherwise.
    * Description : Check if the symbol tabel contains the given symbol.
    */
    bool contains(const std::string& symbol) const;
 
    /* @brief :
    * Routine Name : getAddress
    * In : symbol  - The symbol associated with the address
    * Out : The memory address associated with the given symbol, -1 if the symbol 
    *       doesn't exits in the symbol table
    * Description : This Routine gets the memory address associated with the given symbol. 
    */
    int getAddress(const std::string& symbol) const;
    
    /* @brief :
    * Routine Name : generateST
    * In : None 
    * Out : None
    * Description : This routine copies the content of the symbol table to separate file. 
    */
    void generateST(void);
};
