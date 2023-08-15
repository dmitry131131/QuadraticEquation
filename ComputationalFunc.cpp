/* Supporting functions file */
#include <stdio.h>
#include <math.h>
#include "Prototypes.h"

/* solving quadratic equation function */
void SolvingQuadraticEquation(double a, double b, double c)
{
    double D;     // Discriminant

    if (fabs(a - 0) > 0.000001)
    {
        D = (b * b) - (4 * a * c);
        if (D < 0)
        {
            printf("Equation has not got real solution\n"
                    "Complex solutions:\n"
                    "Real part   Imaginary part\n");
            printf("%-11.4lf %.4lf\n", (-b)/(2*a), sqrt(-D)/(2*a));
            printf("%-11.4lf %.4lf\n", (-b)/(2*a), -(sqrt(-D))/(2*a));
        }
        else if (D > 0)
        {
            printf("Equation has two real solution\n");
            printf("First solution: %.4lf\n", (-b + (sqrt(D))) / (2 * a));
            printf("Second solution: %.4lf\n", (-b - (sqrt(D))) / (2 * a));
        }
        else
        {
            printf("Equation has one real solution\n");
            printf("Solution is: %.4lf\n", ((-b) + sqrt(D)) / (2 * a));
        }
    }

    else if (fabs(b - 0) > 0.000001)
    {
        printf("This is not quadratic equation\n"
                "But solution of linear equation is: %.4lf\n", (-c)/b);
    }

    else
    {
        printf("This is not equation:\n"
                "a and b ratios mustn't be 0\n");
    }
}

void ScipInput()
{
    char ch;           // trash variable to skip trash simbols from stdin flow
    while ((ch = (char) getchar()) != '\n')
        ;         // empty operator
}
