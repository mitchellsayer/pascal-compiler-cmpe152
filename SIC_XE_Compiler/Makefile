ANTLRFILE=Pascal.g4

antlr4=java -jar ${ANTLR_JAR}

PROJECTPATH=$(shell pwd)
ANTLR_RUNTIME_INCLUDES=/usr/local/include/antlr4-runtime
ANTLR_INCLUDES=$(PROJECTPATH)/target/generated-sources/ant4
LIB_PATH=/usr/local/lib
LIB=antlr4-runtime

PROG=CompilerMain.cpp
FRONTEND=$(PROJECTPATH)/frontend/*.cpp
BACKEND=$(PROJECTPATH)/backend/*.cpp
SYMTAB=$(PROJECTPATH)/intermediate/symtab/*.cpp
TYPE=$(PROJECTPATH)/intermediate/type/*.cpp
UTIL=$(PROJECTPATH)/intermediate/util/*.cpp

OUT=compiler
ANTLR_SOURCES=target/generated-sources/ant4/*.cpp
SOURCES=$(ANTLR_SOURCES) $(PROG) $(FRONTEND) $(BACKEND) $(SYMTAB) $(TYPE) $(UTIL)


compile:
	g++ -std=c++11 -o $(OUT) -I$(ANTLR_RUNTIME_INCLUDES) -I$(ANTLR_INCLUDES) -I$(PROJECTPATH) -L$(LIB_PATH) -w $(SOURCES) -l$(LIB)

antlr:
	$(antlr4) -o ./target/generated-sources/ant4 -no-listener -visitor -encoding UTF-8 -Dlanguage=Cpp $(ANTLRFILE)