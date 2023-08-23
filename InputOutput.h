/**
 * @file
 * @brief File with prototypes of input/output functions
*/
#ifndef INPUT_OUTPUT_FUNC_H
#define INPUT_OUTPUT_FUNC_H

/**
 * Scip symbols from flow until found '\n'
 * @param [in] flow filename or flow name
*/
void SkipInput(FILE* flow);
/**
 * Console input of 3 double number
 * @param [out] Coeff array with coefficients
 * @return Return error code or NO_ERRORS
*/
enum ErrorHandling Input(double* Coeff, FILE* file); 
/**
 * Console Output 
 * @param [in] ModeAndAnswerData name of data struct ModeAndAnswers
*/
enum ErrorHandling ConsoleOutput(struct ModeAndAnswers* ModeAndAnswersData);
/**
 * Print Error value to stdout
 * @param [in] ErrorCode code of error (enum ErrorHandling)
*/
void PrintErrorValue(ErrorHandling ErrorCode); 
/**
 * Print help information about programm
*/
void HelpOutput();

#endif // INPUT_OUTPUT_FUNC_H