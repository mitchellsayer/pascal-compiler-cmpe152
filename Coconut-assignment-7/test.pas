PROGRAM test;

CONST
    constvar = 3.14;

VAR
    alpha : INTEGER;
    beta : INTEGER;
    result : INTEGER;

FUNCTION add (a:INTEGER; b:INTEGER) : INTEGER;
VAR
    c: INTEGER;
BEGIN
    c := a + b;
    add := c;
END;

BEGIN
    alpha  := -88;
    beta   := 99;
    result := add(alpha, beta);
END.
