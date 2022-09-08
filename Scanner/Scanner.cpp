#include <iostream>
#include <fstream>
#include <string>

#include "Scanner.h"

namespace frontend {
using namespace std;
    Token * Scanner::nextToken() {
        char ch = source->currentChar();

        // Skip blanks and other whitespace characters.
        while (isspace(ch)) {
            ch = source->nextChar();
        }

        if (isalpha(ch)) {
            return Token::identifier_token(ch, source);
        } else if (isdigit(ch)) {
            return Token::number_token(ch, source);
        } else if (ch == '\'') {
            return Token::string_token(ch, source);
        }
        return Token::symbol_token(ch, source);
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        return 1;
    }
    std::string input_filename = argv[1];
    std::string output_filename = argv[2];

    std::ofstream outfile;
    outfile.open(output_filename);

    frontend::Scanner scanner(input_filename);
    frontend::Token::initializeTable();
    
    frontend::Token *t = scanner.nextToken();
    while (t->type != frontend::TokenType::END_OF_FILE) {
        outfile << *t;
        t = scanner.nextToken();
    }

    outfile.close();
    return 0;
}