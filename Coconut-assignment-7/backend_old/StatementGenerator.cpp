#include <string>
#include <vector>
#include <map>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"
#include "StatementGenerator.h"

namespace backend {

using namespace std;
using namespace intermediate;

void StatementGenerator::emitAssignment(PascalParser::AssignmentStatementContext *ctx)
{
    PascalParser::VariableContext *varCtx  = ctx->lhs()->variable();
    PascalParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    // The last modifier, if any, is the variable's last subscript or field.
    int modifierCount = varCtx->modifier().size();
    PascalParser::ModifierContext *lastModCtx = modifierCount == 0
                            ? nullptr : varCtx->modifier()[modifierCount - 1];

    // The target variable has subscripts and/or fields.
    if (modifierCount > 0)
    {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }

    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float variable := integer constant
    if ((varType == Predefined::realType)
        && (exprType->baseType() == Predefined::integerType)) emit(I2F);

    // Emit code to store the expression value into the target variable.
    // The target variable has no subscripts or fields.
    if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

    // The target variable is a field.
    else if (lastModCtx->field() != nullptr)
    {
        emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
    }

    // The target variable is an array element.
    else
    {
        emitStoreValue(nullptr, varType);
    }
}

void StatementGenerator::emitIf(PascalParser::IfStatementContext *ctx)
{
    /***** Complete this member function. *****/
	PascalParser::TrueStatementContext *tctx = ctx->trueStatement();
	PascalParser::FalseStatementContext *fctx = ctx->falseStatement();
	Label *exitloop = new Label();

	compiler->visit(ctx->expression());

	if(fctx == nullptr)
	{
		emit(IFEQ, exitloop);
		compiler->visit(tctx);
	}

	else
	{
		Label *flabel = new Label();

		emit(IFEQ, flabel);
		compiler->visit(tctx);
		emit(GOTO, exitloop);

		emitLabel(flabel);
		compiler->visit(fctx);

	}

	emitLabel(exitloop);
}

void StatementGenerator::emitCase(PascalParser::CaseStatementContext *ctx) {

    /***** Complete this member function. *****/
	int bcount = 0;
	PascalParser::ExpressionContext *exprCtx = ctx->expression();
    PascalParser::CaseBranchListContext *branchListCtx = ctx->caseBranchList();

    int branches = ((branchListCtx->children.size()/2) + 1);
    Label branchLabels[branches];
    Label *exitcase = new Label();

    compiler->visit(exprCtx);

    emit(LOOKUPSWITCH);
    struct count{
        int val;
        int branchnum;
    };
    count pair[100];

    int size = 0;

    if(branchListCtx != nullptr) {
        for(PascalParser::CaseBranchContext *branchCtx : branchListCtx->caseBranch()) {
            if(branchCtx->caseConstantList() != nullptr) {
                PascalParser::CaseConstantListContext *constListCtx = branchCtx->caseConstantList();
                for(PascalParser::CaseConstantContext *caseConstCtx : constListCtx->caseConstant()) {
                    if(caseConstCtx != nullptr) {
                        int value = caseConstCtx->value;
                        pair[size].val = value;
                        pair[size].branchnum = bcount;
                        size++;
                    }
                }
                bcount++;
            }
        }
    }

    int k, j, min;

    for(k = 0; k< size-1; k++) {
        min = k;
        for(j = k+1; j<size; j++) {
            if(pair[j].val < pair[min].val) {
                min = j;
            }
        }

        count temp = pair[min];
        pair[min] = pair[k];
        pair[k] = temp;
    }

    for(int i = 0; i < size; i++) {
        emitLabel(pair[i].val, &branchLabels[pair[i].branchnum]);
    }

    emitLabel("default", exitcase);

    int counter = 0;

    if(branchListCtx != nullptr) {
        for(PascalParser::CaseBranchContext *branchCtx : branchListCtx->caseBranch()) {
            if(branchCtx->statement() != nullptr) {
                emitLabel(&branchLabels[counter]);
                compiler->visit(branchCtx->statement());
                emit(GOTO, exitcase);
            }
            counter++;
        }
        emitLabel(exitcase);
    }
}

void StatementGenerator::emitRepeat(PascalParser::RepeatStatementContext *ctx) {
    Label *loopTopLabel  = new Label();
    Label *loopExitLabel = new Label();

    emitLabel(loopTopLabel);

    compiler->visit(ctx->statementList());
    compiler->visit(ctx->expression());
    emit(IFNE, loopExitLabel);
    emit(GOTO, loopTopLabel);

    emitLabel(loopExitLabel);
}

void StatementGenerator::emitWhile(PascalParser::WhileStatementContext *ctx)
{
    /***** Complete this member function. *****/
	   Label *loopTopLabel  = new Label();
	   Label *loopExitLabel = new Label();

	    emitLabel(loopTopLabel);

	    compiler->visit(ctx->expression());
	    emit(IFEQ, loopExitLabel);
	    compiler->visit(ctx->statement());

	    emit(GOTO, loopTopLabel);

	    emitLabel(loopExitLabel);
}

void StatementGenerator::emitFor(PascalParser::ForStatementContext *ctx)
{
    /***** Complete this member function. *****/
	Label *ForTopLabel = new Label(); //L001
		Label *ForExitLabel = new Label(); //L002
		Label *ForContinueLabel = new Label(); //L003
		Label *ForBreakLabel = new Label(); //L004

		PascalParser::ExpressionContext *startExprCtx = ctx->expression()[0];
		PascalParser::ExpressionContext *stopExprCtx = ctx->expression()[1];
		PascalParser::FactorContext *varCtx = ctx->expression()[0]->simpleExpression()[0]->term()[0]->factor()[0];
		PascalParser::VariableContext *controlCtx = ctx->variable();
		string controlName = controlCtx->entry->getName();

		bool to = ctx->TO() != nullptr;

		string varText = ctx->variable()->getText();
		string varType = typeDescriptor(varCtx->type);

		compiler->visit(startExprCtx);
		emitStoreValue(controlCtx->entry, controlCtx->type);

		emitLabel(ForTopLabel); //L001
		emitLoadValue(controlCtx->entry);

		compiler->visit(stopExprCtx);


		if(to)
		{
			emit(IF_ICMPGT, ForContinueLabel);
		}
		else
		{
			emit(IF_ICMPLT, ForContinueLabel);
		}
		emit(ICONST_0);
		emit(GOTO, ForBreakLabel);
		emitLabel(ForContinueLabel);
		emit(ICONST_1);
		emitLabel(ForBreakLabel);
		emit(IFNE, ForExitLabel);

		compiler->visit(ctx->statement());
		emitLoadValue(controlCtx->entry);
		if(to)
		{
			emitLoadConstant(1);
		}
		else
		{
			emitLoadConstant(-1);
		}
		emit(IADD);
		emitStoreValue(controlCtx->entry, controlCtx->type);
		emit(GOTO, ForTopLabel);
		emitLabel(ForExitLabel);
}


void StatementGenerator::emitFunctionCall(PascalParser::FunctionCallContext *ctx) {
	PascalParser::ArgumentListContext *argListCtx = ctx->argumentList();
	PascalParser::FunctionNameContext *nameCtx = ctx->functionName();

	SymtabEntry *procSymtab = ctx->functionName()->entry;
	vector<SymtabEntry *> *parmIds = procSymtab->getRoutineParameters();
	string funcCall = programName + "/" + nameCtx->IDENTIFIER()->getText() + "(";

	int index = 0;

	if (argListCtx != nullptr)
	{

		for (SymtabEntry *parmId : *parmIds)
		{
			funcCall += typeDescriptor(parmId);
			compiler->visit(argListCtx->argument()[index]);
			string currentType = typeDescriptor(argListCtx->argument()[index]->expression()->type);
			if(currentType != typeDescriptor(parmId))
			{
				if(currentType == "I")
				{
					emit(I2F);
				}
				else
				{
					emit(F2I);
				}
			}

			index++;
		}
	}
	funcCall += ")" + typeDescriptor(procSymtab);

	emit(INVOKESTATIC, funcCall);


	compiler->visit(ctx->functionName());
}

void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  PascalParser::ArgumentListContext *argListCtx)
{
	string ret = "";
	Typespec targetType;
	vector<SymtabEntry*> *parameters = routineId->getRoutineParameters();
	for (int i = 0; i < parameters->size(); i++)
	{
		SymtabEntry *parmId = (*parameters)[i];
		ret += "I";
	}
	emit (INVOKESTATIC, programName +"/" + routineId->getName()+ "("+ret+")");

}

