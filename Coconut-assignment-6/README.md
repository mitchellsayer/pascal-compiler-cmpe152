# Pascal Parser
Reach the home directory by running ``` ubuntu ``` in cmd and then type in ``` explorer.exe . ``` and place the files there.

First generate the ANTLR files by running: 
``` make antlr ```

And then build the code by running: 
``` make compile ```

And run the parser by specifying an input and output filepath: 
``` ./parser test-in.pas test-out.txt ```

The output file does not have to exist when the scanner is run.