PROGRAM test;

VAR
    alpha : INTEGER;
    beta : REAL;
    result : REAL;

FUNCTION add (a:INTEGER; b:REAL) : REAL;
VAR
    temp : REAL;
BEGIN
    add := a + b + temp;
END;

BEGIN
    alpha  := 88;
    beta   := 99.9;
    result := add(alpha, beta);
END.
