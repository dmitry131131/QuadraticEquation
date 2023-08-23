/**
 * @file
 * @brief Prototypes of large functions in main file 
 * Realised programm modes 
*/

/**
 * Function realise console input of 3 coefficients, data struct and console output solutions of quadratic equations
 * @param [out] a first coefficient of quadratic equation
 * @param [out] b second coefficient of quadratic equation
 * @param [out] c third coefficient of quadratic equation
 * @param [in,out] ModeAndAnswersData data struct with output mode and roots of quadratic equation
 * @return error code or NO_ERRORS
*/
enum ErrorHandling ConsoleInputConsoleOutput(double* a, double* b, double*c, struct ModeAndAnswers* ModeAndAnswersData);
/**
 * Function realise one row file input of 3 first coefficients and console output solutions of quadratic equations
 * @param [out] a first coefficient of quadratic equation
 * @param [out] b second coefficient of quadratic equation
 * @param [out] c third coefficient of quadratic equation
 * @param [in,out] ModeAndAnswersData data struct with output mode and roots of quadratic equation
 * @param [in] file filename with input data
 * @return error code or NO_ERRORS 
*/
enum ErrorHandling FileOneInputConsoleOutput(double* a, double* b, double* c, struct ModeAndAnswers* ModeAndAnswersData, FILE* file);
/**
 * Function realise many rows file input of 3 first coefficients and console output solutions of quadratic equations, until input 
 * found End Of File
 * @param [out] a first coefficient of quadratic equation
 * @param [out] b second coefficient of quadratic equation
 * @param [out] c third coefficient of quadratic equation
 * @param [in,out] ModeAndAnswersData data struct with output mode and roots of quadratic equation
 * @param [in] file filename with input data
 * @return error code or NO_ERRORS 
*/
enum ErrorHandling FileManyInputConsoleOutput(double* a, double* b, double* c, struct ModeAndAnswers* ModeAndAnswersData, FILE* file);
/**
 * Function realise unit tests SolvingQuadraticEquation() function
 * @param [out] a first coefficient of quadratic equation
 * @param [out] b second coefficient of quadratic equation
 * @param [out] c third coefficient of quadratic equation
 * @param [in,out] ModeAndAnswersData data struct with output mode and roots of quadratic equation
 * @param [in] file filename with input data
 * @return error code or NO_ERRORS 
*/
enum ErrorHandling SolvingFuncUnitTest(double* a, double* b, double* c, struct ModeAndAnswers* ModeAndAnswersData, FILE* file, char* argv);
