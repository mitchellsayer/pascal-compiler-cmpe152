PROGRAM PascalTest;

CONST
    PI = 3.141592653589;
    MAXLEN = 10;

TYPE
    arr1d = ARRAY [CHAR] of INTEGER;
    arr2d = ARRAY [CHAR,CHAR] of INTEGER;

VAR
    iter: CHAR;
    ret: INTEGER;
    myarr1: arr1d;
    myarr2: arr2d;

FUNCTION printfn ( arr: arr1d ): INTEGER;
VAR
    i: CHAR;
    count: INTEGER;

BEGIN
    FOR i := 'a' to 'z' DO
    BEGIN
        writeln ( 'array value [', i, '] = ', myarr1[i] );
        count := count + 1;
    END;
    printfn := count;
END;

BEGIN
    ret := printfn ( myarr1 );

    FOR iter := 'a' to 'z' DO
    BEGIN
        myarr1[iter] := ret;
    END;
    writeln (PI);
END.