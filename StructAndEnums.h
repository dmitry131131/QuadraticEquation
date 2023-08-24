/**
 * @file
 * @brief File with enums, structures and constants
*/
#ifndef STRUCT_AND_ENUMS_H
#define STRUCT_AND_ENUMS_H

/// @brief Enum to controle output mode of programm: 1 root, 2 roots, 2 complex roots... 
enum OutputMode {
    INPUT_ERROR = 0,                  ///< Indicates error in solving
    NOT_EQUATION = 1,           ///< Indicates that the numbers entered don't form an equation
    LINERAL_EQUATION = 2,       ///< Indicates that the numbers entered form lineral equation
    ONE_REAL_SOLUTION = 3,      ///< Indicates that entered equation has one real root
    TWO_REAL_SOLUTIONS = 4,     ///< Indicates that entered equation has two real roots
    TWO_COMPLEX_SOLUTONS = 5    ///< Indicates that entered equation has two complex roots
};

/// @brief Enum to controle error codes
enum ErrorHandling {
    NO_ERRORS = 0,                  ///< Programm hasn't errors
    COEFFICIENTS_NOT_NUMBER = 1,    ///< Entered coefficients are not numbers or infinity
    ANSWERS_NOT_NUMBER = 2,         ///< Answers are not numbers or infinity
    FOUND_EOF_STDIN = 3,            ///< Scanf found EOF in stdin flow
    CONSOLE_OUTPUT_ERROR = 4,       ///< Console output error 
    FILE_NOT_OPENED = 5,            ///< Entered invalid filename or function can't open file
    FILE_INPUT_ERROR = 6,           ///< File contains invalid data
    FOUND_EOF_FILE = 7,             ///< fscanf found EOF in file
    CLOSE_FILE_ERROR = 8,           ///< programm can't close the file
    INVALID_CONSOLE_ARG = 9,        ///< User entered invalid console arguments
    TEST_FAILED = 10                ///< Test failed in test mode 
};

/// @brief struct of 1 root
struct Root {
    double Real;        ///< Real part of root
    double Complex;     ///< Complex part of root
};

/// @brief structure contains Mode of output and two roots, coefficients of equation and answers
struct ModeAndAnswers {
    OutputMode OutputMode;     ///< enum OutputMode with mode of output
    double Coeff[3];           ///< coefficients array Coeff[0] - a, Coeff[1] - b, Coeff[2] - c
    struct Root Answers[2];    
};

#endif // STRUCT_AND_ENUMS_H