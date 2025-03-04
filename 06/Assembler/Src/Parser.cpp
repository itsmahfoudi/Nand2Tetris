#include <Parser.hpp>

bool isCommentOrEmpty(std::string line) {
    // verify if it is a comment
    if (line.size() >= 2 && line[0] == '/' && line[1] == '/') {
        return true;
    }

    // verify if it is an empty line
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ')
            return false;
    }
    return true;
}
Parser::Parser(std::string inFileName) {     
    Parser::inputFile.open(inFileName, std::ios_base::in);
    std::string line;
    if (!Parser::inputFile.is_open()) {
        std::domain_error("could not open the specify input file\n");
    }
    while (std::getline(inputFile, line))
    {
        if (!isCommentOrEmpty(line)) {
            Parser::commands.push_back(line);
        }
    }
    
}

bool Parser::hasMoreCommands() {
    return Parser::cursor < Parser::commands.size();
}
