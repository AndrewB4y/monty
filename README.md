# monty
Interpreter for Monty 0.98 ByteCodes files.


# Usage


    `<$ monty file>`

Where file is the path to the file containing Monty byte code

If no file is given, or if there is more than one argument to the program, the error message **USAGE: monty file** is displayed. Exiting with the status **EXIT_FAILURE**./

If, for any reason, its not possible to open the file, the error message **Error: Can't open file <file>**. Exiting with the status EXIT_FAILURE