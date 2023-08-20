/* Input and output functions */
#include <stdio.h>
#include "ComputationalFunc.h"

void ScipInput()
{
    while ((getchar()) != '\n') {}
}

int ConsoleInput(double* a, double* b, double* c)
{
    int log = 0;
    printf("Enter a b c ratios of quadratic equation\n");
    for (int i = 0; i < 10; i++)
    {
        log = scanf("%lf %lf %lf", a, b, c);

        if (log == 3) return 3;

        if (log == EOF) 
            printf("Input error!\n");

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
        printf("Output error!\n");
}
