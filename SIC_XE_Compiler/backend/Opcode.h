#ifndef Opcode_H_
#define Opcode_H_

#include "../Object.h"

namespace backend {

using namespace std;

enum class Opcode
{
    // Load from register
    LDA, LDB, LDCH, LDF, LDL, LDS, LDT, LDX, LPS,

    // Store value or address
    STA, STB, STCH, STF, STI, STL, STS, STSW, STT, STX,

    // Arithmetic and logical
    ADD, ADDF, ADDR, 
    SUB, SUBF, SUBR,
    MUL, MULF, MULR, 
    DIV, DIVF, DIVR,
    NORM, AND, OR,

    // Jump & Compare Opcodes
    J, JEQ, JGT, JLT, JSUB, JRET,
    COMP, COMPF, COMPR,

    // Type conversions
    FIX, FLOAT,

    // Register Operations
    CLEAR, RD, RMO, RSUB, SHIFTL, SHIFTR,

    // Auxillary
    HIO, SSK, SVC,
    TD, TIO, TIX, TIXR, WD,

    // Memory Declaration
    RESW, RESB,
    WORD, BYTE, DWORD,

    // Control
    START, END
};

static const string Opcode_STRINGS[] =
{
    // Load from register
    "LDA", "LDB", "LDCH", "LDF", "LDL", "LDS", "LDT", "LDX", "LPS",

    // Store value or address
    "STA", "STB", "STCH", "STF", "STI", "STL", "STS", "STSW", "STT", "STX",

    // Arithmetic and logical
    "ADD", "ADDF", "ADDR", 
    "SUB", "SUBF", "SUBR",
    "MUL", "MULF", "MULR", 
    "DIV", "DIVF", "DIVR",
    "NORM", "AND", "OR",

    // Jump Opcodes
    "J", "JEQ", "JGT", "JLT", "JSUB", "JRET",
    "COMP", "COMPF", "COMPR",

    // Type conversions
    "FIX", "FLOAT",

    // Register Operations
    "CLEAR", "RD", "RMO", "RSUB", "SHIFTL", "SHIFTR",

    // Auxillary
    "HIO", "SSK", "SVC",
    "TD", "TIO", "TIX", "TIXR", "WD",

    // Memory Declaration
    "RESW", "RESB",
    "WORD", "BYTE", "DWORD",

    // Control
    "START", "END"
};

// Load from register
constexpr Opcode LDA = Opcode::LDA;   // A <-- (m..m+2)
constexpr Opcode LDB = Opcode::LDB;   // B <-- (m..m+2) 
constexpr Opcode LDCH = Opcode::LDCH; // A [rightmost byte] <-- (m)
constexpr Opcode LDF = Opcode::LDF;   // F <-- (m..m+5)
constexpr Opcode LDL = Opcode::LDL;   // L <-- (m..m+2) 
constexpr Opcode LDS = Opcode::LDS;   // S <-- (m..m+2)  
constexpr Opcode LDT = Opcode::LDT;   // T <-- (m..m+2)  
constexpr Opcode LDX = Opcode::LDX;   // X <-- (m..m+2)  
constexpr Opcode LPS = Opcode::LPS;   //Load processor status from information beginning at address m

// Store value or address
constexpr Opcode STA = Opcode::STA;   // m..m+2 <-- (A)
constexpr Opcode STB = Opcode::STB;   // m..m+2 <-- (B)
constexpr Opcode STCH = Opcode::STCH; // m <-- (A) [rightmost byte]
constexpr Opcode STF = Opcode::STF;   // m <-- (A) [rightmost byte]
constexpr Opcode STI = Opcode::STI;   // Interval timer value<--(m..m+2) 
constexpr Opcode STL = Opcode::STL; 
constexpr Opcode STS = Opcode::STS; 
constexpr Opcode STSW = Opcode::STSW; 
constexpr Opcode STT = Opcode::STT;   // m..m+2 <-- (T)
constexpr Opcode STX = Opcode::STX;   // m..m+2 <-- (X)

// Arithmetic and logical
constexpr Opcode ADD = Opcode::ADD;   // A <-- (A) + (m..m+2)
constexpr Opcode ADDF = Opcode::ADDF; // F <-- (F) + (m..m+5) 
constexpr Opcode ADDR = Opcode::ADDR; // r2 <-- (r2) + (r1)
constexpr Opcode SUB = Opcode::SUB;   // A <-- (A) - (m..m+2)
constexpr Opcode SUBF = Opcode::SUBF; // F <-- (F) - (m..m+5) 
constexpr Opcode SUBR = Opcode::SUBR; // r2 <-- (r2) - (r1) 
constexpr Opcode MUL = Opcode::MUL;   // A <-- (A) * (m..m+2)
constexpr Opcode MULF = Opcode::MULF; // F <-- (F) * (m..m+5) 
constexpr Opcode MULR = Opcode::MULR; // r2 <-- (r2) * (r1) 
constexpr Opcode DIV = Opcode::DIV;   // A : (A) / (m..m+2)
constexpr Opcode DIVF = Opcode::DIVF; // F : (F) / (m..m+5)
constexpr Opcode DIVR = Opcode::DIVR; // (r2) <-- (r2) / (r1) 
constexpr Opcode NORM = Opcode::NORM; // F <-- (F) [normalized] 
constexpr Opcode AND = Opcode::AND;   // A <-- (A) & (m..m+2)
constexpr Opcode OR = Opcode::OR;     // A <-- (A) | (m..m+2)

// Jump Opcodes
constexpr Opcode J = Opcode::J;       // PC <-- m
constexpr Opcode JEQ = Opcode::JEQ;   // PC <-- m if CC set to =
constexpr Opcode JGT = Opcode::JGT;   // PC <-- m if CC set to >
constexpr Opcode JLT = Opcode::JLT;   // PC <-- m if CC set to <
constexpr Opcode JRET = Opcode::JRET;
constexpr Opcode JSUB = Opcode::JSUB; // L <-- (PC); PC <-- m
constexpr Opcode COMP = Opcode::COMP;    // A : (m..m+2)
constexpr Opcode COMPF = Opcode::COMPF;  // F : (m..m+5) 
constexpr Opcode COMPR = Opcode::COMPR;  // (r1) : (r2) 

// Type conversions
constexpr Opcode FIX = Opcode::FIX;       // A <-- (F) [convert to integer] 
constexpr Opcode FLOAT = Opcode::FLOAT;   // F <-- (A) [convert to float]

// Register Operations
constexpr Opcode CLEAR = Opcode::CLEAR;   // r1 <-- 0 
constexpr Opcode RD = Opcode::RD;         // A [rightmost byte] <-- data from device specified by (m)
constexpr Opcode RMO = Opcode::RMO;       // r2 <-- (r1)
constexpr Opcode RSUB = Opcode::RSUB;     // PC <-- (L)
// r1 <-- (r1); left circular X shift n bits. {In assembled nstruction, r2=n-1}
constexpr Opcode SHIFTL = Opcode::SHIFTL;  
// r1 <-- (r1); right shift n X bits with vacated bit positions set equal to leftmost bit of (r1). 
// {In assembled Opcode, r2=n-1}
constexpr Opcode SHIFTR = Opcode::SHIFTR;

// Auxillary
constexpr Opcode HIO = Opcode::HIO; 
constexpr Opcode SSK = Opcode::SSK; 
constexpr Opcode SVC = Opcode::SVC; 
constexpr Opcode TD = Opcode::TD; 
constexpr Opcode TIO = Opcode::TIO; 
constexpr Opcode TIX = Opcode::TIX;   // X <-- (X) + 1; (X) : (m..m+2) 
constexpr Opcode TIXR = Opcode::TIXR; // X <-- (X) + 1; (X) : (r1)
constexpr Opcode WD = Opcode::WD;     // Device specified by (m) <-- (A) [rightmost byte]

// Memory Declaration
constexpr Opcode RESW = Opcode::RESW; 
constexpr Opcode RESB = Opcode::RESB;
constexpr Opcode WORD = Opcode::WORD;
constexpr Opcode DWORD = Opcode::DWORD;  
constexpr Opcode BYTE = Opcode::BYTE;

// Control
constexpr Opcode START = Opcode::START; 
constexpr Opcode END = Opcode::END;

inline ostream& operator << (ostream& ofs, const Opcode& Opcode)
{
    ofs << toUpperCase(Opcode_STRINGS[static_cast<int>(Opcode)]);
    return ofs;
}

}

#endif
