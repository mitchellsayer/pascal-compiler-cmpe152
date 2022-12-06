grammar Pascal;

@header {
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;
}

programParams : '(' IDENTIFIER ( ',' IDENTIFIER )* ')' ;
programHeader : PROGRAM programIdentifier programParams? ';' ; 
program : programHeader block '.' ;

programIdentifier locals [SymtabEntry *entry = nullptr] : IDENTIFIER;

declarations : ( constantsPart ';' )? ( typesPart ';' )? ( variablesPart ';' )? ( routinesPart ';')? ;
block : declarations compoundStatement ;

sign : '-' | '+' ;

constantIdentifier locals [Typespec *type = nullptr, SymtabEntry *entry = nullptr] : IDENTIFIER ;
constant locals [Typespec *type = nullptr, Object value = nullptr]  
    : sign? ( IDENTIFIER | unsignedNumber )
    | characterConstant
    | stringConstant;

constantDefinition : constantIdentifier '=' constant ;
constantDefinitionsList : constantDefinition ( ';' constantDefinition )* ;
constantsPart : CONST constantDefinitionsList ;

typeIdentifier locals [Typespec *type = nullptr, SymtabEntry *entry = nullptr] : IDENTIFIER ;
typesPart : TYPE typeDefinitionsList ;
typeDefinitionsList : typeDefinition ( ';' typeDefinition )* ;
typeDefinition : typeIdentifier '=' typeSpecification ;

arrayType : ARRAY '[' arrayDimensionList ']' OF typeSpecification ;
arrayDimensionList : simpleType ( ',' simpleType )* ;

typeSpecification locals [Typespec *type = nullptr]
    : simpleType    # simpleTypespec
    | arrayType     # arrayTypespec;

simpleType locals [Typespec *type = nullptr] 
    : typeIdentifier # typeIdentifierTypespec;

variableIdentifier  locals [Typespec *type = nullptr, SymtabEntry *entry = nullptr] : IDENTIFIER ;
variable locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] : variableIdentifier modifier*;

variablesPart : VAR variableDeclarationsList ;
variableDeclarationsList : variableDeclarations ( ';' variableDeclarations )* ;
variableDeclarations : variableIdentifierList ':' typeSpecification ;
variableIdentifierList : variableIdentifier ( ',' variableIdentifier )* ;

routinesPart      : routineDefinition ( ';' routineDefinition)* ;
routineDefinition : functionHead ';' block ;
functionHead      : FUNCTION  routineIdentifier parameters? ':' typeIdentifier ;

functionName locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] : IDENTIFIER ;
functionCall : functionName '(' argumentList? ')' ;

routineIdentifier   locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] : IDENTIFIER ;

parameterIdentifier   locals [Typespec *type = nullptr, SymtabEntry *entry = nullptr] : IDENTIFIER ;

parameters : '(' parameterDeclarationsList ')' ;
parameterDeclarationsList : parameterDeclarations ( ';' parameterDeclarations )* ;
parameterDeclarations : VAR? parameterIdentifierList ':' typeIdentifier ;
parameterIdentifierList : parameterIdentifier ( ',' parameterIdentifier )* ;

statement : compoundStatement
          | assignmentStatement
          | ifStatement
          | caseStatement
          | repeatStatement
          | whileStatement
          | forStatement
          | writeStatement
          | writelnStatement
          | readStatement
          | readlnStatement
          | emptyStatement;

compoundStatement : BEGIN statementList END ;
emptyStatement : ;

lhs locals [ Typespec *type = nullptr ] : variable ;
rhs : expression ;

statementList : statement ( ';' statement )* ;
assignmentStatement : lhs ':=' rhs ;
repeatStatement : REPEAT statementList UNTIL expression ;
whileStatement : WHILE expression DO statement ;

ifStatement : IF expression THEN trueStatement ( ELSE falseStatement )? ;
trueStatement : statement ;
falseStatement : statement ;

caseStatement locals [map<int, PascalParser::StatementContext*> *jumpTable = nullptr ] : CASE expression OF caseBranchList END ;
    
caseBranchList : caseBranch ( ';' caseBranch )* ;
caseBranch : caseConstantList ':' statement | ;
caseConstantList : caseConstant ( ',' caseConstant )* ;

caseConstant locals [ Typespec *type = nullptr, int value = 0 ] : constant ;

forStatement : FOR variable ':=' expression ( TO | DOWNTO ) expression DO statement ;

argumentList : argument ( ',' argument )* ;
argument     : expression ;

