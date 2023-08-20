/* Computational functions file */
#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

/* solving quadratic equation function */
double* SolvingQuadraticEquation(double a, double b, double c, OutputMode* OutputMode)
{
    double D = NAN;     // Discriminant
    static double Answers[] = {NAN, NAN};    

    if (!IsZero(a))
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
            Answers[0] = (-b)/(2*a);
            Answers[1] = (sqrt(D)) / (2 * a);
        }
        else
        {
            /* One real solution */
            *OutputMode = ONE_REAL_SOLUTION;
            Answers[0] = Answers[1] = (-b + (sqrt(D))) / (2 * a);
        }
    }

    else if (!IsZero(b))
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
    return !isnan(number) && !isinf(number);
}

int IsZero(double number)
{
    return !(fabs(number) > MIN_DOUBLE_VALUE);
}