/* Programm to solve quadratic equation */

#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

int main(void) 
{
    double a = NAN, b = NAN, c = NAN;      // ratios of quadratic equation
    int Mode = 0;
    double* Ans;

    if (ConsoleInput(&a, &b, &c) == 3)
    {
        Ans = SolvingQuadraticEquation(a, b, c, &Mode);
        ConsoleOutput(Ans, Mode);
    }
    else
        printf("Try number is exceeded\n");

    printf("Programm done!\n");
}