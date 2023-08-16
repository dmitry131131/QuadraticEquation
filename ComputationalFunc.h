/* Prototypes and preprocessor dirictives */

enum OutputMode {
    ERROR,
    NOT_EQUATION,
    LINERAL_EQUATION,
    ONE_REAL_SOLUTION,
    TWO_REAL_SOLUTIONS,
    TWO_COMPLEX_SOLUTONS
};
    

double* SolvingQuadraticEquation(double a, double b, double c, int* Mode);         // solving finction prototype

void ScipInput();  //Scip trash symbols from stdin flow

int ConsoleInput(double *, double *, double *);  //  Console input of 3 double number

void ConsoleOutput(double* Out, int Mode);  // Console Output 
