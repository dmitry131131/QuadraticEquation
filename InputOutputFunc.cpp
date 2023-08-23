/**
 * @file
 * @brief Sourse file with input/output functions
*/
#include <stdio.h>
#include <stdlib.h>
#include "StructAndEnums.h"
#include "InputOutputFunc.h"
#include "ComputationalFunc.h"

void ScipInput(FILE* flow)
{
    while ((getc(flow)) != '\n') {}
}

enum ErrorHandling ConsoleInput(double* Coeff)
{
    int log = 0;
    printf("Enter a b c ratios of quadratic equation\n");
    for (int i = 0; i < MAX_INPUT_COUNT; i++)
    {
        log = scanf("%lf %lf %lf", &Coeff[0], &Coeff[1], &Coeff[2]);

        if (log == 3) return NO_ERRORS;

        if (log == EOF)
            {
                PrintErrorValue(FOUND_EOF_STDIN, __func__);
                return FOUND_EOF_STDIN;
                break;
            }

        printf("Please enter digital data\n");
        ScipInput(stdin);
    }

    PrintErrorValue(EXCEEDED_INPUT_LIMIT, __func__);
    return EXCEEDED_INPUT_LIMIT;
}

enum ErrorHandling ConsoleOutput(struct ModeAndAnswers* const ModeAndAnswersData)
{
    switch (ModeAndAnswersData->OutputMode)
    {
    case NOT_EQUATION:
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n\n");
        break;

    case LINERAL_EQUATION:
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n\n", ModeAndAnswersData->Answers[0][0]);
        break;

    case ONE_REAL_SOLUTION:
        printf("Equation has one real solution\n");
        printf("Solution is: %.4lf\n\n", ModeAndAnswersData->Answers[0][0]);
        break;

    case TWO_REAL_SOLUTIONS:
        printf("Equation has two real solution\n");
        printf("First solution: %.4lf\n", ModeAndAnswersData->Answers[0][0]);
        printf("Second solution: %.4lf\n\n", ModeAndAnswersData->Answers[1][0]);
        break;

    case TWO_COMPLEX_SOLUTONS:
        printf("Equation has not got real solution\n"
               "Complex solutions:\n"
               "Real part   Imaginary part\n");
        printf("%-11.4lf %.4lf\n", ModeAndAnswersData->Answers[0][0], ModeAndAnswersData->Answers[0][1]);
        printf("%-11.4lf %.4lf\n\n", ModeAndAnswersData->Answers[1][0], ModeAndAnswersData->Answers[1][1]);
        break;

    case ERROR:
        PrintErrorValue(CONSOLE_OUTPUT_ERROR, __func__);
        return CONSOLE_OUTPUT_ERROR;
        break;

    default:
        PrintErrorValue(CONSOLE_OUTPUT_ERROR, __func__);
        return CONSOLE_OUTPUT_ERROR;
        break;
    }

    return NO_ERRORS;
}

void PrintErrorValue(ErrorHandling ErrorCode, const char* func)
{
    switch (ErrorCode)
    {
    case NO_ERRORS:
        printf("Programm done successfully!\n\n");
        break;

    case COEFFICIENTS_NOT_NUMBER:
        printf( "Coefficients not a number or infinity!\n"
                "Function: %s\n\n", func);
        break;

    case ANSWERS_NOT_NUMBER:
        printf( "Answers are not a numbers or infinity!\n"
                "Function: %s\n\n", func);
        break;

    case EXCEEDED_INPUT_LIMIT:
        printf( "Try number is exceeded!\n"
                "Function: %s\n\n", func);
        break;

    case FOUND_EOF_STDIN:
        printf( "Found EOF in stdin flow\n"
                "Function: %s\n\n", func);
        break;

    case CONSOLE_OUTPUT_ERROR:
        printf( "Output error!\n"
                "Function: %s\n\n", func);
        break;

    case FILE_NOT_OPENED:
        printf( "File not found\n"
                "Function: %s\n\n", func);
        break;

    case FILE_INPUT_ERROR:
        printf( "Invalid data in file!\n"
                "Function: %s\n\n", func);
        break;

    case FOUND_EOF_FILE:
        printf( "Found EOF in file!\n"
                "Function: %s\n\n", func);
        break;

    case CLOSE_FILE_ERROR:
        printf( "Can't close file!\n"
                "Function: %s\n\n", func);
        break;

    case TOO_MANY_CONSOLE_ARG:
        printf("Too many arguments in console\n\n");
        break;

    case INVALID_CONSOLE_ARG:
        printf("Invalid third argument!\n\n");
        break;

    default:
        break;
    }
}

enum ErrorHandling FileInput(double* Coeff, FILE* file)
{
    int log = fscanf(file, "%lf %lf %lf", &Coeff[0], &Coeff[1], &Coeff[2]);
    if (log == 3)
    {  
        return NO_ERRORS;
    }
    else if (log == EOF)
    {
        PrintErrorValue(FOUND_EOF_FILE, __func__);
        return FOUND_EOF_FILE;
    }
    else
    {
        PrintErrorValue(COEFFICIENTS_NOT_NUMBER, __func__);
        return COEFFICIENTS_NOT_NUMBER;
    }
}

void HelpOutput()
{
    printf( "# Programm to solve quadratic equation\n"
            "\n"
            "# empty flag  -- console input and console output\n"
            "Enter a b c decimal coefficients separated by a space"
            "# filename    -- input first 3 numbers from file and output solutions to console\n\n"
            "# filename m  -- input first 3 numbers in row from and output solutions to console\n"
            "programm works until End Of File\n\n"
            "# filename t  -- test mode:\n"
            "programm read first 3 numbers, solve equation and compare roots with roots in file\n"
            "a b c  real1 complex1 real2 complex2\n"
            "a, b, c - decimal coefficient\n"
            "real1, real2 - real parts of first and second answers\n"
            "complex1, complex2 - complex parts of first and second answers\n\n");
}
