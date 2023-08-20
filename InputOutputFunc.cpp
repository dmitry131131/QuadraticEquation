/* Input and output functions */
#include <stdio.h>
#include <stdlib.h>
#include "ComputationalFunc.h"

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
                PrintErrorValue(FOUND_EOF_STDIN);
                break;
            }

        printf("Please enter digital data\n");
        ScipInput();
    }

    return 0;
}

void ConsoleOutput(double* Out, OutputMode Mode)
{
    switch (Mode)
    {
    case NOT_EQUATION:
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n");
        break;

    case LINERAL_EQUATION:
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n", Out[0]);
        break;

    case ONE_REAL_SOLUTION:
        printf("Equation has one real solution\n");
        printf("Solution is: %.4lf\n", Out[0]);
        break;

    case TWO_REAL_SOLUTIONS:
        printf("Equation has two real solution\n");
        printf("First solution: %.4lf\n", Out[0] + Out[1]);
        printf("Second solution: %.4lf\n", Out[0] - Out[1]);
        break;

    case TWO_COMPLEX_SOLUTONS:
        printf("Equation has not got real solution\n"
               "Complex solutions:\n"
               "Real part   Imaginary part\n");
        printf("%-11.4lf %.4lf\n", Out[0], Out[1]);
        printf("%-11.4lf %.4lf\n", Out[0], -Out[1]);
        break;
    
    case ERROR:
        PrintErrorValue(OUTPUT_ERROR);
        break;

    default:
        PrintErrorValue(OUTPUT_ERROR);
        break;
    }
}

void PrintErrorValue(ErrorHandling ErrorCode)
{
    switch (ErrorCode)
    {
    case NO_ERRORS:
        printf("Programm done successfully!\n");
        exit(EXIT_SUCCESS);
        break;

    case COEFFICIENTS_NOT_NUMBER:
        printf("Coefficients not a number or infinity!\n");
        exit(EXIT_FAILURE);
        break;

    case ANSWERS_NOT_NUMBER:
        printf("Answers are not a numbers or infinity!\n");
        exit(EXIT_FAILURE);
        break;
    
    case EXCEEDED_INPUT_LIMIT:
        printf("Try number is exceeded\n");
        exit(EXIT_FAILURE);
        break;

    case FOUND_EOF_STDIN:
        printf("Found EOF in stdin flow\n");
        exit(EXIT_FAILURE);
        break;
    case OUTPUT_ERROR:
        printf("Output error!\n");
        exit(EXIT_FAILURE);
        break;
    
    default:
        break;
    }
}
