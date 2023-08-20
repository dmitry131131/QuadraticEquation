/* Computational functions file */
#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

/* solving quadratic equation function */
double* SolvingQuadraticEquation(double a, double b, double c, OutputMode* OutputMode)
{
    double D = NAN;     // Discriminant
    static double Answers[] = {NAN, NAN};    

    if (IsZero(a) == 0)
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
           *OutputMode = TWO_COMPLEX_SOLUTONS;
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
           *OutputMode = TWO_REAL_SOLUTIONS;
           Answers[0] = (-b + (sqrt(D))) / (2 * a);
           Answers[1] = (-b - (sqrt(D))) / (2 * a);
        }
        else
        {
            /*
            printf("Equation has one real solution\n");
            printf("Solution is: %.4lf\n", ((-b) + sqrt(D)) / (2 * a));
            */
           *OutputMode = ONE_REAL_SOLUTION;
           Answers[0] = Answers[1] = (-b + (sqrt(D))) / (2 * a);
        }
    }

    else if (IsZero(b) == 0)
    {
        /*
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n", (-c)/b);
        */
       *OutputMode = LINERAL_EQUATION;
       Answers[0] = Answers[1] = (-c)/b;
    }

    else
    {
        /*
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n");
        */ 
       *OutputMode = NOT_EQUATION;
       Answers[0] = Answers[1] = 0;
    }

    return Answers;
}

int IsFinite(double number)
{
    if (isnan(number) || isinf(number))
        return 0;
    return 1;
}

int IsZero(double number)
{
    if (fabs(number) > MIN_DOUBLE_VALUE)
        return 0;
    else
        return 1;
}