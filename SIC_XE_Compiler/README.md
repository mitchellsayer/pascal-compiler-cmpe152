# Pascal Parser
First generate the ANTLR files by running: 
``` make antlr ```

And then build the code by running: 
``` make compile ```

And run the parser by specifying an input and output filepath: 
``` ./parser test.pas test-out.txt ```

The output file does not have to exist when the scanner is run.