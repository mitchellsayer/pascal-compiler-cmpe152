#include <iostream>
#include <fstream>
#include <thread>
#include "antlr4-runtime.h"
#include "frontend/ErrorHandlers.h"
#include "frontend/Semantics.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/util/BackendMode.h"
#include "backend/Compiler.h"
#include "PascalLexer.h"
#include "PascalParser.h"
using namespace antlrcpp;
using namespace antlr4;
using namespace std;
using namespace frontend;
using namespace backend;

int main(int argc, const char *args[]) {
  if (argc < 3) {
    return 1;
  }
  ifstream ins;
  ofstream ofs;

  // Create the input stream.
  ins.open(args[1]);
  // ofs.open(args[2]);

  freopen(args[2],"w",stdout);

  ANTLRInputStream input(ins);

  SyntaxErrorHandler syntaxErrorHandler;

  // Create a lexer which scans the input stream
  // to create a token stream.
  PascalLexer lexer(&input);
  lexer.removeErrorListeners();
  lexer.addErrorListener(&syntaxErrorHandler);
  CommonTokenStream tokens(&lexer);

  PascalParser parser(&tokens);

  cout << endl << "Parsing Pass: ";
  parser.removeErrorListeners();
  parser.addErrorListener(&syntaxErrorHandler);
  tree::ParseTree *tree = parser.program();

  this_thread::sleep_for(chrono::milliseconds(100));

  int errorCount = syntaxErrorHandler.getCount();
  if (errorCount > 0) {
      printf("\nSyntax errors found: %d\n", errorCount);
      return errorCount;
  } else {
      cout << "There were no syntax errors." << endl;
  }

  // Print the parse tree in Lisp format.
  cout << endl << "Parse tree (Lisp format):" << endl;
  cout << tree->toStringTree(&parser) << endl;

  // Frontend Semantics Pass
  cout << endl << "Semantic Pass:" << endl ;
  Semantics *semantics = new Semantics();
  semantics->visit(tree);

  int error_count = semantics->getErrorCount();
  if (error_count > 0) {
    cout << endl << "Semantic errors found: " << error_count << endl;
    return errorCount;
  } else {
      cout << "There were no semantic errors." << endl;
  }

  // Pass 3: Compile the Pascal program.
  cout << endl << "PASS 3 Compilation: ";
  SymtabEntry *programId = semantics->getProgramId();
  Compiler *compiler = new Compiler(programId);
  compiler->visit(tree);

  // cout << "Object file \"" << compiler->getObjectFileName() << "\" created." << endl;

  std::cout << tree << endl;
  return 0;
}