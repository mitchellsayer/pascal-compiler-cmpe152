test	START	1000
alpha	RESW	1
beta	RESW	1
result	RESW	1
; 
; ROUTINE: add
; 

a	WORD	0
add	WORD	3
b	WORD	1
temp	WORD	2
; Call initFrame
add	LDX	stackindex
	STL	stack, x
	LDA	52
	LDB	2
	JSUB	initFrame
; 012 add:=a+b+temp
	FLOAT	
	ADDF	stack,x
	FLOAT	
	ADDF	stack,x
; Load Variable Offset
	LDA	2
	JSUB	findstackframe
	ADD	3
	CLEAR	T
	ADDR	A, T
; Pop Stack & Store value
	LDA	stackindex
	SUB	6
	STA	stackindex
	LDX	stackindex
	STF	stack,x
	LDX	T
	STF	stack,x

	LDA	1
	JSUB	findstackframe
	ADD	0
	CLEAR	X
	ADDR	A, X
	LDF	stack, x
	STF	1634497893
; 
; ROUTINE: MAIN
; 
; Call initFrame
MAIN	LDX	stackindex
	STL	stack, x
	LDA	-3
	LDB	1
	JSUB	initFrame
; 016 alpha:=88
	LDA	3
	JSUB	findstackframe
	ADD	3
	CLEAR	X
	ADDR	A, X
	LDA	88
	STA	1667968120
; Load Variable Offset
	LDA	1
	JSUB	findstackframe
	ADD	0
	CLEAR	T
	ADDR	A, T
; Pop Stack & Store value
	LDA	stackindex
	SUB	3
	STA	stackindex
	LDX	stackindex
	STA	stack,x
	LDX	T
	STA	stack,x
; 017 beta:=99.9
	LDA	3
	JSUB	findstackframe
	ADD	6
	CLEAR	X
	ADDR	A, X
	LDF	99.9
	STF	stack,x
; Load Variable Offset
	LDA	1
	JSUB	findstackframe
	ADD	0
	CLEAR	T
	ADDR	A, T
; Pop Stack & Store value
	LDA	stackindex
	SUB	6
	STA	stackindex
	LDX	stackindex
	STF	stack,x
	LDX	T
	STF	stack,x
; 018 result:=add(alpha,beta)
	JSUB	add
; Load Variable Offset
	LDA	1
	JSUB	findstackframe
	ADD	0
	CLEAR	T
	ADDR	A, T
; Pop Stack & Store value
	LDA	stackindex
	SUB	6
	STA	stackindex
	LDX	stackindex
	STF	stack,x
	LDX	T
	STF	stack,x
; Call freeFrame
	JSUB	freeFrame
	LDL	stack
	JRET	
