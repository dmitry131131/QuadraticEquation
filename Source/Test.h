/**
 * @file
 * @brief Prototypes of test functions
*/

/**
 * @param [in] filename name of test data file
 * @return Error code
*/
enum ErrorHandling Tester(const int argc, char* argv[]);
/**
 * @param [in] file File with test data
 * @return Error Code
*/
enum ErrorHandling TestMode(FILE* file);
