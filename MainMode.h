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
enum ErrorHandling MainMode(FILE* file);
