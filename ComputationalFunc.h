/* Prototypes and preprocessor dirictives */
#define MIN_DOUBLE_VALUE 0.000001
#define MAX_INPUT_COUNT 5

enum OutputMode {
    ERROR = 0,
    NOT_EQUATION = 1,
    LINERAL_EQUATION = 2,
    ONE_REAL_SOLUTION = 3,
    TWO_REAL_SOLUTIONS = 4,
    TWO_COMPLEX_SOLUTONS = 5
};

enum ErrorHandling {
    NO_ERRORS = 0,
    EXCEEDED_INPUT_LIMIT = 1,
    COEFFICIENTS_NOT_NUMBER = 2,
    ANSWERS_NOT_NUMBER = 3,
    FOUND_EOF_STDIN = 4,
    OUTPUT_ERROR = 5
};
    
double* SolvingQuadraticEquation(double a, double b, double c, OutputMode* Mode);         // solving finction prototype

void ScipInput();  //Scip trash symbols from stdin flow

int ConsoleInput(double*, double*, double*);  //  Console input of 3 double number

void ConsoleOutput(double* Out, OutputMode Mode);  // Console Output 

int IsFinite(double number);   // Check nubmer is not infinity or NAN

int IsZero(double number);    // Check number != 0

void ProgrammEnding();
