/* Programm to solve quadratic equation */

#include <stdio.h>
#include "Prototypes.h"

int main(void) 
{
    double a, b, c;      // ratios of quadratic equation

    printf("Enter a b c ratios of quadratic equation\n");
    while (1)
    {
        if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
            printf("Please enter digital data\n");
        else
            break;
        ScipInput();
    }
        SolvingQuadraticEquation(a, b, c);

    printf("Programm done!\n");
}