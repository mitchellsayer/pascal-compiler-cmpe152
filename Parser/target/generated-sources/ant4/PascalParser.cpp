
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from Pascal.g4 by ANTLR 4.7.2


#include "PascalVisitor.h"

#include "PascalParser.h"


using namespace antlrcpp;
using namespace antlr4;

PascalParser::PascalParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PascalParser::~PascalParser() {
  delete _interpreter;
}

std::string PascalParser::getGrammarFileName() const {
  return "Pascal.g4";
}

const std::vector<std::string>& PascalParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PascalParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramParamsContext ------------------------------------------------------------------

PascalParser::ProgramParamsContext::ProgramParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PascalParser::ProgramParamsContext::IDENTIFIER() {
  return getTokens(PascalParser::IDENTIFIER);
}

tree::TerminalNode* PascalParser::ProgramParamsContext::IDENTIFIER(size_t i) {
  return getToken(PascalParser::IDENTIFIER, i);
}


size_t PascalParser::ProgramParamsContext::getRuleIndex() const {
  return PascalParser::RuleProgramParams;
}


antlrcpp::Any PascalParser::ProgramParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgramParams(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramParamsContext* PascalParser::programParams() {
  ProgramParamsContext *_localctx = _tracker.createInstance<ProgramParamsContext>(_ctx, getState());
  enterRule(_localctx, 0, PascalParser::RuleProgramParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(PascalParser::T__0);
    setState(167);
    match(PascalParser::IDENTIFIER);
    setState(172);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(168);
      match(PascalParser::T__1);
      setState(169);
      match(PascalParser::IDENTIFIER);
      setState(174);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(175);
    match(PascalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeaderContext ------------------------------------------------------------------

PascalParser::ProgramHeaderContext::ProgramHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProgramHeaderContext::PROGRAM() {
  return getToken(PascalParser::PROGRAM, 0);
}

PascalParser::ProgramIdentifierContext* PascalParser::ProgramHeaderContext::programIdentifier() {
  return getRuleContext<PascalParser::ProgramIdentifierContext>(0);
}

PascalParser::ProgramParamsContext* PascalParser::ProgramHeaderContext::programParams() {
  return getRuleContext<PascalParser::ProgramParamsContext>(0);
}


size_t PascalParser::ProgramHeaderContext::getRuleIndex() const {
  return PascalParser::RuleProgramHeader;
}


antlrcpp::Any PascalParser::ProgramHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgramHeader(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramHeaderContext* PascalParser::programHeader() {
  ProgramHeaderContext *_localctx = _tracker.createInstance<ProgramHeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, PascalParser::RuleProgramHeader);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(PascalParser::PROGRAM);
    setState(178);
    programIdentifier();
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__0) {
      setState(179);
      programParams();
    }
    setState(182);
    match(PascalParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

PascalParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ProgramHeaderContext* PascalParser::ProgramContext::programHeader() {
  return getRuleContext<PascalParser::ProgramHeaderContext>(0);
}

PascalParser::BlockContext* PascalParser::ProgramContext::block() {
  return getRuleContext<PascalParser::BlockContext>(0);
}


size_t PascalParser::ProgramContext::getRuleIndex() const {
  return PascalParser::RuleProgram;
}


antlrcpp::Any PascalParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramContext* PascalParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 4, PascalParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    programHeader();
    setState(185);
    block();
    setState(186);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramIdentifierContext ------------------------------------------------------------------

PascalParser::ProgramIdentifierContext::ProgramIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProgramIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::ProgramIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleProgramIdentifier;
}


antlrcpp::Any PascalParser::ProgramIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgramIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramIdentifierContext* PascalParser::programIdentifier() {
  ProgramIdentifierContext *_localctx = _tracker.createInstance<ProgramIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 6, PascalParser::RuleProgramIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

PascalParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantsPartContext* PascalParser::DeclarationsContext::constantsPart() {
  return getRuleContext<PascalParser::ConstantsPartContext>(0);
}

PascalParser::TypesPartContext* PascalParser::DeclarationsContext::typesPart() {
  return getRuleContext<PascalParser::TypesPartContext>(0);
}

PascalParser::VariablesPartContext* PascalParser::DeclarationsContext::variablesPart() {
  return getRuleContext<PascalParser::VariablesPartContext>(0);
}

PascalParser::RoutinesPartContext* PascalParser::DeclarationsContext::routinesPart() {
  return getRuleContext<PascalParser::RoutinesPartContext>(0);
}


size_t PascalParser::DeclarationsContext::getRuleIndex() const {
  return PascalParser::RuleDeclarations;
}


antlrcpp::Any PascalParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::DeclarationsContext* PascalParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 8, PascalParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::CONST) {
      setState(190);
      constantsPart();
      setState(191);
      match(PascalParser::T__3);
    }
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::TYPE) {
      setState(195);
      typesPart();
      setState(196);
      match(PascalParser::T__3);
    }
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::VAR) {
      setState(200);
      variablesPart();
      setState(201);
      match(PascalParser::T__3);
    }
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::FUNCTION) {
      setState(205);
      routinesPart();
      setState(206);
      match(PascalParser::T__3);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PascalParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::DeclarationsContext* PascalParser::BlockContext::declarations() {
  return getRuleContext<PascalParser::DeclarationsContext>(0);
}

PascalParser::CompoundStatementContext* PascalParser::BlockContext::compoundStatement() {
  return getRuleContext<PascalParser::CompoundStatementContext>(0);
}


size_t PascalParser::BlockContext::getRuleIndex() const {
  return PascalParser::RuleBlock;
}


antlrcpp::Any PascalParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::BlockContext* PascalParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 10, PascalParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    declarations();
    setState(211);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

PascalParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::SignContext::getRuleIndex() const {
  return PascalParser::RuleSign;
}


antlrcpp::Any PascalParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SignContext* PascalParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 12, PascalParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    _la = _input->LA(1);
    if (!(_la == PascalParser::T__5

    || _la == PascalParser::T__6)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantIdentifierContext ------------------------------------------------------------------

PascalParser::ConstantIdentifierContext::ConstantIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::ConstantIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleConstantIdentifier;
}


antlrcpp::Any PascalParser::ConstantIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantIdentifierContext* PascalParser::constantIdentifier() {
  ConstantIdentifierContext *_localctx = _tracker.createInstance<ConstantIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 14, PascalParser::RuleConstantIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

PascalParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}

PascalParser::UnsignedNumberContext* PascalParser::ConstantContext::unsignedNumber() {
  return getRuleContext<PascalParser::UnsignedNumberContext>(0);
}

PascalParser::SignContext* PascalParser::ConstantContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}

PascalParser::CharacterConstantContext* PascalParser::ConstantContext::characterConstant() {
  return getRuleContext<PascalParser::CharacterConstantContext>(0);
}

PascalParser::StringConstantContext* PascalParser::ConstantContext::stringConstant() {
  return getRuleContext<PascalParser::StringConstantContext>(0);
}


size_t PascalParser::ConstantContext::getRuleIndex() const {
  return PascalParser::RuleConstant;
}


antlrcpp::Any PascalParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantContext* PascalParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 16, PascalParser::RuleConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::T__5:
      case PascalParser::T__6:
      case PascalParser::IDENTIFIER:
      case PascalParser::INTEGER:
      case PascalParser::REAL: {
        enterOuterAlt(_localctx, 1);
        setState(218);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PascalParser::T__5

        || _la == PascalParser::T__6) {
          setState(217);
          sign();
        }
        setState(222);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PascalParser::IDENTIFIER: {
            setState(220);
            match(PascalParser::IDENTIFIER);
            break;
          }

          case PascalParser::INTEGER:
          case PascalParser::REAL: {
            setState(221);
            unsignedNumber();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case PascalParser::CHARACTER: {
        enterOuterAlt(_localctx, 2);
        setState(224);
        characterConstant();
        break;
      }

      case PascalParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(225);
        stringConstant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionContext ------------------------------------------------------------------

PascalParser::ConstantDefinitionContext::ConstantDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantIdentifierContext* PascalParser::ConstantDefinitionContext::constantIdentifier() {
  return getRuleContext<PascalParser::ConstantIdentifierContext>(0);
}

PascalParser::ConstantContext* PascalParser::ConstantDefinitionContext::constant() {
  return getRuleContext<PascalParser::ConstantContext>(0);
}


size_t PascalParser::ConstantDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleConstantDefinition;
}


antlrcpp::Any PascalParser::ConstantDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantDefinitionContext* PascalParser::constantDefinition() {
  ConstantDefinitionContext *_localctx = _tracker.createInstance<ConstantDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 18, PascalParser::RuleConstantDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    constantIdentifier();
    setState(229);
    match(PascalParser::T__7);
    setState(230);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionsListContext ------------------------------------------------------------------

PascalParser::ConstantDefinitionsListContext::ConstantDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ConstantDefinitionContext *> PascalParser::ConstantDefinitionsListContext::constantDefinition() {
  return getRuleContexts<PascalParser::ConstantDefinitionContext>();
}

PascalParser::ConstantDefinitionContext* PascalParser::ConstantDefinitionsListContext::constantDefinition(size_t i) {
  return getRuleContext<PascalParser::ConstantDefinitionContext>(i);
}


size_t PascalParser::ConstantDefinitionsListContext::getRuleIndex() const {
  return PascalParser::RuleConstantDefinitionsList;
}


antlrcpp::Any PascalParser::ConstantDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantDefinitionsListContext* PascalParser::constantDefinitionsList() {
  ConstantDefinitionsListContext *_localctx = _tracker.createInstance<ConstantDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 20, PascalParser::RuleConstantDefinitionsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(232);
    constantDefinition();
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(233);
        match(PascalParser::T__3);
        setState(234);
        constantDefinition(); 
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantsPartContext ------------------------------------------------------------------

PascalParser::ConstantsPartContext::ConstantsPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantsPartContext::CONST() {
  return getToken(PascalParser::CONST, 0);
}

PascalParser::ConstantDefinitionsListContext* PascalParser::ConstantsPartContext::constantDefinitionsList() {
  return getRuleContext<PascalParser::ConstantDefinitionsListContext>(0);
}


size_t PascalParser::ConstantsPartContext::getRuleIndex() const {
  return PascalParser::RuleConstantsPart;
}


antlrcpp::Any PascalParser::ConstantsPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantsPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantsPartContext* PascalParser::constantsPart() {
  ConstantsPartContext *_localctx = _tracker.createInstance<ConstantsPartContext>(_ctx, getState());
  enterRule(_localctx, 22, PascalParser::RuleConstantsPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    match(PascalParser::CONST);
    setState(241);
    constantDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdentifierContext ------------------------------------------------------------------

PascalParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::TypeIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::TypeIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleTypeIdentifier;
}


antlrcpp::Any PascalParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeIdentifierContext* PascalParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 24, PascalParser::RuleTypeIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypesPartContext ------------------------------------------------------------------

PascalParser::TypesPartContext::TypesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::TypesPartContext::TYPE() {
  return getToken(PascalParser::TYPE, 0);
}

PascalParser::TypeDefinitionsListContext* PascalParser::TypesPartContext::typeDefinitionsList() {
  return getRuleContext<PascalParser::TypeDefinitionsListContext>(0);
}


size_t PascalParser::TypesPartContext::getRuleIndex() const {
  return PascalParser::RuleTypesPart;
}


antlrcpp::Any PascalParser::TypesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypesPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypesPartContext* PascalParser::typesPart() {
  TypesPartContext *_localctx = _tracker.createInstance<TypesPartContext>(_ctx, getState());
  enterRule(_localctx, 26, PascalParser::RuleTypesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(PascalParser::TYPE);
    setState(246);
    typeDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionsListContext ------------------------------------------------------------------

PascalParser::TypeDefinitionsListContext::TypeDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::TypeDefinitionContext *> PascalParser::TypeDefinitionsListContext::typeDefinition() {
  return getRuleContexts<PascalParser::TypeDefinitionContext>();
}

PascalParser::TypeDefinitionContext* PascalParser::TypeDefinitionsListContext::typeDefinition(size_t i) {
  return getRuleContext<PascalParser::TypeDefinitionContext>(i);
}


size_t PascalParser::TypeDefinitionsListContext::getRuleIndex() const {
  return PascalParser::RuleTypeDefinitionsList;
}


antlrcpp::Any PascalParser::TypeDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeDefinitionsListContext* PascalParser::typeDefinitionsList() {
  TypeDefinitionsListContext *_localctx = _tracker.createInstance<TypeDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 28, PascalParser::RuleTypeDefinitionsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(248);
    typeDefinition();
    setState(253);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(249);
        match(PascalParser::T__3);
        setState(250);
        typeDefinition(); 
      }
      setState(255);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionContext ------------------------------------------------------------------

PascalParser::TypeDefinitionContext::TypeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::TypeIdentifierContext* PascalParser::TypeDefinitionContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::TypeSpecificationContext* PascalParser::TypeDefinitionContext::typeSpecification() {
  return getRuleContext<PascalParser::TypeSpecificationContext>(0);
}


size_t PascalParser::TypeDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleTypeDefinition;
}


antlrcpp::Any PascalParser::TypeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeDefinitionContext* PascalParser::typeDefinition() {
  TypeDefinitionContext *_localctx = _tracker.createInstance<TypeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 30, PascalParser::RuleTypeDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    typeIdentifier();
    setState(257);
    match(PascalParser::T__7);
    setState(258);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

PascalParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ArrayTypeContext::ARRAY() {
  return getToken(PascalParser::ARRAY, 0);
}

PascalParser::ArrayDimensionListContext* PascalParser::ArrayTypeContext::arrayDimensionList() {
  return getRuleContext<PascalParser::ArrayDimensionListContext>(0);
}

tree::TerminalNode* PascalParser::ArrayTypeContext::OF() {
  return getToken(PascalParser::OF, 0);
}

PascalParser::TypeSpecificationContext* PascalParser::ArrayTypeContext::typeSpecification() {
  return getRuleContext<PascalParser::TypeSpecificationContext>(0);
}


size_t PascalParser::ArrayTypeContext::getRuleIndex() const {
  return PascalParser::RuleArrayType;
}


antlrcpp::Any PascalParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArrayTypeContext* PascalParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 32, PascalParser::RuleArrayType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(PascalParser::ARRAY);
    setState(261);
    match(PascalParser::T__8);
    setState(262);
    arrayDimensionList();
    setState(263);
    match(PascalParser::T__9);
    setState(264);
    match(PascalParser::OF);
    setState(265);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDimensionListContext ------------------------------------------------------------------

PascalParser::ArrayDimensionListContext::ArrayDimensionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::SimpleTypeContext *> PascalParser::ArrayDimensionListContext::simpleType() {
  return getRuleContexts<PascalParser::SimpleTypeContext>();
}

PascalParser::SimpleTypeContext* PascalParser::ArrayDimensionListContext::simpleType(size_t i) {
  return getRuleContext<PascalParser::SimpleTypeContext>(i);
}


size_t PascalParser::ArrayDimensionListContext::getRuleIndex() const {
  return PascalParser::RuleArrayDimensionList;
}


antlrcpp::Any PascalParser::ArrayDimensionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArrayDimensionList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArrayDimensionListContext* PascalParser::arrayDimensionList() {
  ArrayDimensionListContext *_localctx = _tracker.createInstance<ArrayDimensionListContext>(_ctx, getState());
  enterRule(_localctx, 34, PascalParser::RuleArrayDimensionList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    simpleType();
    setState(272);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(268);
      match(PascalParser::T__1);
      setState(269);
      simpleType();
      setState(274);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecificationContext ------------------------------------------------------------------

PascalParser::TypeSpecificationContext::TypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::TypeSpecificationContext::getRuleIndex() const {
  return PascalParser::RuleTypeSpecification;
}

void PascalParser::TypeSpecificationContext::copyFrom(TypeSpecificationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- SimpleTypespecContext ------------------------------------------------------------------

PascalParser::SimpleTypeContext* PascalParser::SimpleTypespecContext::simpleType() {
  return getRuleContext<PascalParser::SimpleTypeContext>(0);
}

PascalParser::SimpleTypespecContext::SimpleTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::SimpleTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSimpleTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayTypespecContext ------------------------------------------------------------------

PascalParser::ArrayTypeContext* PascalParser::ArrayTypespecContext::arrayType() {
  return getRuleContext<PascalParser::ArrayTypeContext>(0);
}

PascalParser::ArrayTypespecContext::ArrayTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::ArrayTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArrayTypespec(this);
  else
    return visitor->visitChildren(this);
}
PascalParser::TypeSpecificationContext* PascalParser::typeSpecification() {
  TypeSpecificationContext *_localctx = _tracker.createInstance<TypeSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 36, PascalParser::RuleTypeSpecification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENTIFIER: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<PascalParser::SimpleTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(275);
        simpleType();
        break;
      }

      case PascalParser::ARRAY: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<PascalParser::ArrayTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(276);
        arrayType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleTypeContext ------------------------------------------------------------------

PascalParser::SimpleTypeContext::SimpleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::SimpleTypeContext::getRuleIndex() const {
  return PascalParser::RuleSimpleType;
}

void PascalParser::SimpleTypeContext::copyFrom(SimpleTypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- TypeIdentifierTypespecContext ------------------------------------------------------------------

PascalParser::TypeIdentifierContext* PascalParser::TypeIdentifierTypespecContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::TypeIdentifierTypespecContext::TypeIdentifierTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::TypeIdentifierTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifierTypespec(this);
  else
    return visitor->visitChildren(this);
}
PascalParser::SimpleTypeContext* PascalParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 38, PascalParser::RuleSimpleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<PascalParser::TypeIdentifierTypespecContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(279);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierContext ------------------------------------------------------------------

PascalParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::VariableIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::VariableIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleVariableIdentifier;
}


antlrcpp::Any PascalParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableIdentifierContext* PascalParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 40, PascalParser::RuleVariableIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

PascalParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableIdentifierContext* PascalParser::VariableContext::variableIdentifier() {
  return getRuleContext<PascalParser::VariableIdentifierContext>(0);
}

std::vector<PascalParser::ModifierContext *> PascalParser::VariableContext::modifier() {
  return getRuleContexts<PascalParser::ModifierContext>();
}

PascalParser::ModifierContext* PascalParser::VariableContext::modifier(size_t i) {
  return getRuleContext<PascalParser::ModifierContext>(i);
}


size_t PascalParser::VariableContext::getRuleIndex() const {
  return PascalParser::RuleVariable;
}


antlrcpp::Any PascalParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableContext* PascalParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 42, PascalParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    variableIdentifier();
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__4

    || _la == PascalParser::T__8) {
      setState(284);
      modifier();
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesPartContext ------------------------------------------------------------------

PascalParser::VariablesPartContext::VariablesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::VariablesPartContext::VAR() {
  return getToken(PascalParser::VAR, 0);
}

PascalParser::VariableDeclarationsListContext* PascalParser::VariablesPartContext::variableDeclarationsList() {
  return getRuleContext<PascalParser::VariableDeclarationsListContext>(0);
}


size_t PascalParser::VariablesPartContext::getRuleIndex() const {
  return PascalParser::RuleVariablesPart;
}


antlrcpp::Any PascalParser::VariablesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariablesPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariablesPartContext* PascalParser::variablesPart() {
  VariablesPartContext *_localctx = _tracker.createInstance<VariablesPartContext>(_ctx, getState());
  enterRule(_localctx, 44, PascalParser::RuleVariablesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    match(PascalParser::VAR);
    setState(291);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsListContext ------------------------------------------------------------------

PascalParser::VariableDeclarationsListContext::VariableDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::VariableDeclarationsContext *> PascalParser::VariableDeclarationsListContext::variableDeclarations() {
  return getRuleContexts<PascalParser::VariableDeclarationsContext>();
}

PascalParser::VariableDeclarationsContext* PascalParser::VariableDeclarationsListContext::variableDeclarations(size_t i) {
  return getRuleContext<PascalParser::VariableDeclarationsContext>(i);
}


size_t PascalParser::VariableDeclarationsListContext::getRuleIndex() const {
  return PascalParser::RuleVariableDeclarationsList;
}


antlrcpp::Any PascalParser::VariableDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableDeclarationsListContext* PascalParser::variableDeclarationsList() {
  VariableDeclarationsListContext *_localctx = _tracker.createInstance<VariableDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 46, PascalParser::RuleVariableDeclarationsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(293);
    variableDeclarations();
    setState(298);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(294);
        match(PascalParser::T__3);
        setState(295);
        variableDeclarations(); 
      }
      setState(300);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsContext ------------------------------------------------------------------

PascalParser::VariableDeclarationsContext::VariableDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableIdentifierListContext* PascalParser::VariableDeclarationsContext::variableIdentifierList() {
  return getRuleContext<PascalParser::VariableIdentifierListContext>(0);
}

PascalParser::TypeSpecificationContext* PascalParser::VariableDeclarationsContext::typeSpecification() {
  return getRuleContext<PascalParser::TypeSpecificationContext>(0);
}


size_t PascalParser::VariableDeclarationsContext::getRuleIndex() const {
  return PascalParser::RuleVariableDeclarations;
}


antlrcpp::Any PascalParser::VariableDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableDeclarationsContext* PascalParser::variableDeclarations() {
  VariableDeclarationsContext *_localctx = _tracker.createInstance<VariableDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 48, PascalParser::RuleVariableDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    variableIdentifierList();
    setState(302);
    match(PascalParser::T__10);
    setState(303);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierListContext ------------------------------------------------------------------

PascalParser::VariableIdentifierListContext::VariableIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::VariableIdentifierContext *> PascalParser::VariableIdentifierListContext::variableIdentifier() {
  return getRuleContexts<PascalParser::VariableIdentifierContext>();
}

PascalParser::VariableIdentifierContext* PascalParser::VariableIdentifierListContext::variableIdentifier(size_t i) {
  return getRuleContext<PascalParser::VariableIdentifierContext>(i);
}


size_t PascalParser::VariableIdentifierListContext::getRuleIndex() const {
  return PascalParser::RuleVariableIdentifierList;
}


antlrcpp::Any PascalParser::VariableIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableIdentifierListContext* PascalParser::variableIdentifierList() {
  VariableIdentifierListContext *_localctx = _tracker.createInstance<VariableIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 50, PascalParser::RuleVariableIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    variableIdentifier();
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(306);
      match(PascalParser::T__1);
      setState(307);
      variableIdentifier();
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutinesPartContext ------------------------------------------------------------------

PascalParser::RoutinesPartContext::RoutinesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::RoutineDefinitionContext *> PascalParser::RoutinesPartContext::routineDefinition() {
  return getRuleContexts<PascalParser::RoutineDefinitionContext>();
}

PascalParser::RoutineDefinitionContext* PascalParser::RoutinesPartContext::routineDefinition(size_t i) {
  return getRuleContext<PascalParser::RoutineDefinitionContext>(i);
}


size_t PascalParser::RoutinesPartContext::getRuleIndex() const {
  return PascalParser::RuleRoutinesPart;
}


antlrcpp::Any PascalParser::RoutinesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRoutinesPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RoutinesPartContext* PascalParser::routinesPart() {
  RoutinesPartContext *_localctx = _tracker.createInstance<RoutinesPartContext>(_ctx, getState());
  enterRule(_localctx, 52, PascalParser::RuleRoutinesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(313);
    routineDefinition();
    setState(318);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(314);
        match(PascalParser::T__3);
        setState(315);
        routineDefinition(); 
      }
      setState(320);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineDefinitionContext ------------------------------------------------------------------

PascalParser::RoutineDefinitionContext::RoutineDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::FunctionHeadContext* PascalParser::RoutineDefinitionContext::functionHead() {
  return getRuleContext<PascalParser::FunctionHeadContext>(0);
}

PascalParser::BlockContext* PascalParser::RoutineDefinitionContext::block() {
  return getRuleContext<PascalParser::BlockContext>(0);
}


size_t PascalParser::RoutineDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleRoutineDefinition;
}


antlrcpp::Any PascalParser::RoutineDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRoutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RoutineDefinitionContext* PascalParser::routineDefinition() {
  RoutineDefinitionContext *_localctx = _tracker.createInstance<RoutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 54, PascalParser::RuleRoutineDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    functionHead();
    setState(322);
    match(PascalParser::T__3);
    setState(323);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionHeadContext ------------------------------------------------------------------

PascalParser::FunctionHeadContext::FunctionHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FunctionHeadContext::FUNCTION() {
  return getToken(PascalParser::FUNCTION, 0);
}

PascalParser::RoutineIdentifierContext* PascalParser::FunctionHeadContext::routineIdentifier() {
  return getRuleContext<PascalParser::RoutineIdentifierContext>(0);
}

PascalParser::TypeIdentifierContext* PascalParser::FunctionHeadContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::ParametersContext* PascalParser::FunctionHeadContext::parameters() {
  return getRuleContext<PascalParser::ParametersContext>(0);
}


size_t PascalParser::FunctionHeadContext::getRuleIndex() const {
  return PascalParser::RuleFunctionHead;
}


antlrcpp::Any PascalParser::FunctionHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionHead(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionHeadContext* PascalParser::functionHead() {
  FunctionHeadContext *_localctx = _tracker.createInstance<FunctionHeadContext>(_ctx, getState());
  enterRule(_localctx, 56, PascalParser::RuleFunctionHead);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    match(PascalParser::FUNCTION);
    setState(326);
    routineIdentifier();
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__0) {
      setState(327);
      parameters();
    }
    setState(330);
    match(PascalParser::T__10);
    setState(331);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

PascalParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FunctionNameContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::FunctionNameContext::getRuleIndex() const {
  return PascalParser::RuleFunctionName;
}


antlrcpp::Any PascalParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionNameContext* PascalParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 58, PascalParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

PascalParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::FunctionNameContext* PascalParser::FunctionCallContext::functionName() {
  return getRuleContext<PascalParser::FunctionNameContext>(0);
}

PascalParser::ArgumentListContext* PascalParser::FunctionCallContext::argumentList() {
  return getRuleContext<PascalParser::ArgumentListContext>(0);
}


size_t PascalParser::FunctionCallContext::getRuleIndex() const {
  return PascalParser::RuleFunctionCall;
}


antlrcpp::Any PascalParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionCallContext* PascalParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 60, PascalParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    functionName();
    setState(336);
    match(PascalParser::T__0);
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__0)
      | (1ULL << PascalParser::T__5)
      | (1ULL << PascalParser::T__6)
      | (1ULL << PascalParser::NOT)
      | (1ULL << PascalParser::CHARACTER)
      | (1ULL << PascalParser::STRING)
      | (1ULL << PascalParser::IDENTIFIER)
      | (1ULL << PascalParser::INTEGER)
      | (1ULL << PascalParser::REAL))) != 0)) {
      setState(337);
      argumentList();
    }
    setState(340);
    match(PascalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineIdentifierContext ------------------------------------------------------------------

PascalParser::RoutineIdentifierContext::RoutineIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RoutineIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::RoutineIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleRoutineIdentifier;
}


antlrcpp::Any PascalParser::RoutineIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRoutineIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RoutineIdentifierContext* PascalParser::routineIdentifier() {
  RoutineIdentifierContext *_localctx = _tracker.createInstance<RoutineIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 62, PascalParser::RuleRoutineIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierContext ------------------------------------------------------------------

PascalParser::ParameterIdentifierContext::ParameterIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ParameterIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::ParameterIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleParameterIdentifier;
}


antlrcpp::Any PascalParser::ParameterIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterIdentifierContext* PascalParser::parameterIdentifier() {
  ParameterIdentifierContext *_localctx = _tracker.createInstance<ParameterIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 64, PascalParser::RuleParameterIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

PascalParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ParameterDeclarationsListContext* PascalParser::ParametersContext::parameterDeclarationsList() {
  return getRuleContext<PascalParser::ParameterDeclarationsListContext>(0);
}


size_t PascalParser::ParametersContext::getRuleIndex() const {
  return PascalParser::RuleParameters;
}


antlrcpp::Any PascalParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParametersContext* PascalParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 66, PascalParser::RuleParameters);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    match(PascalParser::T__0);
    setState(347);
    parameterDeclarationsList();
    setState(348);
    match(PascalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsListContext ------------------------------------------------------------------

PascalParser::ParameterDeclarationsListContext::ParameterDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ParameterDeclarationsContext *> PascalParser::ParameterDeclarationsListContext::parameterDeclarations() {
  return getRuleContexts<PascalParser::ParameterDeclarationsContext>();
}

PascalParser::ParameterDeclarationsContext* PascalParser::ParameterDeclarationsListContext::parameterDeclarations(size_t i) {
  return getRuleContext<PascalParser::ParameterDeclarationsContext>(i);
}


size_t PascalParser::ParameterDeclarationsListContext::getRuleIndex() const {
  return PascalParser::RuleParameterDeclarationsList;
}


antlrcpp::Any PascalParser::ParameterDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterDeclarationsListContext* PascalParser::parameterDeclarationsList() {
  ParameterDeclarationsListContext *_localctx = _tracker.createInstance<ParameterDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 68, PascalParser::RuleParameterDeclarationsList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    parameterDeclarations();
    setState(355);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(351);
      match(PascalParser::T__3);
      setState(352);
      parameterDeclarations();
      setState(357);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsContext ------------------------------------------------------------------

PascalParser::ParameterDeclarationsContext::ParameterDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ParameterIdentifierListContext* PascalParser::ParameterDeclarationsContext::parameterIdentifierList() {
  return getRuleContext<PascalParser::ParameterIdentifierListContext>(0);
}

PascalParser::TypeIdentifierContext* PascalParser::ParameterDeclarationsContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ParameterDeclarationsContext::VAR() {
  return getToken(PascalParser::VAR, 0);
}


size_t PascalParser::ParameterDeclarationsContext::getRuleIndex() const {
  return PascalParser::RuleParameterDeclarations;
}


antlrcpp::Any PascalParser::ParameterDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterDeclarationsContext* PascalParser::parameterDeclarations() {
  ParameterDeclarationsContext *_localctx = _tracker.createInstance<ParameterDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 70, PascalParser::RuleParameterDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::VAR) {
      setState(358);
      match(PascalParser::VAR);
    }
    setState(361);
    parameterIdentifierList();
    setState(362);
    match(PascalParser::T__10);
    setState(363);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierListContext ------------------------------------------------------------------

PascalParser::ParameterIdentifierListContext::ParameterIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ParameterIdentifierContext *> PascalParser::ParameterIdentifierListContext::parameterIdentifier() {
  return getRuleContexts<PascalParser::ParameterIdentifierContext>();
}

PascalParser::ParameterIdentifierContext* PascalParser::ParameterIdentifierListContext::parameterIdentifier(size_t i) {
  return getRuleContext<PascalParser::ParameterIdentifierContext>(i);
}


size_t PascalParser::ParameterIdentifierListContext::getRuleIndex() const {
  return PascalParser::RuleParameterIdentifierList;
}


antlrcpp::Any PascalParser::ParameterIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterIdentifierListContext* PascalParser::parameterIdentifierList() {
  ParameterIdentifierListContext *_localctx = _tracker.createInstance<ParameterIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 72, PascalParser::RuleParameterIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    parameterIdentifier();
    setState(370);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(366);
      match(PascalParser::T__1);
      setState(367);
      parameterIdentifier();
      setState(372);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PascalParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::CompoundStatementContext* PascalParser::StatementContext::compoundStatement() {
  return getRuleContext<PascalParser::CompoundStatementContext>(0);
}

PascalParser::AssignmentStatementContext* PascalParser::StatementContext::assignmentStatement() {
  return getRuleContext<PascalParser::AssignmentStatementContext>(0);
}

PascalParser::IfStatementContext* PascalParser::StatementContext::ifStatement() {
  return getRuleContext<PascalParser::IfStatementContext>(0);
}

PascalParser::CaseStatementContext* PascalParser::StatementContext::caseStatement() {
  return getRuleContext<PascalParser::CaseStatementContext>(0);
}

PascalParser::RepeatStatementContext* PascalParser::StatementContext::repeatStatement() {
  return getRuleContext<PascalParser::RepeatStatementContext>(0);
}

PascalParser::WhileStatementContext* PascalParser::StatementContext::whileStatement() {
  return getRuleContext<PascalParser::WhileStatementContext>(0);
}

PascalParser::ForStatementContext* PascalParser::StatementContext::forStatement() {
  return getRuleContext<PascalParser::ForStatementContext>(0);
}

PascalParser::WriteStatementContext* PascalParser::StatementContext::writeStatement() {
  return getRuleContext<PascalParser::WriteStatementContext>(0);
}

PascalParser::WritelnStatementContext* PascalParser::StatementContext::writelnStatement() {
  return getRuleContext<PascalParser::WritelnStatementContext>(0);
}

PascalParser::ReadStatementContext* PascalParser::StatementContext::readStatement() {
  return getRuleContext<PascalParser::ReadStatementContext>(0);
}

PascalParser::ReadlnStatementContext* PascalParser::StatementContext::readlnStatement() {
  return getRuleContext<PascalParser::ReadlnStatementContext>(0);
}

PascalParser::EmptyStatementContext* PascalParser::StatementContext::emptyStatement() {
  return getRuleContext<PascalParser::EmptyStatementContext>(0);
}


size_t PascalParser::StatementContext::getRuleIndex() const {
  return PascalParser::RuleStatement;
}


antlrcpp::Any PascalParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StatementContext* PascalParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 74, PascalParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(385);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::BEGIN: {
        enterOuterAlt(_localctx, 1);
        setState(373);
        compoundStatement();
        break;
      }

      case PascalParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(374);
        assignmentStatement();
        break;
      }

      case PascalParser::IF: {
        enterOuterAlt(_localctx, 3);
        setState(375);
        ifStatement();
        break;
      }

      case PascalParser::CASE: {
        enterOuterAlt(_localctx, 4);
        setState(376);
        caseStatement();
        break;
      }

      case PascalParser::REPEAT: {
        enterOuterAlt(_localctx, 5);
        setState(377);
        repeatStatement();
        break;
      }

      case PascalParser::WHILE: {
        enterOuterAlt(_localctx, 6);
        setState(378);
        whileStatement();
        break;
      }

      case PascalParser::FOR: {
        enterOuterAlt(_localctx, 7);
        setState(379);
        forStatement();
        break;
      }

      case PascalParser::WRITE: {
        enterOuterAlt(_localctx, 8);
        setState(380);
        writeStatement();
        break;
      }

      case PascalParser::WRITELN: {
        enterOuterAlt(_localctx, 9);
        setState(381);
        writelnStatement();
        break;
      }

      case PascalParser::READ: {
        enterOuterAlt(_localctx, 10);
        setState(382);
        readStatement();
        break;
      }

      case PascalParser::READLN: {
        enterOuterAlt(_localctx, 11);
        setState(383);
        readlnStatement();
        break;
      }

      case PascalParser::T__3:
      case PascalParser::END:
      case PascalParser::ELSE:
      case PascalParser::UNTIL: {
        enterOuterAlt(_localctx, 12);
        setState(384);
        emptyStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

PascalParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CompoundStatementContext::BEGIN() {
  return getToken(PascalParser::BEGIN, 0);
}

PascalParser::StatementListContext* PascalParser::CompoundStatementContext::statementList() {
  return getRuleContext<PascalParser::StatementListContext>(0);
}

tree::TerminalNode* PascalParser::CompoundStatementContext::END() {
  return getToken(PascalParser::END, 0);
}


size_t PascalParser::CompoundStatementContext::getRuleIndex() const {
  return PascalParser::RuleCompoundStatement;
}


antlrcpp::Any PascalParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CompoundStatementContext* PascalParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 76, PascalParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    match(PascalParser::BEGIN);
    setState(388);
    statementList();
    setState(389);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

PascalParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::EmptyStatementContext::getRuleIndex() const {
  return PascalParser::RuleEmptyStatement;
}


antlrcpp::Any PascalParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::EmptyStatementContext* PascalParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 78, PascalParser::RuleEmptyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

PascalParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableContext* PascalParser::LhsContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}


size_t PascalParser::LhsContext::getRuleIndex() const {
  return PascalParser::RuleLhs;
}


antlrcpp::Any PascalParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::LhsContext* PascalParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 80, PascalParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

PascalParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::RhsContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::RhsContext::getRuleIndex() const {
  return PascalParser::RuleRhs;
}


antlrcpp::Any PascalParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RhsContext* PascalParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 82, PascalParser::RuleRhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

PascalParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::StatementContext *> PascalParser::StatementListContext::statement() {
  return getRuleContexts<PascalParser::StatementContext>();
}

PascalParser::StatementContext* PascalParser::StatementListContext::statement(size_t i) {
  return getRuleContext<PascalParser::StatementContext>(i);
}


size_t PascalParser::StatementListContext::getRuleIndex() const {
  return PascalParser::RuleStatementList;
}


antlrcpp::Any PascalParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StatementListContext* PascalParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 84, PascalParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    statement();
    setState(402);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(398);
      match(PascalParser::T__3);
      setState(399);
      statement();
      setState(404);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

PascalParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::LhsContext* PascalParser::AssignmentStatementContext::lhs() {
  return getRuleContext<PascalParser::LhsContext>(0);
}

PascalParser::RhsContext* PascalParser::AssignmentStatementContext::rhs() {
  return getRuleContext<PascalParser::RhsContext>(0);
}


size_t PascalParser::AssignmentStatementContext::getRuleIndex() const {
  return PascalParser::RuleAssignmentStatement;
}


antlrcpp::Any PascalParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::AssignmentStatementContext* PascalParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 86, PascalParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    lhs();
    setState(406);
    match(PascalParser::T__11);
    setState(407);
    rhs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RepeatStatementContext ------------------------------------------------------------------

PascalParser::RepeatStatementContext::RepeatStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RepeatStatementContext::REPEAT() {
  return getToken(PascalParser::REPEAT, 0);
}

PascalParser::StatementListContext* PascalParser::RepeatStatementContext::statementList() {
  return getRuleContext<PascalParser::StatementListContext>(0);
}

tree::TerminalNode* PascalParser::RepeatStatementContext::UNTIL() {
  return getToken(PascalParser::UNTIL, 0);
}

PascalParser::ExpressionContext* PascalParser::RepeatStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::RepeatStatementContext::getRuleIndex() const {
  return PascalParser::RuleRepeatStatement;
}


antlrcpp::Any PascalParser::RepeatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRepeatStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RepeatStatementContext* PascalParser::repeatStatement() {
  RepeatStatementContext *_localctx = _tracker.createInstance<RepeatStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, PascalParser::RuleRepeatStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(PascalParser::REPEAT);
    setState(410);
    statementList();
    setState(411);
    match(PascalParser::UNTIL);
    setState(412);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

PascalParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WhileStatementContext::WHILE() {
  return getToken(PascalParser::WHILE, 0);
}

PascalParser::ExpressionContext* PascalParser::WhileStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::WhileStatementContext::DO() {
  return getToken(PascalParser::DO, 0);
}

PascalParser::StatementContext* PascalParser::WhileStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::WhileStatementContext::getRuleIndex() const {
  return PascalParser::RuleWhileStatement;
}


antlrcpp::Any PascalParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WhileStatementContext* PascalParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 90, PascalParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    match(PascalParser::WHILE);
    setState(415);
    expression();
    setState(416);
    match(PascalParser::DO);
    setState(417);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

PascalParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::IfStatementContext::IF() {
  return getToken(PascalParser::IF, 0);
}

PascalParser::ExpressionContext* PascalParser::IfStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::IfStatementContext::THEN() {
  return getToken(PascalParser::THEN, 0);
}

PascalParser::TrueStatementContext* PascalParser::IfStatementContext::trueStatement() {
  return getRuleContext<PascalParser::TrueStatementContext>(0);
}

tree::TerminalNode* PascalParser::IfStatementContext::ELSE() {
  return getToken(PascalParser::ELSE, 0);
}

PascalParser::FalseStatementContext* PascalParser::IfStatementContext::falseStatement() {
  return getRuleContext<PascalParser::FalseStatementContext>(0);
}


size_t PascalParser::IfStatementContext::getRuleIndex() const {
  return PascalParser::RuleIfStatement;
}


antlrcpp::Any PascalParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IfStatementContext* PascalParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 92, PascalParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(419);
    match(PascalParser::IF);
    setState(420);
    expression();
    setState(421);
    match(PascalParser::THEN);
    setState(422);
    trueStatement();
    setState(425);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(423);
      match(PascalParser::ELSE);
      setState(424);
      falseStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TrueStatementContext ------------------------------------------------------------------

PascalParser::TrueStatementContext::TrueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::StatementContext* PascalParser::TrueStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::TrueStatementContext::getRuleIndex() const {
  return PascalParser::RuleTrueStatement;
}


antlrcpp::Any PascalParser::TrueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTrueStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TrueStatementContext* PascalParser::trueStatement() {
  TrueStatementContext *_localctx = _tracker.createInstance<TrueStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, PascalParser::RuleTrueStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FalseStatementContext ------------------------------------------------------------------

PascalParser::FalseStatementContext::FalseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::StatementContext* PascalParser::FalseStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::FalseStatementContext::getRuleIndex() const {
  return PascalParser::RuleFalseStatement;
}


antlrcpp::Any PascalParser::FalseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFalseStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FalseStatementContext* PascalParser::falseStatement() {
  FalseStatementContext *_localctx = _tracker.createInstance<FalseStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, PascalParser::RuleFalseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

PascalParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CaseStatementContext::CASE() {
  return getToken(PascalParser::CASE, 0);
}

PascalParser::ExpressionContext* PascalParser::CaseStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::CaseStatementContext::OF() {
  return getToken(PascalParser::OF, 0);
}

PascalParser::CaseBranchListContext* PascalParser::CaseStatementContext::caseBranchList() {
  return getRuleContext<PascalParser::CaseBranchListContext>(0);
}

tree::TerminalNode* PascalParser::CaseStatementContext::END() {
  return getToken(PascalParser::END, 0);
}


size_t PascalParser::CaseStatementContext::getRuleIndex() const {
  return PascalParser::RuleCaseStatement;
}


antlrcpp::Any PascalParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseStatementContext* PascalParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, PascalParser::RuleCaseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    match(PascalParser::CASE);
    setState(432);
    expression();
    setState(433);
    match(PascalParser::OF);
    setState(434);
    caseBranchList();
    setState(435);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBranchListContext ------------------------------------------------------------------

PascalParser::CaseBranchListContext::CaseBranchListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::CaseBranchContext *> PascalParser::CaseBranchListContext::caseBranch() {
  return getRuleContexts<PascalParser::CaseBranchContext>();
}

PascalParser::CaseBranchContext* PascalParser::CaseBranchListContext::caseBranch(size_t i) {
  return getRuleContext<PascalParser::CaseBranchContext>(i);
}


size_t PascalParser::CaseBranchListContext::getRuleIndex() const {
  return PascalParser::RuleCaseBranchList;
}


antlrcpp::Any PascalParser::CaseBranchListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranchList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseBranchListContext* PascalParser::caseBranchList() {
  CaseBranchListContext *_localctx = _tracker.createInstance<CaseBranchListContext>(_ctx, getState());
  enterRule(_localctx, 100, PascalParser::RuleCaseBranchList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    caseBranch();
    setState(442);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(438);
      match(PascalParser::T__3);
      setState(439);
      caseBranch();
      setState(444);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBranchContext ------------------------------------------------------------------

PascalParser::CaseBranchContext::CaseBranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::CaseConstantListContext* PascalParser::CaseBranchContext::caseConstantList() {
  return getRuleContext<PascalParser::CaseConstantListContext>(0);
}

PascalParser::StatementContext* PascalParser::CaseBranchContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::CaseBranchContext::getRuleIndex() const {
  return PascalParser::RuleCaseBranch;
}


antlrcpp::Any PascalParser::CaseBranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranch(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseBranchContext* PascalParser::caseBranch() {
  CaseBranchContext *_localctx = _tracker.createInstance<CaseBranchContext>(_ctx, getState());
  enterRule(_localctx, 102, PascalParser::RuleCaseBranch);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(450);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::T__5:
      case PascalParser::T__6:
      case PascalParser::CHARACTER:
      case PascalParser::STRING:
      case PascalParser::IDENTIFIER:
      case PascalParser::INTEGER:
      case PascalParser::REAL: {
        enterOuterAlt(_localctx, 1);
        setState(445);
        caseConstantList();
        setState(446);
        match(PascalParser::T__10);
        setState(447);
        statement();
        break;
      }

      case PascalParser::T__3:
      case PascalParser::END: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseConstantListContext ------------------------------------------------------------------

PascalParser::CaseConstantListContext::CaseConstantListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::CaseConstantContext *> PascalParser::CaseConstantListContext::caseConstant() {
  return getRuleContexts<PascalParser::CaseConstantContext>();
}

PascalParser::CaseConstantContext* PascalParser::CaseConstantListContext::caseConstant(size_t i) {
  return getRuleContext<PascalParser::CaseConstantContext>(i);
}


size_t PascalParser::CaseConstantListContext::getRuleIndex() const {
  return PascalParser::RuleCaseConstantList;
}


antlrcpp::Any PascalParser::CaseConstantListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstantList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseConstantListContext* PascalParser::caseConstantList() {
  CaseConstantListContext *_localctx = _tracker.createInstance<CaseConstantListContext>(_ctx, getState());
  enterRule(_localctx, 104, PascalParser::RuleCaseConstantList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    caseConstant();
    setState(457);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(453);
      match(PascalParser::T__1);
      setState(454);
      caseConstant();
      setState(459);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseConstantContext ------------------------------------------------------------------

PascalParser::CaseConstantContext::CaseConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantContext* PascalParser::CaseConstantContext::constant() {
  return getRuleContext<PascalParser::ConstantContext>(0);
}


size_t PascalParser::CaseConstantContext::getRuleIndex() const {
  return PascalParser::RuleCaseConstant;
}


antlrcpp::Any PascalParser::CaseConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseConstantContext* PascalParser::caseConstant() {
  CaseConstantContext *_localctx = _tracker.createInstance<CaseConstantContext>(_ctx, getState());
  enterRule(_localctx, 106, PascalParser::RuleCaseConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

PascalParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ForStatementContext::FOR() {
  return getToken(PascalParser::FOR, 0);
}

PascalParser::VariableContext* PascalParser::ForStatementContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}

std::vector<PascalParser::ExpressionContext *> PascalParser::ForStatementContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
}

tree::TerminalNode* PascalParser::ForStatementContext::DO() {
  return getToken(PascalParser::DO, 0);
}

PascalParser::StatementContext* PascalParser::ForStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}

tree::TerminalNode* PascalParser::ForStatementContext::TO() {
  return getToken(PascalParser::TO, 0);
}

tree::TerminalNode* PascalParser::ForStatementContext::DOWNTO() {
  return getToken(PascalParser::DOWNTO, 0);
}


size_t PascalParser::ForStatementContext::getRuleIndex() const {
  return PascalParser::RuleForStatement;
}


antlrcpp::Any PascalParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ForStatementContext* PascalParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 108, PascalParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    match(PascalParser::FOR);
    setState(463);
    variable();
    setState(464);
    match(PascalParser::T__11);
    setState(465);
    expression();
    setState(466);
    _la = _input->LA(1);
    if (!(_la == PascalParser::TO

    || _la == PascalParser::DOWNTO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(467);
    expression();
    setState(468);
    match(PascalParser::DO);
    setState(469);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

PascalParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ArgumentContext *> PascalParser::ArgumentListContext::argument() {
  return getRuleContexts<PascalParser::ArgumentContext>();
}

PascalParser::ArgumentContext* PascalParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<PascalParser::ArgumentContext>(i);
}


size_t PascalParser::ArgumentListContext::getRuleIndex() const {
  return PascalParser::RuleArgumentList;
}


antlrcpp::Any PascalParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArgumentListContext* PascalParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 110, PascalParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(471);
    argument();
    setState(476);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(472);
      match(PascalParser::T__1);
      setState(473);
      argument();
      setState(478);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

PascalParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::ArgumentContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::ArgumentContext::getRuleIndex() const {
  return PascalParser::RuleArgument;
}


antlrcpp::Any PascalParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArgumentContext* PascalParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 112, PascalParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteStatementContext ------------------------------------------------------------------

PascalParser::WriteStatementContext::WriteStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WriteStatementContext::WRITE() {
  return getToken(PascalParser::WRITE, 0);
}

PascalParser::WriteArgumentsContext* PascalParser::WriteStatementContext::writeArguments() {
  return getRuleContext<PascalParser::WriteArgumentsContext>(0);
}


size_t PascalParser::WriteStatementContext::getRuleIndex() const {
  return PascalParser::RuleWriteStatement;
}


antlrcpp::Any PascalParser::WriteStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteStatementContext* PascalParser::writeStatement() {
  WriteStatementContext *_localctx = _tracker.createInstance<WriteStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, PascalParser::RuleWriteStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(481);
    match(PascalParser::WRITE);
    setState(482);
    writeArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WritelnStatementContext ------------------------------------------------------------------

PascalParser::WritelnStatementContext::WritelnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WritelnStatementContext::WRITELN() {
  return getToken(PascalParser::WRITELN, 0);
}

PascalParser::WriteArgumentsContext* PascalParser::WritelnStatementContext::writeArguments() {
  return getRuleContext<PascalParser::WriteArgumentsContext>(0);
}


size_t PascalParser::WritelnStatementContext::getRuleIndex() const {
  return PascalParser::RuleWritelnStatement;
}


antlrcpp::Any PascalParser::WritelnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWritelnStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WritelnStatementContext* PascalParser::writelnStatement() {
  WritelnStatementContext *_localctx = _tracker.createInstance<WritelnStatementContext>(_ctx, getState());
  enterRule(_localctx, 116, PascalParser::RuleWritelnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(PascalParser::WRITELN);
    setState(486);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__0) {
      setState(485);
      writeArguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgumentContext ------------------------------------------------------------------

PascalParser::WriteArgumentContext::WriteArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::WriteArgumentContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

PascalParser::FieldWidthContext* PascalParser::WriteArgumentContext::fieldWidth() {
  return getRuleContext<PascalParser::FieldWidthContext>(0);
}


size_t PascalParser::WriteArgumentContext::getRuleIndex() const {
  return PascalParser::RuleWriteArgument;
}


antlrcpp::Any PascalParser::WriteArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteArgument(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteArgumentContext* PascalParser::writeArgument() {
  WriteArgumentContext *_localctx = _tracker.createInstance<WriteArgumentContext>(_ctx, getState());
  enterRule(_localctx, 118, PascalParser::RuleWriteArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    expression();
    setState(491);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__10) {
      setState(489);
      match(PascalParser::T__10);
      setState(490);
      fieldWidth();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgumentsContext ------------------------------------------------------------------

PascalParser::WriteArgumentsContext::WriteArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::WriteArgumentContext *> PascalParser::WriteArgumentsContext::writeArgument() {
  return getRuleContexts<PascalParser::WriteArgumentContext>();
}

PascalParser::WriteArgumentContext* PascalParser::WriteArgumentsContext::writeArgument(size_t i) {
  return getRuleContext<PascalParser::WriteArgumentContext>(i);
}


size_t PascalParser::WriteArgumentsContext::getRuleIndex() const {
  return PascalParser::RuleWriteArguments;
}


antlrcpp::Any PascalParser::WriteArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteArguments(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteArgumentsContext* PascalParser::writeArguments() {
  WriteArgumentsContext *_localctx = _tracker.createInstance<WriteArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 120, PascalParser::RuleWriteArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    match(PascalParser::T__0);
    setState(494);
    writeArgument();
    setState(499);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(495);
      match(PascalParser::T__1);
      setState(496);
      writeArgument();
      setState(501);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(502);
    match(PascalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldWidthContext ------------------------------------------------------------------

PascalParser::FieldWidthContext::FieldWidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IntegerConstantContext* PascalParser::FieldWidthContext::integerConstant() {
  return getRuleContext<PascalParser::IntegerConstantContext>(0);
}

PascalParser::SignContext* PascalParser::FieldWidthContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}

PascalParser::DecimalPlacesContext* PascalParser::FieldWidthContext::decimalPlaces() {
  return getRuleContext<PascalParser::DecimalPlacesContext>(0);
}


size_t PascalParser::FieldWidthContext::getRuleIndex() const {
  return PascalParser::RuleFieldWidth;
}


antlrcpp::Any PascalParser::FieldWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFieldWidth(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FieldWidthContext* PascalParser::fieldWidth() {
  FieldWidthContext *_localctx = _tracker.createInstance<FieldWidthContext>(_ctx, getState());
  enterRule(_localctx, 122, PascalParser::RuleFieldWidth);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__5

    || _la == PascalParser::T__6) {
      setState(504);
      sign();
    }
    setState(507);
    integerConstant();
    setState(510);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__10) {
      setState(508);
      match(PascalParser::T__10);
      setState(509);
      decimalPlaces();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalPlacesContext ------------------------------------------------------------------

PascalParser::DecimalPlacesContext::DecimalPlacesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IntegerConstantContext* PascalParser::DecimalPlacesContext::integerConstant() {
  return getRuleContext<PascalParser::IntegerConstantContext>(0);
}


size_t PascalParser::DecimalPlacesContext::getRuleIndex() const {
  return PascalParser::RuleDecimalPlaces;
}


antlrcpp::Any PascalParser::DecimalPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitDecimalPlaces(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::DecimalPlacesContext* PascalParser::decimalPlaces() {
  DecimalPlacesContext *_localctx = _tracker.createInstance<DecimalPlacesContext>(_ctx, getState());
  enterRule(_localctx, 124, PascalParser::RuleDecimalPlaces);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    integerConstant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadStatementContext ------------------------------------------------------------------

PascalParser::ReadStatementContext::ReadStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ReadStatementContext::READ() {
  return getToken(PascalParser::READ, 0);
}

PascalParser::ReadArgumentsContext* PascalParser::ReadStatementContext::readArguments() {
  return getRuleContext<PascalParser::ReadArgumentsContext>(0);
}


size_t PascalParser::ReadStatementContext::getRuleIndex() const {
  return PascalParser::RuleReadStatement;
}


antlrcpp::Any PascalParser::ReadStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitReadStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ReadStatementContext* PascalParser::readStatement() {
  ReadStatementContext *_localctx = _tracker.createInstance<ReadStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, PascalParser::RuleReadStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(514);
    match(PascalParser::READ);
    setState(515);
    readArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadlnStatementContext ------------------------------------------------------------------

PascalParser::ReadlnStatementContext::ReadlnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ReadlnStatementContext::READLN() {
  return getToken(PascalParser::READLN, 0);
}

PascalParser::ReadArgumentsContext* PascalParser::ReadlnStatementContext::readArguments() {
  return getRuleContext<PascalParser::ReadArgumentsContext>(0);
}


size_t PascalParser::ReadlnStatementContext::getRuleIndex() const {
  return PascalParser::RuleReadlnStatement;
}


antlrcpp::Any PascalParser::ReadlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitReadlnStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ReadlnStatementContext* PascalParser::readlnStatement() {
  ReadlnStatementContext *_localctx = _tracker.createInstance<ReadlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 128, PascalParser::RuleReadlnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    match(PascalParser::READLN);
    setState(518);
    readArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadArgumentsContext ------------------------------------------------------------------

PascalParser::ReadArgumentsContext::ReadArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::VariableContext *> PascalParser::ReadArgumentsContext::variable() {
  return getRuleContexts<PascalParser::VariableContext>();
}

PascalParser::VariableContext* PascalParser::ReadArgumentsContext::variable(size_t i) {
  return getRuleContext<PascalParser::VariableContext>(i);
}


size_t PascalParser::ReadArgumentsContext::getRuleIndex() const {
  return PascalParser::RuleReadArguments;
}


antlrcpp::Any PascalParser::ReadArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitReadArguments(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ReadArgumentsContext* PascalParser::readArguments() {
  ReadArgumentsContext *_localctx = _tracker.createInstance<ReadArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 130, PascalParser::RuleReadArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    match(PascalParser::T__0);
    setState(521);
    variable();
    setState(526);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(522);
      match(PascalParser::T__1);
      setState(523);
      variable();
      setState(528);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(529);
    match(PascalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

PascalParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::FactorContext *> PascalParser::TermContext::factor() {
  return getRuleContexts<PascalParser::FactorContext>();
}

PascalParser::FactorContext* PascalParser::TermContext::factor(size_t i) {
  return getRuleContext<PascalParser::FactorContext>(i);
}

std::vector<PascalParser::MulOpContext *> PascalParser::TermContext::mulOp() {
  return getRuleContexts<PascalParser::MulOpContext>();
}

PascalParser::MulOpContext* PascalParser::TermContext::mulOp(size_t i) {
  return getRuleContext<PascalParser::MulOpContext>(i);
}


size_t PascalParser::TermContext::getRuleIndex() const {
  return PascalParser::RuleTerm;
}


antlrcpp::Any PascalParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TermContext* PascalParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 132, PascalParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(531);
    factor();
    setState(537);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__17)
      | (1ULL << PascalParser::T__18)
      | (1ULL << PascalParser::DIV)
      | (1ULL << PascalParser::MOD)
      | (1ULL << PascalParser::AND))) != 0)) {
      setState(532);
      mulOp();
      setState(533);
      factor();
      setState(539);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PascalParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::SimpleExpressionContext *> PascalParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<PascalParser::SimpleExpressionContext>();
}

PascalParser::SimpleExpressionContext* PascalParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<PascalParser::SimpleExpressionContext>(i);
}

PascalParser::RelOpContext* PascalParser::ExpressionContext::relOp() {
  return getRuleContext<PascalParser::RelOpContext>(0);
}


size_t PascalParser::ExpressionContext::getRuleIndex() const {
  return PascalParser::RuleExpression;
}


antlrcpp::Any PascalParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ExpressionContext* PascalParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 134, PascalParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(540);
    simpleExpression();
    setState(544);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__7)
      | (1ULL << PascalParser::T__12)
      | (1ULL << PascalParser::T__13)
      | (1ULL << PascalParser::T__14)
      | (1ULL << PascalParser::T__15)
      | (1ULL << PascalParser::T__16))) != 0)) {
      setState(541);
      relOp();
      setState(542);
      simpleExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

PascalParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::TermContext *> PascalParser::SimpleExpressionContext::term() {
  return getRuleContexts<PascalParser::TermContext>();
}

PascalParser::TermContext* PascalParser::SimpleExpressionContext::term(size_t i) {
  return getRuleContext<PascalParser::TermContext>(i);
}

PascalParser::SignContext* PascalParser::SimpleExpressionContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}

std::vector<PascalParser::AddOpContext *> PascalParser::SimpleExpressionContext::addOp() {
  return getRuleContexts<PascalParser::AddOpContext>();
}

PascalParser::AddOpContext* PascalParser::SimpleExpressionContext::addOp(size_t i) {
  return getRuleContext<PascalParser::AddOpContext>(i);
}


size_t PascalParser::SimpleExpressionContext::getRuleIndex() const {
  return PascalParser::RuleSimpleExpression;
}


antlrcpp::Any PascalParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SimpleExpressionContext* PascalParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 136, PascalParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(546);
      sign();
      break;
    }

    }
    setState(549);
    term();
    setState(555);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__5)
      | (1ULL << PascalParser::T__6)
      | (1ULL << PascalParser::OR))) != 0)) {
      setState(550);
      addOp();
      setState(551);
      term();
      setState(557);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

PascalParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::FactorContext::getRuleIndex() const {
  return PascalParser::RuleFactor;
}

void PascalParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- NumberFactorContext ------------------------------------------------------------------

PascalParser::NumberContext* PascalParser::NumberFactorContext::number() {
  return getRuleContext<PascalParser::NumberContext>(0);
}

PascalParser::NumberFactorContext::NumberFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitNumberFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringFactorContext ------------------------------------------------------------------

PascalParser::StringConstantContext* PascalParser::StringFactorContext::stringConstant() {
  return getRuleContext<PascalParser::StringConstantContext>(0);
}

PascalParser::StringFactorContext::StringFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStringFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharacterFactorContext ------------------------------------------------------------------

PascalParser::CharacterConstantContext* PascalParser::CharacterFactorContext::characterConstant() {
  return getRuleContext<PascalParser::CharacterConstantContext>(0);
}

PascalParser::CharacterFactorContext::CharacterFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCharacterFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

PascalParser::VariableContext* PascalParser::VariableFactorContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}

PascalParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallFactorContext ------------------------------------------------------------------

PascalParser::FunctionCallContext* PascalParser::FunctionCallFactorContext::functionCall() {
  return getRuleContext<PascalParser::FunctionCallContext>(0);
}

PascalParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFactorContext ------------------------------------------------------------------

tree::TerminalNode* PascalParser::NotFactorContext::NOT() {
  return getToken(PascalParser::NOT, 0);
}

PascalParser::FactorContext* PascalParser::NotFactorContext::factor() {
  return getRuleContext<PascalParser::FactorContext>(0);
}

PascalParser::NotFactorContext::NotFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitNotFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

PascalParser::ExpressionContext* PascalParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

PascalParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
PascalParser::FactorContext* PascalParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 138, PascalParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(569);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::VariableFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(558);
      variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::NumberFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(559);
      number();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::CharacterFactorContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(560);
      characterConstant();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::StringFactorContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(561);
      stringConstant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::FunctionCallFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(562);
      functionCall();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::NotFactorContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(563);
      match(PascalParser::NOT);
      setState(564);
      factor();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::ParenthesizedFactorContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(565);
      match(PascalParser::T__0);
      setState(566);
      expression();
      setState(567);
      match(PascalParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

PascalParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IndexListContext* PascalParser::ModifierContext::indexList() {
  return getRuleContext<PascalParser::IndexListContext>(0);
}

PascalParser::FieldContext* PascalParser::ModifierContext::field() {
  return getRuleContext<PascalParser::FieldContext>(0);
}


size_t PascalParser::ModifierContext::getRuleIndex() const {
  return PascalParser::RuleModifier;
}


antlrcpp::Any PascalParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ModifierContext* PascalParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 140, PascalParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(577);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(571);
        match(PascalParser::T__8);
        setState(572);
        indexList();
        setState(573);
        match(PascalParser::T__9);
        break;
      }

      case PascalParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(575);
        match(PascalParser::T__4);
        setState(576);
        field();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexListContext ------------------------------------------------------------------

PascalParser::IndexListContext::IndexListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::IndexContext *> PascalParser::IndexListContext::index() {
  return getRuleContexts<PascalParser::IndexContext>();
}

PascalParser::IndexContext* PascalParser::IndexListContext::index(size_t i) {
  return getRuleContext<PascalParser::IndexContext>(i);
}


size_t PascalParser::IndexListContext::getRuleIndex() const {
  return PascalParser::RuleIndexList;
}


antlrcpp::Any PascalParser::IndexListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIndexList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IndexListContext* PascalParser::indexList() {
  IndexListContext *_localctx = _tracker.createInstance<IndexListContext>(_ctx, getState());
  enterRule(_localctx, 142, PascalParser::RuleIndexList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    index();
    setState(584);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(580);
      match(PascalParser::T__1);
      setState(581);
      index();
      setState(586);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

PascalParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::IndexContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::IndexContext::getRuleIndex() const {
  return PascalParser::RuleIndex;
}


antlrcpp::Any PascalParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IndexContext* PascalParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 144, PascalParser::RuleIndex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(587);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

PascalParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FieldContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::FieldContext::getRuleIndex() const {
  return PascalParser::RuleField;
}


antlrcpp::Any PascalParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FieldContext* PascalParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 146, PascalParser::RuleField);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerConstantContext ------------------------------------------------------------------

PascalParser::IntegerConstantContext::IntegerConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::IntegerConstantContext::INTEGER() {
  return getToken(PascalParser::INTEGER, 0);
}


size_t PascalParser::IntegerConstantContext::getRuleIndex() const {
  return PascalParser::RuleIntegerConstant;
}


antlrcpp::Any PascalParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IntegerConstantContext* PascalParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 148, PascalParser::RuleIntegerConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(591);
    match(PascalParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealConstantContext ------------------------------------------------------------------

PascalParser::RealConstantContext::RealConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RealConstantContext::REAL() {
  return getToken(PascalParser::REAL, 0);
}


size_t PascalParser::RealConstantContext::getRuleIndex() const {
  return PascalParser::RuleRealConstant;
}


antlrcpp::Any PascalParser::RealConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRealConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RealConstantContext* PascalParser::realConstant() {
  RealConstantContext *_localctx = _tracker.createInstance<RealConstantContext>(_ctx, getState());
  enterRule(_localctx, 150, PascalParser::RuleRealConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    match(PascalParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

PascalParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IntegerConstantContext* PascalParser::UnsignedNumberContext::integerConstant() {
  return getRuleContext<PascalParser::IntegerConstantContext>(0);
}

PascalParser::RealConstantContext* PascalParser::UnsignedNumberContext::realConstant() {
  return getRuleContext<PascalParser::RealConstantContext>(0);
}


size_t PascalParser::UnsignedNumberContext::getRuleIndex() const {
  return PascalParser::RuleUnsignedNumber;
}


antlrcpp::Any PascalParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnsignedNumberContext* PascalParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 152, PascalParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(597);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(595);
        integerConstant();
        break;
      }

      case PascalParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(596);
        realConstant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

PascalParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::UnsignedNumberContext* PascalParser::NumberContext::unsignedNumber() {
  return getRuleContext<PascalParser::UnsignedNumberContext>(0);
}

PascalParser::SignContext* PascalParser::NumberContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}


size_t PascalParser::NumberContext::getRuleIndex() const {
  return PascalParser::RuleNumber;
}


antlrcpp::Any PascalParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::NumberContext* PascalParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 154, PascalParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(600);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__5

    || _la == PascalParser::T__6) {
      setState(599);
      sign();
    }
    setState(602);
    unsignedNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharacterConstantContext ------------------------------------------------------------------

PascalParser::CharacterConstantContext::CharacterConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CharacterConstantContext::CHARACTER() {
  return getToken(PascalParser::CHARACTER, 0);
}


size_t PascalParser::CharacterConstantContext::getRuleIndex() const {
  return PascalParser::RuleCharacterConstant;
}


antlrcpp::Any PascalParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CharacterConstantContext* PascalParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 156, PascalParser::RuleCharacterConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    match(PascalParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

PascalParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::StringConstantContext::STRING() {
  return getToken(PascalParser::STRING, 0);
}


size_t PascalParser::StringConstantContext::getRuleIndex() const {
  return PascalParser::RuleStringConstant;
}


antlrcpp::Any PascalParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StringConstantContext* PascalParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 158, PascalParser::RuleStringConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(606);
    match(PascalParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

PascalParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::RelOpContext::getRuleIndex() const {
  return PascalParser::RuleRelOp;
}


antlrcpp::Any PascalParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RelOpContext* PascalParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 160, PascalParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(608);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__7)
      | (1ULL << PascalParser::T__12)
      | (1ULL << PascalParser::T__13)
      | (1ULL << PascalParser::T__14)
      | (1ULL << PascalParser::T__15)
      | (1ULL << PascalParser::T__16))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

PascalParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::AddOpContext::OR() {
  return getToken(PascalParser::OR, 0);
}


size_t PascalParser::AddOpContext::getRuleIndex() const {
  return PascalParser::RuleAddOp;
}


antlrcpp::Any PascalParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::AddOpContext* PascalParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 162, PascalParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__5)
      | (1ULL << PascalParser::T__6)
      | (1ULL << PascalParser::OR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

PascalParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::MulOpContext::DIV() {
  return getToken(PascalParser::DIV, 0);
}

tree::TerminalNode* PascalParser::MulOpContext::MOD() {
  return getToken(PascalParser::MOD, 0);
}

tree::TerminalNode* PascalParser::MulOpContext::AND() {
  return getToken(PascalParser::AND, 0);
}


size_t PascalParser::MulOpContext::getRuleIndex() const {
  return PascalParser::RuleMulOp;
}


antlrcpp::Any PascalParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::MulOpContext* PascalParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 164, PascalParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__17)
      | (1ULL << PascalParser::T__18)
      | (1ULL << PascalParser::DIV)
      | (1ULL << PascalParser::MOD)
      | (1ULL << PascalParser::AND))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> PascalParser::_decisionToDFA;
atn::PredictionContextCache PascalParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PascalParser::_atn;
std::vector<uint16_t> PascalParser::_serializedATN;

std::vector<std::string> PascalParser::_ruleNames = {
  "programParams", "programHeader", "program", "programIdentifier", "declarations", 
  "block", "sign", "constantIdentifier", "constant", "constantDefinition", 
  "constantDefinitionsList", "constantsPart", "typeIdentifier", "typesPart", 
  "typeDefinitionsList", "typeDefinition", "arrayType", "arrayDimensionList", 
  "typeSpecification", "simpleType", "variableIdentifier", "variable", "variablesPart", 
  "variableDeclarationsList", "variableDeclarations", "variableIdentifierList", 
  "routinesPart", "routineDefinition", "functionHead", "functionName", "functionCall", 
  "routineIdentifier", "parameterIdentifier", "parameters", "parameterDeclarationsList", 
  "parameterDeclarations", "parameterIdentifierList", "statement", "compoundStatement", 
  "emptyStatement", "lhs", "rhs", "statementList", "assignmentStatement", 
  "repeatStatement", "whileStatement", "ifStatement", "trueStatement", "falseStatement", 
  "caseStatement", "caseBranchList", "caseBranch", "caseConstantList", "caseConstant", 
  "forStatement", "argumentList", "argument", "writeStatement", "writelnStatement", 
  "writeArgument", "writeArguments", "fieldWidth", "decimalPlaces", "readStatement", 
  "readlnStatement", "readArguments", "term", "expression", "simpleExpression", 
  "factor", "modifier", "indexList", "index", "field", "integerConstant", 
  "realConstant", "unsignedNumber", "number", "characterConstant", "stringConstant", 
  "relOp", "addOp", "mulOp"
};

std::vector<std::string> PascalParser::_literalNames = {
  "", "'('", "','", "')'", "';'", "'.'", "'-'", "'+'", "'='", "'['", "']'", 
  "':'", "':='", "'<>'", "'<'", "'<='", "'>'", "'>='", "'*'", "'/'", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "'''"
};

std::vector<std::string> PascalParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "DO", "FOR", "TO", "DOWNTO", "WRITE", "WRITELN", "READ", "READLN", 
  "FUNCTION", "PROGRAM", "CONST", "TYPE", "ARRAY", "OF", "VAR", "BEGIN", 
  "END", "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", "ELSE", "CASE", 
  "REPEAT", "UNTIL", "WHILE", "NEWLINE", "WS", "QUOTE", "CHARACTER", "STRING", 
  "IDENTIFIER", "INTEGER", "REAL", "COMMENT"
};

dfa::Vocabulary PascalParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PascalParser::_tokenNames;

PascalParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3b, 0x269, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0xad, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xb0, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xb7, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xc4, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xc9, 0xa, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0xce, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0xd3, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x5, 0xa, 0xdd, 0xa, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0xe1, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xe5, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0xee, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xf1, 0xb, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xfe, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0x101, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x111, 
    0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x114, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0x118, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x120, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 
    0x123, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x7, 0x19, 0x12b, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x12e, 
    0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x137, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 
    0x13a, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x13f, 
    0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x142, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x14b, 
    0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x155, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 
    0x164, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x167, 0xb, 0x24, 0x3, 0x25, 
    0x5, 0x25, 0x16a, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x173, 0xa, 0x26, 0xc, 0x26, 
    0xe, 0x26, 0x176, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x5, 0x27, 0x184, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x193, 
    0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x196, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1ac, 
    0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x7, 0x34, 0x1bb, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x1be, 
    0xb, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 
    0x35, 0x1c5, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 
    0x1ca, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x1cd, 0xb, 0x36, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x7, 0x39, 0x1dd, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x1e0, 0xb, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 
    0x3c, 0x5, 0x3c, 0x1e9, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x5, 0x3d, 0x1ee, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x7, 0x3e, 0x1f4, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x1f7, 0xb, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x5, 0x3f, 0x1fc, 0xa, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x201, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x20f, 0xa, 0x43, 
    0xc, 0x43, 0xe, 0x43, 0x212, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x21a, 0xa, 0x44, 0xc, 0x44, 
    0xe, 0x44, 0x21d, 0xb, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 
    0x5, 0x45, 0x223, 0xa, 0x45, 0x3, 0x46, 0x5, 0x46, 0x226, 0xa, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x22c, 0xa, 0x46, 
    0xc, 0x46, 0xe, 0x46, 0x22f, 0xb, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 
    0x47, 0x3, 0x47, 0x5, 0x47, 0x23c, 0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x244, 0xa, 0x48, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x7, 0x49, 0x249, 0xa, 0x49, 0xc, 0x49, 
    0xe, 0x49, 0x24c, 0xb, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 
    0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x5, 
    0x4e, 0x258, 0xa, 0x4e, 0x3, 0x4f, 0x5, 0x4f, 0x25b, 0xa, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x2, 
    0x2, 0x55, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
    0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
    0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 
    0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 
    0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 
    0x2, 0x7, 0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0x18, 0x19, 0x4, 0x2, 0xa, 0xa, 
    0xf, 0x13, 0x4, 0x2, 0x8, 0x9, 0x2a, 0x2a, 0x4, 0x2, 0x14, 0x15, 0x27, 
    0x29, 0x2, 0x251, 0x2, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x4, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0xba, 0x3, 0x2, 0x2, 0x2, 0x8, 0xbe, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xe, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x12, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x16, 0xea, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x102, 0x3, 0x2, 0x2, 0x2, 0x22, 0x106, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x26, 0x117, 0x3, 0x2, 0x2, 0x2, 0x28, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x11d, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x124, 0x3, 0x2, 0x2, 0x2, 0x30, 0x127, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x34, 0x133, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x38, 0x143, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x147, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x151, 0x3, 0x2, 0x2, 0x2, 0x40, 0x158, 0x3, 0x2, 0x2, 0x2, 0x42, 0x15a, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x46, 0x160, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x169, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x16f, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x183, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x185, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x189, 0x3, 0x2, 0x2, 0x2, 0x52, 0x18b, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x56, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x197, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1a0, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1ad, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1b1, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1c4, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1ce, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x1e1, 0x3, 0x2, 0x2, 0x2, 0x74, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x76, 0x1e6, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x1ef, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x202, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x204, 0x3, 0x2, 0x2, 0x2, 0x82, 0x207, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x86, 0x215, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x225, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x23b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x243, 0x3, 0x2, 0x2, 0x2, 0x90, 0x245, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x94, 0x24f, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x251, 0x3, 0x2, 0x2, 0x2, 0x98, 0x253, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x257, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x25a, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x25e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x260, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x262, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x264, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x266, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x3, 0x2, 0x2, 0xa9, 0xae, 
    0x7, 0x38, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x4, 0x2, 0x2, 0xab, 0xad, 0x7, 
    0x38, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb2, 0x7, 0x5, 0x2, 0x2, 0xb2, 0x3, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb4, 0x7, 0x1f, 0x2, 0x2, 0xb4, 0xb6, 0x5, 0x8, 0x5, 0x2, 0xb5, 0xb7, 
    0x5, 0x2, 0x2, 0x2, 0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x6, 
    0x2, 0x2, 0xb9, 0x5, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x5, 0x4, 0x3, 
    0x2, 0xbb, 0xbc, 0x5, 0xc, 0x7, 0x2, 0xbc, 0xbd, 0x7, 0x7, 0x2, 0x2, 
    0xbd, 0x7, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x38, 0x2, 0x2, 0xbf, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x18, 0xd, 0x2, 0xc1, 0xc2, 
    0x7, 0x6, 0x2, 0x2, 0xc2, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xc5, 0xc6, 0x5, 0x1c, 0xf, 0x2, 0xc6, 0xc7, 0x7, 0x6, 0x2, 
    0x2, 0xc7, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xcb, 0x5, 0x2e, 0x18, 0x2, 0xcb, 0xcc, 0x7, 0x6, 0x2, 0x2, 0xcc, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x5, 0x36, 
    0x1c, 0x2, 0xd0, 0xd1, 0x7, 0x6, 0x2, 0x2, 0xd1, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0xa, 0x6, 0x2, 0xd5, 
    0xd6, 0x5, 0x4e, 0x28, 0x2, 0xd6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 
    0x9, 0x2, 0x2, 0x2, 0xd8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 
    0x38, 0x2, 0x2, 0xda, 0x11, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0xe, 
    0x8, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe1, 0x7, 0x38, 0x2, 0x2, 
    0xdf, 0xe1, 0x5, 0x9a, 0x4e, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe5, 
    0x5, 0x9e, 0x50, 0x2, 0xe3, 0xe5, 0x5, 0xa0, 0x51, 0x2, 0xe4, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe3, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x10, 
    0x9, 0x2, 0xe7, 0xe8, 0x7, 0xa, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x12, 0xa, 
    0x2, 0xe9, 0x15, 0x3, 0x2, 0x2, 0x2, 0xea, 0xef, 0x5, 0x14, 0xb, 0x2, 
    0xeb, 0xec, 0x7, 0x6, 0x2, 0x2, 0xec, 0xee, 0x5, 0x14, 0xb, 0x2, 0xed, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0x20, 
    0x2, 0x2, 0xf3, 0xf4, 0x5, 0x16, 0xc, 0x2, 0xf4, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xf5, 0xf6, 0x7, 0x38, 0x2, 0x2, 0xf6, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf8, 0x7, 0x21, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x1e, 0x10, 0x2, 0xf9, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xff, 0x5, 0x20, 0x11, 0x2, 0xfb, 0xfc, 
    0x7, 0x6, 0x2, 0x2, 0xfc, 0xfe, 0x5, 0x20, 0x11, 0x2, 0xfd, 0xfb, 0x3, 
    0x2, 0x2, 0x2, 0xfe, 0x101, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x5, 0x1a, 0xe, 
    0x2, 0x103, 0x104, 0x7, 0xa, 0x2, 0x2, 0x104, 0x105, 0x5, 0x26, 0x14, 
    0x2, 0x105, 0x21, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x7, 0x22, 0x2, 
    0x2, 0x107, 0x108, 0x7, 0xb, 0x2, 0x2, 0x108, 0x109, 0x5, 0x24, 0x13, 
    0x2, 0x109, 0x10a, 0x7, 0xc, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x23, 0x2, 
    0x2, 0x10b, 0x10c, 0x5, 0x26, 0x14, 0x2, 0x10c, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x10d, 0x112, 0x5, 0x28, 0x15, 0x2, 0x10e, 0x10f, 0x7, 0x4, 0x2, 
    0x2, 0x10f, 0x111, 0x5, 0x28, 0x15, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 
    0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x115, 0x118, 0x5, 0x28, 0x15, 0x2, 
    0x116, 0x118, 0x5, 0x22, 0x12, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x117, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x27, 0x3, 0x2, 0x2, 0x2, 0x119, 
    0x11a, 0x5, 0x1a, 0xe, 0x2, 0x11a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x11c, 0x7, 0x38, 0x2, 0x2, 0x11c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x121, 0x5, 0x2a, 0x16, 0x2, 0x11e, 0x120, 0x5, 0x8e, 0x48, 0x2, 0x11f, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 
    0x7, 0x24, 0x2, 0x2, 0x125, 0x126, 0x5, 0x30, 0x19, 0x2, 0x126, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x12c, 0x5, 0x32, 0x1a, 0x2, 0x128, 0x129, 
    0x7, 0x6, 0x2, 0x2, 0x129, 0x12b, 0x5, 0x32, 0x1a, 0x2, 0x12a, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x5, 
    0x34, 0x1b, 0x2, 0x130, 0x131, 0x7, 0xd, 0x2, 0x2, 0x131, 0x132, 0x5, 
    0x26, 0x14, 0x2, 0x132, 0x33, 0x3, 0x2, 0x2, 0x2, 0x133, 0x138, 0x5, 
    0x2a, 0x16, 0x2, 0x134, 0x135, 0x7, 0x4, 0x2, 0x2, 0x135, 0x137, 0x5, 
    0x2a, 0x16, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 0x3, 
    0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x35, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x140, 0x5, 0x38, 0x1d, 0x2, 0x13c, 0x13d, 0x7, 0x6, 
    0x2, 0x2, 0x13d, 0x13f, 0x5, 0x38, 0x1d, 0x2, 0x13e, 0x13c, 0x3, 0x2, 
    0x2, 0x2, 0x13f, 0x142, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13e, 0x3, 0x2, 
    0x2, 0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x5, 0x3a, 0x1e, 
    0x2, 0x144, 0x145, 0x7, 0x6, 0x2, 0x2, 0x145, 0x146, 0x5, 0xc, 0x7, 
    0x2, 0x146, 0x39, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x7, 0x1e, 0x2, 
    0x2, 0x148, 0x14a, 0x5, 0x40, 0x21, 0x2, 0x149, 0x14b, 0x5, 0x44, 0x23, 
    0x2, 0x14a, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0xd, 0x2, 
    0x2, 0x14d, 0x14e, 0x5, 0x1a, 0xe, 0x2, 0x14e, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x150, 0x7, 0x38, 0x2, 0x2, 0x150, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x152, 0x5, 0x3c, 0x1f, 0x2, 0x152, 0x154, 0x7, 0x3, 0x2, 
    0x2, 0x153, 0x155, 0x5, 0x70, 0x39, 0x2, 0x154, 0x153, 0x3, 0x2, 0x2, 
    0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x156, 0x157, 0x7, 0x5, 0x2, 0x2, 0x157, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x158, 0x159, 0x7, 0x38, 0x2, 0x2, 0x159, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x15b, 0x7, 0x38, 0x2, 0x2, 0x15b, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x15c, 0x15d, 0x7, 0x3, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x46, 0x24, 0x2, 
    0x15e, 0x15f, 0x7, 0x5, 0x2, 0x2, 0x15f, 0x45, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x165, 0x5, 0x48, 0x25, 0x2, 0x161, 0x162, 0x7, 0x6, 0x2, 0x2, 0x162, 
    0x164, 0x5, 0x48, 0x25, 0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 0x2, 0x164, 
    0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 
    0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x47, 0x3, 0x2, 0x2, 0x2, 0x167, 0x165, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x16a, 0x7, 0x24, 0x2, 0x2, 0x169, 0x168, 
    0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 
    0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x5, 0x4a, 0x26, 0x2, 0x16c, 0x16d, 
    0x7, 0xd, 0x2, 0x2, 0x16d, 0x16e, 0x5, 0x1a, 0xe, 0x2, 0x16e, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x16f, 0x174, 0x5, 0x42, 0x22, 0x2, 0x170, 0x171, 
    0x7, 0x4, 0x2, 0x2, 0x171, 0x173, 0x5, 0x42, 0x22, 0x2, 0x172, 0x170, 
    0x3, 0x2, 0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 0x2, 0x174, 0x172, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x184, 0x5, 
    0x4e, 0x28, 0x2, 0x178, 0x184, 0x5, 0x58, 0x2d, 0x2, 0x179, 0x184, 0x5, 
    0x5e, 0x30, 0x2, 0x17a, 0x184, 0x5, 0x64, 0x33, 0x2, 0x17b, 0x184, 0x5, 
    0x5a, 0x2e, 0x2, 0x17c, 0x184, 0x5, 0x5c, 0x2f, 0x2, 0x17d, 0x184, 0x5, 
    0x6e, 0x38, 0x2, 0x17e, 0x184, 0x5, 0x74, 0x3b, 0x2, 0x17f, 0x184, 0x5, 
    0x76, 0x3c, 0x2, 0x180, 0x184, 0x5, 0x80, 0x41, 0x2, 0x181, 0x184, 0x5, 
    0x82, 0x42, 0x2, 0x182, 0x184, 0x5, 0x50, 0x29, 0x2, 0x183, 0x177, 0x3, 
    0x2, 0x2, 0x2, 0x183, 0x178, 0x3, 0x2, 0x2, 0x2, 0x183, 0x179, 0x3, 
    0x2, 0x2, 0x2, 0x183, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x183, 0x17b, 0x3, 
    0x2, 0x2, 0x2, 0x183, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x183, 0x17d, 0x3, 
    0x2, 0x2, 0x2, 0x183, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x183, 0x17f, 0x3, 
    0x2, 0x2, 0x2, 0x183, 0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 0x181, 0x3, 
    0x2, 0x2, 0x2, 0x183, 0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x185, 0x186, 0x7, 0x25, 0x2, 0x2, 0x186, 0x187, 0x5, 0x56, 
    0x2c, 0x2, 0x187, 0x188, 0x7, 0x26, 0x2, 0x2, 0x188, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x18b, 0x18c, 0x5, 0x2c, 0x17, 0x2, 0x18c, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x18e, 0x5, 0x88, 0x45, 0x2, 0x18e, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x18f, 0x194, 0x5, 0x4c, 0x27, 0x2, 0x190, 0x191, 0x7, 0x6, 0x2, 
    0x2, 0x191, 0x193, 0x5, 0x4c, 0x27, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x193, 0x196, 0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x5, 0x52, 0x2a, 0x2, 
    0x198, 0x199, 0x7, 0xe, 0x2, 0x2, 0x199, 0x19a, 0x5, 0x54, 0x2b, 0x2, 
    0x19a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x30, 0x2, 0x2, 
    0x19c, 0x19d, 0x5, 0x56, 0x2c, 0x2, 0x19d, 0x19e, 0x7, 0x31, 0x2, 0x2, 
    0x19e, 0x19f, 0x5, 0x88, 0x45, 0x2, 0x19f, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x1a0, 0x1a1, 0x7, 0x32, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x88, 0x45, 0x2, 
    0x1a2, 0x1a3, 0x7, 0x16, 0x2, 0x2, 0x1a3, 0x1a4, 0x5, 0x4c, 0x27, 0x2, 
    0x1a4, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x2c, 0x2, 0x2, 
    0x1a6, 0x1a7, 0x5, 0x88, 0x45, 0x2, 0x1a7, 0x1a8, 0x7, 0x2d, 0x2, 0x2, 
    0x1a8, 0x1ab, 0x5, 0x60, 0x31, 0x2, 0x1a9, 0x1aa, 0x7, 0x2e, 0x2, 0x2, 
    0x1aa, 0x1ac, 0x5, 0x62, 0x32, 0x2, 0x1ab, 0x1a9, 0x3, 0x2, 0x2, 0x2, 
    0x1ab, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1ad, 
    0x1ae, 0x5, 0x4c, 0x27, 0x2, 0x1ae, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1af, 
    0x1b0, 0x5, 0x4c, 0x27, 0x2, 0x1b0, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1b2, 0x7, 0x2f, 0x2, 0x2, 0x1b2, 0x1b3, 0x5, 0x88, 0x45, 0x2, 0x1b3, 
    0x1b4, 0x7, 0x23, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x66, 0x34, 0x2, 0x1b5, 
    0x1b6, 0x7, 0x26, 0x2, 0x2, 0x1b6, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1b7, 
    0x1bc, 0x5, 0x68, 0x35, 0x2, 0x1b8, 0x1b9, 0x7, 0x6, 0x2, 0x2, 0x1b9, 
    0x1bb, 0x5, 0x68, 0x35, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1bb, 
    0x1be, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bc, 
    0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 
    0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x5, 0x6a, 0x36, 0x2, 0x1c0, 0x1c1, 
    0x7, 0xd, 0x2, 0x2, 0x1c1, 0x1c2, 0x5, 0x4c, 0x27, 0x2, 0x1c2, 0x1c5, 
    0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1bf, 
    0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x1c6, 0x1cb, 0x5, 0x6c, 0x37, 0x2, 0x1c7, 0x1c8, 0x7, 
    0x4, 0x2, 0x2, 0x1c8, 0x1ca, 0x5, 0x6c, 0x37, 0x2, 0x1c9, 0x1c7, 0x3, 
    0x2, 0x2, 0x2, 0x1ca, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1c9, 0x3, 
    0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x1cd, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x5, 0x12, 
    0xa, 0x2, 0x1cf, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x7, 0x17, 
    0x2, 0x2, 0x1d1, 0x1d2, 0x5, 0x2c, 0x17, 0x2, 0x1d2, 0x1d3, 0x7, 0xe, 
    0x2, 0x2, 0x1d3, 0x1d4, 0x5, 0x88, 0x45, 0x2, 0x1d4, 0x1d5, 0x9, 0x3, 
    0x2, 0x2, 0x1d5, 0x1d6, 0x5, 0x88, 0x45, 0x2, 0x1d6, 0x1d7, 0x7, 0x16, 
    0x2, 0x2, 0x1d7, 0x1d8, 0x5, 0x4c, 0x27, 0x2, 0x1d8, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x1d9, 0x1de, 0x5, 0x72, 0x3a, 0x2, 0x1da, 0x1db, 0x7, 0x4, 
    0x2, 0x2, 0x1db, 0x1dd, 0x5, 0x72, 0x3a, 0x2, 0x1dc, 0x1da, 0x3, 0x2, 
    0x2, 0x2, 0x1dd, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1dc, 0x3, 0x2, 
    0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x5, 0x88, 0x45, 
    0x2, 0x1e2, 0x73, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x1a, 0x2, 
    0x2, 0x1e4, 0x1e5, 0x5, 0x7a, 0x3e, 0x2, 0x1e5, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x1e6, 0x1e8, 0x7, 0x1b, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 0x7a, 0x3e, 
    0x2, 0x1e8, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 0x2, 0x2, 
    0x2, 0x1e9, 0x77, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ed, 0x5, 0x88, 0x45, 
    0x2, 0x1eb, 0x1ec, 0x7, 0xd, 0x2, 0x2, 0x1ec, 0x1ee, 0x5, 0x7c, 0x3f, 
    0x2, 0x1ed, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x3, 0x2, 0x2, 
    0x2, 0x1ee, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x7, 0x3, 0x2, 0x2, 
    0x1f0, 0x1f5, 0x5, 0x78, 0x3d, 0x2, 0x1f1, 0x1f2, 0x7, 0x4, 0x2, 0x2, 
    0x1f2, 0x1f4, 0x5, 0x78, 0x3d, 0x2, 0x1f3, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1f4, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
    0x1f5, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f8, 0x3, 0x2, 0x2, 0x2, 
    0x1f7, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 0x7, 0x5, 0x2, 0x2, 
    0x1f9, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fc, 0x5, 0xe, 0x8, 0x2, 0x1fb, 
    0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 
    0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x200, 0x5, 0x96, 0x4c, 0x2, 0x1fe, 
    0x1ff, 0x7, 0xd, 0x2, 0x2, 0x1ff, 0x201, 0x5, 0x7e, 0x40, 0x2, 0x200, 
    0x1fe, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 0x201, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x5, 0x96, 0x4c, 0x2, 0x203, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0x7, 0x1c, 0x2, 0x2, 0x205, 
    0x206, 0x5, 0x84, 0x43, 0x2, 0x206, 0x81, 0x3, 0x2, 0x2, 0x2, 0x207, 
    0x208, 0x7, 0x1d, 0x2, 0x2, 0x208, 0x209, 0x5, 0x84, 0x43, 0x2, 0x209, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x7, 0x3, 0x2, 0x2, 0x20b, 0x210, 
    0x5, 0x2c, 0x17, 0x2, 0x20c, 0x20d, 0x7, 0x4, 0x2, 0x2, 0x20d, 0x20f, 
    0x5, 0x2c, 0x17, 0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x212, 
    0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 
    0x3, 0x2, 0x2, 0x2, 0x211, 0x213, 0x3, 0x2, 0x2, 0x2, 0x212, 0x210, 
    0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x7, 0x5, 0x2, 0x2, 0x214, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x215, 0x21b, 0x5, 0x8c, 0x47, 0x2, 0x216, 0x217, 0x5, 
    0xa6, 0x54, 0x2, 0x217, 0x218, 0x5, 0x8c, 0x47, 0x2, 0x218, 0x21a, 0x3, 
    0x2, 0x2, 0x2, 0x219, 0x216, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21d, 0x3, 
    0x2, 0x2, 0x2, 0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 
    0x2, 0x2, 0x2, 0x21c, 0x87, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21b, 0x3, 0x2, 
    0x2, 0x2, 0x21e, 0x222, 0x5, 0x8a, 0x46, 0x2, 0x21f, 0x220, 0x5, 0xa2, 
    0x52, 0x2, 0x220, 0x221, 0x5, 0x8a, 0x46, 0x2, 0x221, 0x223, 0x3, 0x2, 
    0x2, 0x2, 0x222, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x3, 0x2, 
    0x2, 0x2, 0x223, 0x89, 0x3, 0x2, 0x2, 0x2, 0x224, 0x226, 0x5, 0xe, 0x8, 
    0x2, 0x225, 0x224, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x226, 0x227, 0x3, 0x2, 0x2, 0x2, 0x227, 0x22d, 0x5, 0x86, 0x44, 
    0x2, 0x228, 0x229, 0x5, 0xa4, 0x53, 0x2, 0x229, 0x22a, 0x5, 0x86, 0x44, 
    0x2, 0x22a, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x228, 0x3, 0x2, 0x2, 
    0x2, 0x22c, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22b, 0x3, 0x2, 0x2, 
    0x2, 0x22d, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x22f, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x230, 0x23c, 0x5, 0x2c, 0x17, 0x2, 
    0x231, 0x23c, 0x5, 0x9c, 0x4f, 0x2, 0x232, 0x23c, 0x5, 0x9e, 0x50, 0x2, 
    0x233, 0x23c, 0x5, 0xa0, 0x51, 0x2, 0x234, 0x23c, 0x5, 0x3e, 0x20, 0x2, 
    0x235, 0x236, 0x7, 0x2b, 0x2, 0x2, 0x236, 0x23c, 0x5, 0x8c, 0x47, 0x2, 
    0x237, 0x238, 0x7, 0x3, 0x2, 0x2, 0x238, 0x239, 0x5, 0x88, 0x45, 0x2, 
    0x239, 0x23a, 0x7, 0x5, 0x2, 0x2, 0x23a, 0x23c, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x230, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x231, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x232, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x233, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x234, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x235, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x237, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x23d, 
    0x23e, 0x7, 0xb, 0x2, 0x2, 0x23e, 0x23f, 0x5, 0x90, 0x49, 0x2, 0x23f, 
    0x240, 0x7, 0xc, 0x2, 0x2, 0x240, 0x244, 0x3, 0x2, 0x2, 0x2, 0x241, 
    0x242, 0x7, 0x7, 0x2, 0x2, 0x242, 0x244, 0x5, 0x94, 0x4b, 0x2, 0x243, 
    0x23d, 0x3, 0x2, 0x2, 0x2, 0x243, 0x241, 0x3, 0x2, 0x2, 0x2, 0x244, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x245, 0x24a, 0x5, 0x92, 0x4a, 0x2, 0x246, 
    0x247, 0x7, 0x4, 0x2, 0x2, 0x247, 0x249, 0x5, 0x92, 0x4a, 0x2, 0x248, 
    0x246, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24a, 
    0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24b, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 
    0x5, 0x88, 0x45, 0x2, 0x24e, 0x93, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 
    0x7, 0x38, 0x2, 0x2, 0x250, 0x95, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 
    0x7, 0x39, 0x2, 0x2, 0x252, 0x97, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 
    0x7, 0x3a, 0x2, 0x2, 0x254, 0x99, 0x3, 0x2, 0x2, 0x2, 0x255, 0x258, 
    0x5, 0x96, 0x4c, 0x2, 0x256, 0x258, 0x5, 0x98, 0x4d, 0x2, 0x257, 0x255, 
    0x3, 0x2, 0x2, 0x2, 0x257, 0x256, 0x3, 0x2, 0x2, 0x2, 0x258, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x259, 0x25b, 0x5, 0xe, 0x8, 0x2, 0x25a, 0x259, 0x3, 
    0x2, 0x2, 0x2, 0x25a, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x3, 
    0x2, 0x2, 0x2, 0x25c, 0x25d, 0x5, 0x9a, 0x4e, 0x2, 0x25d, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0x25e, 0x25f, 0x7, 0x36, 0x2, 0x2, 0x25f, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0x260, 0x261, 0x7, 0x37, 0x2, 0x2, 0x261, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0x262, 0x263, 0x9, 0x4, 0x2, 0x2, 0x263, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0x264, 0x265, 0x9, 0x5, 0x2, 0x2, 0x265, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x266, 0x267, 0x9, 0x6, 0x2, 0x2, 0x267, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x2e, 0xae, 0xb6, 0xc3, 0xc8, 0xcd, 0xd2, 0xdc, 0xe0, 0xe4, 0xef, 0xff, 
    0x112, 0x117, 0x121, 0x12c, 0x138, 0x140, 0x14a, 0x154, 0x165, 0x169, 
    0x174, 0x183, 0x194, 0x1ab, 0x1bc, 0x1c4, 0x1cb, 0x1de, 0x1e8, 0x1ed, 
    0x1f5, 0x1fb, 0x200, 0x210, 0x21b, 0x222, 0x225, 0x22d, 0x23b, 0x243, 
    0x24a, 0x257, 0x25a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PascalParser::Initializer PascalParser::_init;
