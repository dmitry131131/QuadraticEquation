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
    OUTPUT_ERROR = 5,
    FILE_NOT_OPENED = 6,
    FILE_INPUT_ERROR = 7,
    FOUND_EOF_FILE = 8,
    CLOSE_FILE_ERROR = 9,
    TOO_MANY_CONSOLE_ARG = 10,
    INVALID_CONSOLE_ARG = 11
};

struct ModeAndAnswers
{
    OutputMode OutputMode;
    double Answers[2];
};
    
void SolvingQuadraticEquation(double a, double b, double c, struct ModeAndAnswers* );         // solving finction prototype

void ScipInput(FILE* flow);  //Scip trash symbols from stdin flow

int ConsoleInput(double*, double*, double*);  //  Console input of 3 double number

int FileInput(double* a, double* b, double* c, FILE* file); // File input of 3 number

void ConsoleOutput(struct ModeAndAnswers* ModeAndAnswersData);  // Console Output 

int IsFinite(double number);   // Check nubmer is not infinity or NAN

int IsZero(double number);    // Check number != 0

int EqualityNumbers(const double a, const double b); // a == b

void PrintErrorValue(ErrorHandling ErrorCode);  // Print Error value to stdout

void TwoComplexSolutions(double a, double b, double D, struct ModeAndAnswers* ModeAndAnswersData); // Two complex solutions 

void TwoRealSolutions(const double a, const double b, const double D, struct ModeAndAnswers* ModeAndAnswersData);  // Two real solutions

void OneRealSolution(const double a, const double b, const double D, struct ModeAndAnswers* ModeAndAnswersData); // One real solution

void LineralEquation(const double b, const double c, struct ModeAndAnswers* ModeAndAnswersData); // Lineral equation

void NotEquation(struct ModeAndAnswers* ModeAndAnswersData); // Not equation
