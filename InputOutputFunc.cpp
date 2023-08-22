/* Input and output functions */
#include <stdio.h>
#include <stdlib.h>
#include "ComputationalFunc.h"

void ScipInput(FILE* flow)
{
    while ((getc(flow)) != '\n') {}
}

enum ErrorHandling ConsoleInput(double* a, double* b, double* c)
{
    int log = 0;
    printf("Enter a b c ratios of quadratic equation\n");
    for (int i = 0; i < MAX_INPUT_COUNT; i++)
    {
        log = scanf("%lf %lf %lf", a, b, c);

        if (log == 3) return NO_ERRORS;

        if (log == EOF)
            {
                PrintErrorValue(FOUND_EOF_STDIN);
                return FOUND_EOF_STDIN;
                break;
            }

        printf("Please enter digital data\n");
        ScipInput(stdin);
    }

    PrintErrorValue(EXCEEDED_INPUT_LIMIT);
    return EXCEEDED_INPUT_LIMIT;
}

enum ErrorHandling ConsoleOutput(struct ModeAndAnswers* const ModeAndAnswersData)
{
    switch (ModeAndAnswersData->OutputMode)
    {
    case NOT_EQUATION:
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n");
        break;

    case LINERAL_EQUATION:
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n", ModeAndAnswersData->Answer1[0]);
        break;

    case ONE_REAL_SOLUTION:
        printf("Equation has one real solution\n");
        printf("Solution is: %.4lf\n", ModeAndAnswersData->Answer1[0]);
        break;

    case TWO_REAL_SOLUTIONS:
        printf("Equation has two real solution\n");
        printf("First solution: %.4lf\n", ModeAndAnswersData->Answer1[0]);
        printf("Second solution: %.4lf\n", ModeAndAnswersData->Answer2[0]);
        break;

    case TWO_COMPLEX_SOLUTONS:
        printf("Equation has not got real solution\n"
               "Complex solutions:\n"
               "Real part   Imaginary part\n");
        printf("%-11.4lf %.4lf\n", ModeAndAnswersData->Answer1[0], ModeAndAnswersData->Answer1[1]);
        printf("%-11.4lf %.4lf\n", ModeAndAnswersData->Answer2[0], ModeAndAnswersData->Answer2[1]);
        break;

    case ERROR:
        PrintErrorValue(OUTPUT_ERROR);
        return OUTPUT_ERROR;
        break;

    default:
        PrintErrorValue(OUTPUT_ERROR);
        return OUTPUT_ERROR;
        break;
    }

    return NO_ERRORS;
}

void PrintErrorValue(ErrorHandling ErrorCode)
{
    switch (ErrorCode)
    {
    case NO_ERRORS:
        printf("Programm done successfully!\n");
        break;

    case COEFFICIENTS_NOT_NUMBER:
        printf("Coefficients not a number or infinity!\n");
        break;

    case ANSWERS_NOT_NUMBER:
        printf("Answers are not a numbers or infinity!\n");
        break;

    case EXCEEDED_INPUT_LIMIT:
        printf("Try number is exceeded\n");
        break;

    case FOUND_EOF_STDIN:
        printf("Found EOF in stdin flow\n");
        break;

    case OUTPUT_ERROR:
        printf("Output error!\n");
        break;

    case FILE_NOT_OPENED:
        printf("File not found\n");
        break;

    case FILE_INPUT_ERROR:
        printf("Invalid data in file!\n");
        break;

    case FOUND_EOF_FILE:
        printf("Found EOF in file!\n");
        break;

    case CLOSE_FILE_ERROR:
        printf("Can't close file!\n");
        break;

    case TOO_MANY_CONSOLE_ARG:
        printf("Too many arguments in console\n");
        break;

    case INVALID_CONSOLE_ARG:
        printf("Invalid third argument!\n");
        break;

    default:
        break;
    }
}

enum ErrorHandling FileInput(double* a, double* b, double* c, FILE* file)
{
    int log = fscanf(file, "%lf %lf %lf", a, b, c);
    if (log == 3)
    {  
        return NO_ERRORS;
    }
    else if (log == EOF)
    {
        PrintErrorValue(FOUND_EOF_FILE);
        return FOUND_EOF_FILE;
    }
    else
    {
        PrintErrorValue(COEFFICIENTS_NOT_NUMBER);
        return COEFFICIENTS_NOT_NUMBER;
    }
}
