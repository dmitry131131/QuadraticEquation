/**
 * @file
 * @brief Prototypes and preprocessor dirictives file 
 * 
 * In this file prototypes of computational functions
*/
#ifndef COMPUTANIONAL_FUNC_H
#define COMPUTANIONAL_FUNC_H
/**
 * Solving finction prototype
 * @param [in] a first coefficient of quadratic equation
 * @param [in] b second coefficient of quadratic equation
 * @param [in] c third coefficient of quadratic equation
 * @param [out] ModeAndAnswersData output data structure
*/
void SolvingQuadraticEquation(struct ModeAndAnswers* ModeAndAnswersData);
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
/**
 * Returns two complex solutions
 * @param [in] a first coefficient of quadratic equation
 * @param [in] b second coefficient of quadratic equation
 * @param [in] D discriminant of quadratic equation
 * @param [out] ModeAndAnswersData output data structure
*/
void TwoComplexSolutions(const double* Coeff, double D, struct ModeAndAnswers* ModeAndAnswersData); // Two complex solutions 
/**
 * Returns two real solutions
 * @param [in] a first coefficient of quadratic equation
 * @param [in] b second coefficient of quadratic equation
 * @param [in] D discriminant of quadratic equation
 * @param [out] ModeAndAnswersData output data structure
*/
void TwoRealSolutions(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData); 
/**
 * Returns one real solution
 * @param [in] a first coefficient of quadratic equation
 * @param [in] b second coefficient of quadratic equation
 * @param [in] D discriminant of quadratic equation
 * @param [out] ModeAndAnswersData output data structure
*/
void OneRealSolution(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData);
/**
 * Returns solution of lineral equation
 * @param [in] b second coefficient of quadratic equation
 * @param [in] c third coefficient of quadratic equation
 * @param [out] ModeAndAnswersData output data structure
*/
void LineralEquation(const double* Coeff, struct ModeAndAnswers* ModeAndAnswersData); // Lineral equation
/** 
 * Returns data in case not equation
 * @param [out] ModeAndAnswersData output data structure
*/
void NotEquation(struct ModeAndAnswers* ModeAndAnswersData);

#endif // COMPUTANIONAL_FUNC_H
