/* Supporting functions file */
#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

/* solving quadratic equation function */
double* SolvingQuadraticEquation(double a, double b, double c, int* Mode)
{
    double D = NAN;     // Discriminant
    static double Answers[] = {NAN, NAN};    

    if (fabs(a - 0) > 0.000001)
    {
        D = (b * b) - (4 * a * c);
        if (D < 0)
        {
            /*
            printf("Equation has not got real solution\n"
                   "Complex solutions:\n"
                   "Real part   Imaginary part\n");
            printf("%-11.4lf %.4lf\n", (-b)/(2*a), sqrt(-D)/(2*a));
            printf("%-11.4lf %.4lf\n", (-b)/(2*a), -(sqrt(-D))/(2*a));
            */
           *Mode = 5;
           Answers[0] = (-b)/(2*a);
           Answers[1] = sqrt(-D)/(2*a);
        }
        else if (D > 0)
        {
            /*
            printf("Equation has two real solution\n");
            printf("First solution: %.4lf\n", (-b + (sqrt(D))) / (2 * a));
            printf("Second solution: %.4lf\n", (-b - (sqrt(D))) / (2 * a));
            */
           *Mode = 4;
           Answers[0] = (-b + (sqrt(D))) / (2 * a);
           Answers[1] = (-b - (sqrt(D))) / (2 * a);
        }
        else
        {
            /*
            printf("Equation has one real solution\n");
            printf("Solution is: %.4lf\n", ((-b) + sqrt(D)) / (2 * a));
            */
           *Mode = 3;
           Answers[0] = (-b + (sqrt(D))) / (2 * a);
        }
    }

    else if (fabs(b - 0) > 0.000001)
    {
        /*
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n", (-c)/b);
        */
       *Mode = 2;
       Answers[0] = (-c)/b;
    }

    else
    {
        /*
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n");
        */ 
       *Mode = 1;
    }

    return Answers;
}
