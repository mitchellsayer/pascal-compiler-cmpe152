
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from Pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  PascalParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, DO = 20, 
    FOR = 21, TO = 22, DOWNTO = 23, WRITE = 24, WRITELN = 25, READ = 26, 
    READLN = 27, FUNCTION = 28, PROGRAM = 29, CONST = 30, TYPE = 31, ARRAY = 32, 
    OF = 33, VAR = 34, BEGIN = 35, END = 36, DIV = 37, MOD = 38, AND = 39, 
    OR = 40, NOT = 41, IF = 42, THEN = 43, ELSE = 44, CASE = 45, REPEAT = 46, 
    UNTIL = 47, WHILE = 48, NEWLINE = 49, WS = 50, QUOTE = 51, CHARACTER = 52, 
    STRING = 53, IDENTIFIER = 54, INTEGER = 55, REAL = 56, COMMENT = 57
  };

  enum {
    RuleProgramParams = 0, RuleProgramHeader = 1, RuleProgram = 2, RuleProgramIdentifier = 3, 
    RuleDeclarations = 4, RuleBlock = 5, RuleSign = 6, RuleConstantIdentifier = 7, 
    RuleConstant = 8, RuleConstantDefinition = 9, RuleConstantDefinitionsList = 10, 
    RuleConstantsPart = 11, RuleTypeIdentifier = 12, RuleTypesPart = 13, 
    RuleTypeDefinitionsList = 14, RuleTypeDefinition = 15, RuleArrayType = 16, 
    RuleArrayDimensionList = 17, RuleTypeSpecification = 18, RuleSimpleType = 19, 
    RuleVariableIdentifier = 20, RuleVariable = 21, RuleVariablesPart = 22, 
    RuleVariableDeclarationsList = 23, RuleVariableDeclarations = 24, RuleVariableIdentifierList = 25, 
    RuleRoutinesPart = 26, RuleRoutineDefinition = 27, RuleFunctionHead = 28, 
    RuleFunctionName = 29, RuleFunctionCall = 30, RuleRoutineIdentifier = 31, 
    RuleParameterIdentifier = 32, RuleParameters = 33, RuleParameterDeclarationsList = 34, 
    RuleParameterDeclarations = 35, RuleParameterIdentifierList = 36, RuleStatement = 37, 
    RuleCompoundStatement = 38, RuleEmptyStatement = 39, RuleLhs = 40, RuleRhs = 41, 
    RuleStatementList = 42, RuleAssignmentStatement = 43, RuleRepeatStatement = 44, 
    RuleWhileStatement = 45, RuleIfStatement = 46, RuleTrueStatement = 47, 
    RuleFalseStatement = 48, RuleCaseStatement = 49, RuleCaseBranchList = 50, 
    RuleCaseBranch = 51, RuleCaseConstantList = 52, RuleCaseConstant = 53, 
    RuleForStatement = 54, RuleArgumentList = 55, RuleArgument = 56, RuleWriteStatement = 57, 
    RuleWritelnStatement = 58, RuleWriteArgument = 59, RuleWriteArguments = 60, 
    RuleFieldWidth = 61, RuleDecimalPlaces = 62, RuleReadStatement = 63, 
    RuleReadlnStatement = 64, RuleReadArguments = 65, RuleTerm = 66, RuleExpression = 67, 
    RuleSimpleExpression = 68, RuleFactor = 69, RuleModifier = 70, RuleIndexList = 71, 
    RuleIndex = 72, RuleField = 73, RuleIntegerConstant = 74, RuleRealConstant = 75, 
    RuleUnsignedNumber = 76, RuleNumber = 77, RuleCharacterConstant = 78, 
    RuleStringConstant = 79, RuleRelOp = 80, RuleAddOp = 81, RuleMulOp = 82
  };

  PascalParser(antlr4::TokenStream *input);
  ~PascalParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramParamsContext;
  class ProgramHeaderContext;
  class ProgramContext;
  class ProgramIdentifierContext;
  class DeclarationsContext;
  class BlockContext;
  class SignContext;
  class ConstantIdentifierContext;
  class ConstantContext;
  class ConstantDefinitionContext;
  class ConstantDefinitionsListContext;
  class ConstantsPartContext;
  class TypeIdentifierContext;
  class TypesPartContext;
  class TypeDefinitionsListContext;
  class TypeDefinitionContext;
  class ArrayTypeContext;
  class ArrayDimensionListContext;
  class TypeSpecificationContext;
  class SimpleTypeContext;
  class VariableIdentifierContext;
  class VariableContext;
  class VariablesPartContext;
  class VariableDeclarationsListContext;
  class VariableDeclarationsContext;
  class VariableIdentifierListContext;
  class RoutinesPartContext;
  class RoutineDefinitionContext;
  class FunctionHeadContext;
  class FunctionNameContext;
  class FunctionCallContext;
  class RoutineIdentifierContext;
  class ParameterIdentifierContext;
  class ParametersContext;
  class ParameterDeclarationsListContext;
  class ParameterDeclarationsContext;
  class ParameterIdentifierListContext;
  class StatementContext;
  class CompoundStatementContext;
  class EmptyStatementContext;
  class LhsContext;
  class RhsContext;
  class StatementListContext;
  class AssignmentStatementContext;
  class RepeatStatementContext;
  class WhileStatementContext;
  class IfStatementContext;
  class TrueStatementContext;
  class FalseStatementContext;
  class CaseStatementContext;
  class CaseBranchListContext;
  class CaseBranchContext;
  class CaseConstantListContext;
  class CaseConstantContext;
  class ForStatementContext;
  class ArgumentListContext;
  class ArgumentContext;
  class WriteStatementContext;
  class WritelnStatementContext;
  class WriteArgumentContext;
  class WriteArgumentsContext;
  class FieldWidthContext;
  class DecimalPlacesContext;
  class ReadStatementContext;
  class ReadlnStatementContext;
  class ReadArgumentsContext;
  class TermContext;
  class ExpressionContext;
  class SimpleExpressionContext;
  class FactorContext;
  class ModifierContext;
  class IndexListContext;
  class IndexContext;
  class FieldContext;
  class IntegerConstantContext;
  class RealConstantContext;
  class UnsignedNumberContext;
  class NumberContext;
  class CharacterConstantContext;
  class StringConstantContext;
  class RelOpContext;
  class AddOpContext;
  class MulOpContext; 

  class  ProgramParamsContext : public antlr4::ParserRuleContext {
  public:
    ProgramParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramParamsContext* programParams();

  class  ProgramHeaderContext : public antlr4::ParserRuleContext {
  public:
    ProgramHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGRAM();
    ProgramIdentifierContext *programIdentifier();
    ProgramParamsContext *programParams();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramHeaderContext* programHeader();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramHeaderContext *programHeader();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ProgramIdentifierContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * entry = nullptr;
    ProgramIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramIdentifierContext* programIdentifier();

  class  DeclarationsContext : public antlr4::ParserRuleContext {
  public:
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantsPartContext *constantsPart();
    TypesPartContext *typesPart();
    VariablesPartContext *variablesPart();
    RoutinesPartContext *routinesPart();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationsContext* declarations();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationsContext *declarations();
    CompoundStatementContext *compoundStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  SignContext : public antlr4::ParserRuleContext {
  public:
    SignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignContext* sign();

  class  ConstantIdentifierContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    ConstantIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantIdentifierContext* constantIdentifier();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    Object value = nullptr;
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    UnsignedNumberContext *unsignedNumber();
    SignContext *sign();
    CharacterConstantContext *characterConstant();
    StringConstantContext *stringConstant();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantContext* constant();

  class  ConstantDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ConstantDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantIdentifierContext *constantIdentifier();
    ConstantContext *constant();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantDefinitionContext* constantDefinition();

  class  ConstantDefinitionsListContext : public antlr4::ParserRuleContext {
  public:
    ConstantDefinitionsListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstantDefinitionContext *> constantDefinition();
    ConstantDefinitionContext* constantDefinition(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantDefinitionsListContext* constantDefinitionsList();

  class  ConstantsPartContext : public antlr4::ParserRuleContext {
  public:
    ConstantsPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    ConstantDefinitionsListContext *constantDefinitionsList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantsPartContext* constantsPart();

  class  TypeIdentifierContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    TypeIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeIdentifierContext* typeIdentifier();

  class  TypesPartContext : public antlr4::ParserRuleContext {
  public:
    TypesPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    TypeDefinitionsListContext *typeDefinitionsList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypesPartContext* typesPart();

  class  TypeDefinitionsListContext : public antlr4::ParserRuleContext {
  public:
    TypeDefinitionsListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeDefinitionContext *> typeDefinition();
    TypeDefinitionContext* typeDefinition(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDefinitionsListContext* typeDefinitionsList();

  class  TypeDefinitionContext : public antlr4::ParserRuleContext {
  public:
    TypeDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeIdentifierContext *typeIdentifier();
    TypeSpecificationContext *typeSpecification();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDefinitionContext* typeDefinition();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    ArrayDimensionListContext *arrayDimensionList();
    antlr4::tree::TerminalNode *OF();
    TypeSpecificationContext *typeSpecification();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();

  class  ArrayDimensionListContext : public antlr4::ParserRuleContext {
  public:
    ArrayDimensionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimpleTypeContext *> simpleType();
    SimpleTypeContext* simpleType(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayDimensionListContext* arrayDimensionList();

  class  TypeSpecificationContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    TypeSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeSpecificationContext() = default;
    void copyFrom(TypeSpecificationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimpleTypespecContext : public TypeSpecificationContext {
  public:
    SimpleTypespecContext(TypeSpecificationContext *ctx);

    SimpleTypeContext *simpleType();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayTypespecContext : public TypeSpecificationContext {
  public:
    ArrayTypespecContext(TypeSpecificationContext *ctx);

    ArrayTypeContext *arrayType();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeSpecificationContext* typeSpecification();

  class  SimpleTypeContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SimpleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SimpleTypeContext() = default;
    void copyFrom(SimpleTypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TypeIdentifierTypespecContext : public SimpleTypeContext {
  public:
    TypeIdentifierTypespecContext(SimpleTypeContext *ctx);

    TypeIdentifierContext *typeIdentifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SimpleTypeContext* simpleType();

  class  VariableIdentifierContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    VariableIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableIdentifierContext* variableIdentifier();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableIdentifierContext *variableIdentifier();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  VariablesPartContext : public antlr4::ParserRuleContext {
  public:
    VariablesPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    VariableDeclarationsListContext *variableDeclarationsList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariablesPartContext* variablesPart();

  class  VariableDeclarationsListContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationsListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableDeclarationsContext *> variableDeclarations();
    VariableDeclarationsContext* variableDeclarations(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationsListContext* variableDeclarationsList();

  class  VariableDeclarationsContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableIdentifierListContext *variableIdentifierList();
    TypeSpecificationContext *typeSpecification();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationsContext* variableDeclarations();

  class  VariableIdentifierListContext : public antlr4::ParserRuleContext {
  public:
    VariableIdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableIdentifierContext *> variableIdentifier();
    VariableIdentifierContext* variableIdentifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableIdentifierListContext* variableIdentifierList();

  class  RoutinesPartContext : public antlr4::ParserRuleContext {
  public:
    RoutinesPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RoutineDefinitionContext *> routineDefinition();
    RoutineDefinitionContext* routineDefinition(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RoutinesPartContext* routinesPart();

  class  RoutineDefinitionContext : public antlr4::ParserRuleContext {
  public:
    RoutineDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionHeadContext *functionHead();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RoutineDefinitionContext* routineDefinition();

  class  FunctionHeadContext : public antlr4::ParserRuleContext {
  public:
    FunctionHeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTION();
    RoutineIdentifierContext *routineIdentifier();
    TypeIdentifierContext *typeIdentifier();
    ParametersContext *parameters();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionHeadContext* functionHead();

  class  FunctionNameContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionNameContext* functionName();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionNameContext *functionName();
    ArgumentListContext *argumentList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallContext* functionCall();

  class  RoutineIdentifierContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    RoutineIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RoutineIdentifierContext* routineIdentifier();

  class  ParameterIdentifierContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    ParameterIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterIdentifierContext* parameterIdentifier();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterDeclarationsListContext *parameterDeclarationsList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  ParameterDeclarationsListContext : public antlr4::ParserRuleContext {
  public:
    ParameterDeclarationsListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterDeclarationsContext *> parameterDeclarations();
    ParameterDeclarationsContext* parameterDeclarations(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterDeclarationsListContext* parameterDeclarationsList();

  class  ParameterDeclarationsContext : public antlr4::ParserRuleContext {
  public:
    ParameterDeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterIdentifierListContext *parameterIdentifierList();
    TypeIdentifierContext *typeIdentifier();
    antlr4::tree::TerminalNode *VAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterDeclarationsContext* parameterDeclarations();

  class  ParameterIdentifierListContext : public antlr4::ParserRuleContext {
  public:
    ParameterIdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterIdentifierContext *> parameterIdentifier();
    ParameterIdentifierContext* parameterIdentifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterIdentifierListContext* parameterIdentifierList();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompoundStatementContext *compoundStatement();
    AssignmentStatementContext *assignmentStatement();
    IfStatementContext *ifStatement();
    CaseStatementContext *caseStatement();
    RepeatStatementContext *repeatStatement();
    WhileStatementContext *whileStatement();
    ForStatementContext *forStatement();
    WriteStatementContext *writeStatement();
    WritelnStatementContext *writelnStatement();
    ReadStatementContext *readStatement();
    ReadlnStatementContext *readlnStatement();
    EmptyStatementContext *emptyStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  CompoundStatementContext : public antlr4::ParserRuleContext {
  public:
    CompoundStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    StatementListContext *statementList();
    antlr4::tree::TerminalNode *END();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundStatementContext* compoundStatement();

  class  EmptyStatementContext : public antlr4::ParserRuleContext {
  public:
    EmptyStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptyStatementContext* emptyStatement();

  class  LhsContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    LhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LhsContext* lhs();

  class  RhsContext : public antlr4::ParserRuleContext {
  public:
    RhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RhsContext* rhs();

  class  StatementListContext : public antlr4::ParserRuleContext {
  public:
    StatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementListContext* statementList();

  class  AssignmentStatementContext : public antlr4::ParserRuleContext {
  public:
    AssignmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LhsContext *lhs();
    RhsContext *rhs();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentStatementContext* assignmentStatement();

  class  RepeatStatementContext : public antlr4::ParserRuleContext {
  public:
    RepeatStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REPEAT();
    StatementListContext *statementList();
    antlr4::tree::TerminalNode *UNTIL();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RepeatStatementContext* repeatStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *THEN();
    TrueStatementContext *trueStatement();
    antlr4::tree::TerminalNode *ELSE();
    FalseStatementContext *falseStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  TrueStatementContext : public antlr4::ParserRuleContext {
  public:
    TrueStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrueStatementContext* trueStatement();

  class  FalseStatementContext : public antlr4::ParserRuleContext {
  public:
    FalseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FalseStatementContext* falseStatement();

  class  CaseStatementContext : public antlr4::ParserRuleContext {
  public:
    map<int, PascalParser::StatementContext*> * jumpTable = nullptr;
    CaseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OF();
    CaseBranchListContext *caseBranchList();
    antlr4::tree::TerminalNode *END();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseStatementContext* caseStatement();

  class  CaseBranchListContext : public antlr4::ParserRuleContext {
  public:
    CaseBranchListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CaseBranchContext *> caseBranch();
    CaseBranchContext* caseBranch(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseBranchListContext* caseBranchList();

  class  CaseBranchContext : public antlr4::ParserRuleContext {
  public:
    CaseBranchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CaseConstantListContext *caseConstantList();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseBranchContext* caseBranch();

  class  CaseConstantListContext : public antlr4::ParserRuleContext {
  public:
    CaseConstantListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CaseConstantContext *> caseConstant();
    CaseConstantContext* caseConstant(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseConstantListContext* caseConstantList();

  class  CaseConstantContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    int value = 0;
    CaseConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantContext *constant();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseConstantContext* caseConstant();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    VariableContext *variable();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *DOWNTO();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  ArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentListContext* argumentList();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentContext* argument();

  class  WriteStatementContext : public antlr4::ParserRuleContext {
  public:
    WriteStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITE();
    WriteArgumentsContext *writeArguments();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteStatementContext* writeStatement();

  class  WritelnStatementContext : public antlr4::ParserRuleContext {
  public:
    WritelnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITELN();
    WriteArgumentsContext *writeArguments();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WritelnStatementContext* writelnStatement();

  class  WriteArgumentContext : public antlr4::ParserRuleContext {
  public:
    WriteArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    FieldWidthContext *fieldWidth();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteArgumentContext* writeArgument();

  class  WriteArgumentsContext : public antlr4::ParserRuleContext {
  public:
    WriteArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<WriteArgumentContext *> writeArgument();
    WriteArgumentContext* writeArgument(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteArgumentsContext* writeArguments();

  class  FieldWidthContext : public antlr4::ParserRuleContext {
  public:
    FieldWidthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerConstantContext *integerConstant();
    SignContext *sign();
    DecimalPlacesContext *decimalPlaces();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldWidthContext* fieldWidth();

  class  DecimalPlacesContext : public antlr4::ParserRuleContext {
  public:
    DecimalPlacesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerConstantContext *integerConstant();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecimalPlacesContext* decimalPlaces();

  class  ReadStatementContext : public antlr4::ParserRuleContext {
  public:
    ReadStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *READ();
    ReadArgumentsContext *readArguments();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadStatementContext* readStatement();

  class  ReadlnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReadlnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *READLN();
    ReadArgumentsContext *readArguments();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadlnStatementContext* readlnStatement();

  class  ReadArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ReadArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadArgumentsContext* readArguments();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<MulOpContext *> mulOp();
    MulOpContext* mulOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimpleExpressionContext *> simpleExpression();
    SimpleExpressionContext* simpleExpression(size_t i);
    RelOpContext *relOp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  SimpleExpressionContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SimpleExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    SignContext *sign();
    std::vector<AddOpContext *> addOp();
    AddOpContext* addOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleExpressionContext* simpleExpression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FactorContext() = default;
    void copyFrom(FactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberFactorContext : public FactorContext {
  public:
    NumberFactorContext(FactorContext *ctx);

    NumberContext *number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringFactorContext : public FactorContext {
  public:
    StringFactorContext(FactorContext *ctx);

    StringConstantContext *stringConstant();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharacterFactorContext : public FactorContext {
  public:
    CharacterFactorContext(FactorContext *ctx);

    CharacterConstantContext *characterConstant();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableFactorContext : public FactorContext {
  public:
    VariableFactorContext(FactorContext *ctx);

    VariableContext *variable();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallFactorContext : public FactorContext {
  public:
    FunctionCallFactorContext(FactorContext *ctx);

    FunctionCallContext *functionCall();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotFactorContext : public FactorContext {
  public:
    NotFactorContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedFactorContext : public FactorContext {
  public:
    ParenthesizedFactorContext(FactorContext *ctx);

    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FactorContext* factor();

  class  ModifierContext : public antlr4::ParserRuleContext {
  public:
    ModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexListContext *indexList();
    FieldContext *field();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierContext* modifier();

  class  IndexListContext : public antlr4::ParserRuleContext {
  public:
    IndexListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexListContext* indexList();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  FieldContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    FieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldContext* field();

  class  IntegerConstantContext : public antlr4::ParserRuleContext {
  public:
    IntegerConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntegerConstantContext* integerConstant();

  class  RealConstantContext : public antlr4::ParserRuleContext {
  public:
    RealConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REAL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RealConstantContext* realConstant();

  class  UnsignedNumberContext : public antlr4::ParserRuleContext {
  public:
    UnsignedNumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerConstantContext *integerConstant();
    RealConstantContext *realConstant();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedNumberContext* unsignedNumber();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedNumberContext *unsignedNumber();
    SignContext *sign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  CharacterConstantContext : public antlr4::ParserRuleContext {
  public:
    CharacterConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHARACTER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterConstantContext* characterConstant();

  class  StringConstantContext : public antlr4::ParserRuleContext {
  public:
    StringConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringConstantContext* stringConstant();

  class  RelOpContext : public antlr4::ParserRuleContext {
  public:
    RelOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelOpContext* relOp();

  class  AddOpContext : public antlr4::ParserRuleContext {
  public:
    AddOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddOpContext* addOp();

  class  MulOpContext : public antlr4::ParserRuleContext {
  public:
    MulOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *AND();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulOpContext* mulOp();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