void StatementGenerator::emitWrite(PascalParser::WriteStatementContext *ctx)
{
    emitWrite(ctx->writeArguments(), false);
}

void StatementGenerator::emitWriteln(PascalParser::WritelnStatementContext *ctx)
{
    emitWrite(ctx->writeArguments(), true);
}

void StatementGenerator::emitWrite(PascalParser::WriteArgumentsContext *argsCtx, bool needLF)
{
    emit(GETSTATIC, "java/lang/System/out", "Ljava/io/PrintStream;");

    if (argsCtx == nullptr)
    {
        emit(INVOKEVIRTUAL, "java/io/PrintStream.println()V");
        localStack->decrease(1);
    }

    // Generate code for the arguments.
    else
    {
        string format;
        int exprCount = createWriteFormat(argsCtx, format, needLF);

        // Load the format string.
        emit(LDC, format);

        // Emit the arguments array.
       if (exprCount > 0)
        {
            emitArgumentsArray(argsCtx, exprCount);

            emit(INVOKEVIRTUAL,
                        string("java/io/PrintStream/printf(Ljava/lang/String;")
                      + string("[Ljava/lang/Object;)")
                      + string("Ljava/io/PrintStream;"));
            localStack->decrease(2);
            emit(POP);
        }
        else
        {
            emit(INVOKEVIRTUAL,
                 "java/io/PrintStream/print(Ljava/lang/String;)V");
            localStack->decrease(2);
        }
    }
}

