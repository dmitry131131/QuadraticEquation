/* Input and output functions */
#include <stdio.h>
#include "ComputationalFunc.h"

extern ErrorHandling ErrorCode;

void ScipInput()
{
    while ((getchar()) != '\n') {}
}

int ConsoleInput(double* a, double* b, double* c)
{
    int log = 0;
    printf("Enter a b c ratios of quadratic equation\n");
    for (int i = 0; i < MAX_INPUT_COUNT; i++)
    {
        log = scanf("%lf %lf %lf", a, b, c);

        if (log == 3) return 3;

        if (log == EOF) 
            {
                ErrorCode = FOUND_EOF_STDIN;
                break;
            }

        printf("Please enter digital data\n");
        ScipInput();
    }

    return 0;
}

void ConsoleOutput(double* Out, OutputMode Mode)
{
    if (Mode == NOT_EQUATION)
    {
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n");
    }

    else if (Mode == LINERAL_EQUATION)
    {
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n", Out[0]);
    }

    else if (Mode == ONE_REAL_SOLUTION)
    {
        printf("Equation has one real solution\n");
        printf("Solution is: %.4lf\n", Out[0]);
    }

    else if (Mode == TWO_REAL_SOLUTIONS)
    {
        printf("Equation has two real solution\n");
        printf("First solution: %.4lf\n", Out[0]);
        printf("Second solution: %.4lf\n", Out[1]);
    }

    else if (Mode == TWO_COMPLEX_SOLUTONS)
    {
        printf("Equation has not got real solution\n"
               "Complex solutions:\n"
               "Real part   Imaginary part\n");
        printf("%-11.4lf %.4lf\n", Out[0], Out[1]);
        printf("%-11.4lf %.4lf\n", Out[0], -Out[1]);
    }
    else
        ErrorCode = OUTPUT_ERROR;
}

void ProgrammEnding()
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
    
    default:
        break;
    }
}
