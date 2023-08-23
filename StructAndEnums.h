/**
 * @file
 * @brief File with enums, structures and constants
*/
#ifndef STRUCT_AND_ENUMS_H
#define STRUCT_AND_ENUMS_H

/// @brief Epsilon constant to compare two double numbers
const double MIN_DOUBLE_VALUE = 1.0e-4;
/// @brief Maximum count of attemps in console input
const int MAX_INPUT_COUNT = 5;

/// @brief Enum to controle output mode of programm: 1 root, 2 roots, 2 complex roots... 
enum OutputMode {
    ERROR = 0,                  ///< Indicates error in solving
    NOT_EQUATION = 1,           ///< Indicates that the numbers entered don't form an equation
    LINERAL_EQUATION = 2,       ///< Indicates that the numbers entered form lineral equation
    ONE_REAL_SOLUTION = 3,      ///< Indicates that entered equation has one real root
    TWO_REAL_SOLUTIONS = 4,     ///< Indicates that entered equation has two real roots
    TWO_COMPLEX_SOLUTONS = 5    ///< Indicates that entered equation has two complex roots
};

/// @brief Enum to controle error codes
enum ErrorHandling {
    NO_ERRORS = 0,                  ///< Programm hasn't errors
    EXCEEDED_INPUT_LIMIT = 1,       ///< Exeeded number of enter limit in console input
    COEFFICIENTS_NOT_NUMBER = 2,    ///< Entered coefficients are not numbers or infinity
    ANSWERS_NOT_NUMBER = 3,         ///< Answers are not numbers or infinity
    FOUND_EOF_STDIN = 4,            ///< Scanf found EOF in stdin flow
    CONSOLE_OUTPUT_ERROR = 5,       ///< Console output error 
    FILE_NOT_OPENED = 6,            ///< Entered invalid filename or function can't open file
    FILE_INPUT_ERROR = 7,           ///< File contains invalid data
    FOUND_EOF_FILE = 8,             ///< fscanf found EOF in file
    CLOSE_FILE_ERROR = 9,           ///< programm can't close the file
    TOO_MANY_CONSOLE_ARG = 10,      ///< User entered too many console arguments
    INVALID_CONSOLE_ARG = 11        ///< User entered invalid console arguments
};
/// @brief structure contains Mode of output and two roots, coefficients of equation and answers
struct ModeAndAnswers
{
    OutputMode OutputMode;     ///< enum OutputMode with mode of output
    double Coeff[3];           ///< coefficients array Coeff[0] - a, Coeff[1] - b, Coeff[2] - c
    double Answer1[2];         ///< first root array Answer1[0] - real part, Answer1[1] - complex part
    double Answer2[2];         ///< first root array Answer2[0] - real part, Answer2[1] - complex part
};

#endif // STRUCT_AND_ENUMS_H