/**
 * Scanner class.
 */
#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>

#include "InputFile.h"
#include "Token.h"

namespace frontend {

using namespace std;

class Scanner {
private:
    InputFile *source;

public:
    Scanner(std::string sourceFileName) {
        source = new InputFile(sourceFileName);
    }

    Token * nextToken();
};

}

#endif