/* Programm to solve quadratic equation */

#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

int main() 
{
    double a = NAN, b = NAN, c = NAN;      // coefficient of quadratic equation
    OutputMode OutputMode = ERROR;
    double* Answers;

    if (ConsoleInput(&a, &b, &c) == 3)
    {
        if (IsFinite(a) && IsFinite(b) && IsFinite(c))
            Answers = SolvingQuadraticEquation(a, b, c, &OutputMode);
        else
            printf("Coefficients not a number or infinity!\n");

        if (IsFinite(Answers[0]) && IsFinite(Answers[1]))
            ConsoleOutput(Answers, OutputMode);
        else
            printf("Answers are not a numbers or infinity!\n");
    }
    else
        printf("Try number is exceeded\n");

    printf("Programm done!\n");
    return 0;
}