writeStatement   : WRITE writeArguments ;
writelnStatement : WRITELN writeArguments? ;
writeArgument : expression (':' fieldWidth)? ;
writeArguments : '(' writeArgument (',' writeArgument)* ')' ;

fieldWidth : sign? integerConstant (':' decimalPlaces)? ;
decimalPlaces : integerConstant ;

readStatement : READ readArguments ;
readlnStatement : READLN readArguments ;
readArguments : '(' variable ( ',' variable )* ')' ;

term locals [ Typespec *type = nullptr ] : factor (mulOp factor)* ;
expression locals [ Typespec *type = nullptr ] : simpleExpression (relOp simpleExpression)? ;
simpleExpression locals [ Typespec *type = nullptr ] : sign? term (addOp term)* ;

factor locals [ Typespec *type = nullptr ] 
    : variable  # variableFactor
    | number    # numberFactor
    | characterConstant # characterFactor
    | stringConstant    # stringFactor
    | functionCall  # functionCallFactor
    | NOT factor    # notFactor
    | '(' expression ')' # parenthesizedFactor;   

modifier  : '[' indexList ']' | '.' field ;
indexList : index ( ',' index )* ;
index : expression ; 

field locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] : IDENTIFIER ;

integerConstant : INTEGER ;
realConstant    : REAL;
unsignedNumber  : integerConstant | realConstant ;
number : sign? unsignedNumber ;

characterConstant : CHARACTER ;
stringConstant : STRING ;
       
relOp : '=' | '<>' | '<' | '<=' | '>' | '>=' ;
addOp : '+' | '-' | OR ;
mulOp : '*' | '/' | DIV | MOD | AND ;

fragment A : ('a' | 'A') ;
fragment B : ('b' | 'B') ;
fragment C : ('c' | 'C') ;
fragment D : ('d' | 'D') ;
fragment E : ('e' | 'E') ;
fragment F : ('f' | 'F') ;
fragment G : ('g' | 'G') ;
fragment H : ('h' | 'H') ;
fragment I : ('i' | 'I') ;
fragment J : ('j' | 'J') ;
fragment K : ('k' | 'K') ;
fragment L : ('l' | 'L') ;
fragment M : ('m' | 'M') ;
fragment N : ('n' | 'N') ;
fragment O : ('o' | 'O') ;
fragment P : ('p' | 'P') ;
fragment Q : ('q' | 'Q') ;
fragment R : ('r' | 'R') ;
fragment S : ('s' | 'S') ;
fragment T : ('t' | 'T') ;
fragment U : ('u' | 'U') ;
fragment V : ('v' | 'V') ;
fragment W : ('w' | 'W') ;
fragment X : ('x' | 'X') ;
fragment Y : ('y' | 'Y') ;
fragment Z : ('z' | 'Z') ;

DO        : D O ;
FOR       : F O R ;
TO        : T O ;
DOWNTO    : D O W N T O ;
WRITE     : W R I T E ;
WRITELN   : W R I T E L N ;
READ      : R E A D ;
READLN    : R E A D L N ;
FUNCTION  : F U N C T I O N ;
PROGRAM   : P R O G R A M ;
CONST     : C O N S T ;
TYPE      : T Y P E ;
ARRAY     : A R R A Y ;
OF        : O F ;
VAR       : V A R ;
BEGIN     : B E G I N ;
END       : E N D ;
DIV       : D I V ;
MOD       : M O D ;
AND       : A N D ;
OR        : O R ;
NOT       : N O T ;
IF        : I F ;
THEN      : T H E N ;
ELSE      : E L S E ;
CASE      : C A S E ;
REPEAT    : R E P E A T ;
UNTIL     : U N T I L ;
WHILE     : W H I L E ;

NEWLINE : '\r'? '\n' -> skip  ;
WS      : [ \t]+ -> skip ; 

QUOTE     : '\'' ;
CHARACTER : QUOTE CHARACTER_CHAR QUOTE ;
STRING    : QUOTE STRING_CHAR* QUOTE ;

IDENTIFIER : [a-zA-Z][a-zA-Z0-9]* ;
INTEGER    : [0-9]+ ;

REAL : INTEGER '.' INTEGER
     | INTEGER ('e' | 'E') ('+' | '-')? INTEGER
     | INTEGER '.' INTEGER ('e' | 'E') ('+' | '-')? INTEGER;

fragment CHARACTER_CHAR : ~('\'');

fragment STRING_CHAR : QUOTE QUOTE | ~('\'');

COMMENT : '{' COMMENT_CHARACTER* '}' -> skip ;

fragment COMMENT_CHARACTER : ~('}') ;
                     