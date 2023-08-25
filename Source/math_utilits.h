/**
 * @file
 * @brief Prototypes with utilits func
*/

/**
 * Check nubmer is not infinity or NAN
 * @param [in] number checked value
 * @return True if number is finite and False if number is infinity
*/
int IsFinite(const double number);
/**
 * Check number != 0
 * @param [in] number checked value
 * @return True if number is zero and False if number is not zero
*/
int IsZero(const double number);
/**
 * Compare two numbers
 * @param [in] a first number
 * @param [in] b second number
 * @return True if a == b of False if a != b
*/
int EqualityNumbers(const double a, const double b); // a == b