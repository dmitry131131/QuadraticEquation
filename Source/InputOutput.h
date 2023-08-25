/**
 * @file
 * @brief File with prototypes of input/output functions
*/
#ifndef INPUT_OUTPUT_FUNC_H
#define INPUT_OUTPUT_FUNC_H

enum Colors {
    NONE,
    RED,
    GREEN,
    BLUE,
    VIOLET
};

/**
 * Scip symbols from flow until found '\n'
 * @param [in] flow filename or flow name
*/
enum ErrorHandling SkipInput(FILE* flow);
/**
 * Console input of 3 double number
 * @param [out] Coeff array with coefficients
 * @param [in] file file or input flow 
 * @return Return error code or NO_ERRORS
*/
enum ErrorHandling Input(double* Coeff, FILE* file); 
/**
 * Console Output 
 * @param [in] ModeAndAnswerData name of data struct ModeAndAnswers
 * @return ErroreCode
*/
enum ErrorHandling ConsoleOutput(struct ModeAndAnswers* ModeAndAnswersData);
/**
 * Print Error value to stdout
 * @param [in] ErrorCode code of error (enum ErrorHandling)
 * @param [in] flow output flow
 * @param filename name of opened file
*/
void PrintErrorValue(ErrorHandling ErrorCode, FILE* flow, const char* filename); 
/**
 * Print help information about programm
*/
void HelpOutput();
/**
 * Open file from console
 * @param [in] argc count of console arguments
 * @param [in] argv console arguments array
 * @param [out] i out function iterator
 * @return file or NULL if file open error
*/
FILE* OpenFile(const int argc, const char* const argv[], int* i);
/**
 * Change output color
 * @param [in] color color
*/
void ChangeColor(enum Colors color);
/**
 * @param [in] file filename
 * @param [in] color output color
*/
void PrintFilename(char* file, enum Colors color);

#endif // INPUT_OUTPUT_FUNC_H