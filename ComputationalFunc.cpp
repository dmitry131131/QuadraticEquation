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
            /* Two complex solutions */
            *OutputMode = TWO_COMPLEX_SOLUTONS;
            Answers[0] = (-b)/(2*a);
            Answers[1] = sqrt(-D)/(2*a);
        }
        else if (D > 0)
        {
            /* Two real solutions */
            *OutputMode = TWO_REAL_SOLUTIONS;
            Answers[0] = (-b + (sqrt(D))) / (2 * a);
            Answers[1] = (-b - (sqrt(D))) / (2 * a);
        }
        else
        {
            /* One real solution */
            *OutputMode = ONE_REAL_SOLUTION;
            Answers[0] = Answers[1] = (-b + (sqrt(D))) / (2 * a);
        }
    }

    else if (IsZero(b) == 0)
    {
        /* Lineral equation */
        *OutputMode = LINERAL_EQUATION;
        Answers[0] = Answers[1] = (-c)/b;
    }

    else
    {
        /* Not equation */
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