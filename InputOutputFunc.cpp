/* Input and output functions */
#include <stdio.h>
#include "ComputationalFunc.h"

void ScipInput()
{
    char ch;           // trash variable to skip trash simbols from stdin flow
    while ((ch = (char) getchar()) != '\n')
        ;         // empty operator
}

int ConsoleInput(double *a, double *b, double *c)
{
    printf("Enter a b c ratios of quadratic equation\n");
    for (int i = 0; i < 10; i++)
    {
        if (scanf("%lf %lf %lf", a, b, c) == 3) return 3;
        printf("Please enter digital data\n");
        ScipInput();
    }
    return 0;
}

void ConsoleOutput(double* Out, int Mode)
{
    if (Mode == 1)
    {
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n");
    }

    else if (Mode == 2)
    {
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n", Out[0]);
    }

    else if (Mode == 3)
    {
        printf("Equation has one real solution\n");
        printf("Solution is: %.4lf\n", Out[0]);
    }

    else if (Mode == 4)
    {
        printf("Equation has two real solution\n");
        printf("First solution: %.4lf\n", Out[0]);
        printf("Second solution: %.4lf\n", Out[1]);
    }

    else if (Mode == 5)
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