int StatementGenerator::createWriteFormat(PascalParser::WriteArgumentsContext *argsCtx, string& format, bool needLF) {
    int exprCount = 0;
    format += "\"";

    // Loop over the write arguments.
    for (PascalParser::WriteArgumentContext *argCtx : argsCtx->writeArgument()) {
        Typespec *type = argCtx->expression()->type;
        string argText = argCtx->getText();

        // Append any literal strings.
        if (argText[0] == '\'') format += convertString(argText, true);

        // For any other expressions, append a field specifier.
        else
        {
            exprCount++;
            format.append("%");

            PascalParser::FieldWidthContext *fwCtx = argCtx->fieldWidth();
            if (fwCtx != nullptr)
            {
                string sign = (   (fwCtx->sign() != nullptr)
                               && (fwCtx->sign()->getText() == "-")) ? "-" : "";
                format += sign + fwCtx->integerConstant()->getText();

                PascalParser::DecimalPlacesContext *dpCtx =
                                                        fwCtx->decimalPlaces();
                if (dpCtx != nullptr)
                {
                    format += "." + dpCtx->integerConstant()->getText();
                }
            }

            string typeFlag = type == Predefined::integerType ? "d"
                            : type == Predefined::realType    ? "f"
                            : type == Predefined::booleanType ? "b"
                            : type == Predefined::charType    ? "c"
                            :                                  "s";
            format += typeFlag;
        }
    }

    format += needLF ? "\\n\"" : "\"";

    return exprCount;
}

void StatementGenerator::emitArgumentsArray(
                    PascalParser::WriteArgumentsContext *argsCtx, int exprCount)
{
    // Create the arguments array.
    emitLoadConstant(exprCount);
    emit(ANEWARRAY, "java/lang/Object");

    int index = 0;

    // Loop over the write arguments to fill the arguments array.
    for (PascalParser::WriteArgumentContext *argCtx :
                                                argsCtx->writeArgument())
    {
        string argText = argCtx->getText();
        PascalParser::ExpressionContext *exprCtx = argCtx->expression();
        Typespec *type = exprCtx->type->baseType();

        // Skip string constants, which were made part of
        // the format string.
        if (argText[0] != '\'')
        {
            emit(DUP);
            emitLoadConstant(index++);

            compiler->visit(exprCtx);

            Form form = type->getForm();
            if (    ((form == SCALAR) || (form == ENUMERATION))
                 && (type != Predefined::stringType))
            {
                emit(INVOKESTATIC, valueOfSignature(type));
            }

            // Store the value into the array.
            emit(AASTORE);
        }
    }
}

void StatementGenerator::emitRead(PascalParser::ReadStatementContext *ctx)
{
    emitRead(ctx->readArguments(), false);
}

void StatementGenerator::emitReadln(PascalParser::ReadlnStatementContext *ctx)
{
    emitRead(ctx->readArguments(), true);
}

void StatementGenerator::emitRead(PascalParser::ReadArgumentsContext *argsCtx,
                                  bool needSkip)
{
    int size = argsCtx->variable().size();

    // Loop over read arguments.
    for (int i = 0; i < size; i++)
    {
        PascalParser::VariableContext *varCtx = argsCtx->variable()[i];
        Typespec *varType = varCtx->type;

        if (varType == Predefined::integerType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextInt()I");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::realType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextFloat()F");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::booleanType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextBoolean()Z");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::charType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(LDC, "\"\"");
            emit(INVOKEVIRTUAL,
                 string("java/util/Scanner/useDelimiter(Ljava/lang/String;)") +
                 string("Ljava/util/Scanner;"));
            emit(POP);
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emit(ICONST_0);
            emit(INVOKEVIRTUAL, "java/lang/String/charAt(I)C");
            emitStoreValue(varCtx->entry, nullptr);

            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/reset()Ljava/util/Scanner;");

        }
        else  // string
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emitStoreValue(varCtx->entry, nullptr);
        }
    }

    // READLN: Skip the rest of the input line.
    if (needSkip)
    {
        emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
        emit(INVOKEVIRTUAL, "java/util/Scanner/nextLine()Ljava/lang/String;");
        emit(POP);
    }
}

}
