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
void ScipInput(FILE* flow);
/**
 * Console input of 3 double number
 * @param [out] a first number
 * @param [out] b second number
 * @param [out] c third number
 * @return Return error code or NO_ERRORS
*/
enum ErrorHandling ConsoleInput(double* a, double* b, double* c); 

/**
 * File input of 3 number
 * @param [out] a first number
 * @param [out] b second number
 * @param [out] c third number
 * @param [in] file name of input file
 * @return Return error code or NO_ERRORS
*/
enum ErrorHandling FileInput(double* a, double* b, double* c, FILE* file);
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