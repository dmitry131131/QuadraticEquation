/* Computational functions file */
#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

/* solving quadratic equation function */
void SolvingQuadraticEquation(double a, double b, double c, struct ModeAndAnswers* ModeAndAnswersData)
{
    double D = NAN;     // Discriminant  

    if (!IsZero(a))
    {
        D = (b * b) - (4 * a * c);
        if (D < 0)
        {
            /* Two complex solutions */
            ModeAndAnswersData->OutputMode = TWO_COMPLEX_SOLUTONS;
            ModeAndAnswersData->Answers[0] = (-b)/(2*a);
            ModeAndAnswersData->Answers[1] = sqrt(-D)/(2*a);
        }
        else if (D > 0)
        {
            /* Two real solutions */
            ModeAndAnswersData->OutputMode = TWO_REAL_SOLUTIONS;
            ModeAndAnswersData->Answers[0] = (-b)/(2*a);
            ModeAndAnswersData->Answers[1] = (sqrt(D)) / (2 * a);
        }
        else
        {
            /* One real solution */
            ModeAndAnswersData->OutputMode = ONE_REAL_SOLUTION;
            ModeAndAnswersData->Answers[0] = ModeAndAnswersData->Answers[1] = (-b + (sqrt(D))) / (2 * a);
        }
    }

    else if (!IsZero(b))
    {
        /* Lineral equation */
        ModeAndAnswersData->OutputMode = LINERAL_EQUATION;
        ModeAndAnswersData->Answers[0] = ModeAndAnswersData->Answers[1] = (-c)/b;
    }

    else
    {
        /* Not equation */
        ModeAndAnswersData->OutputMode = NOT_EQUATION;
        ModeAndAnswersData->Answers[0] = ModeAndAnswersData->Answers[1] = 0;
    }
}

int IsFinite(double number)
{
    return !isnan(number) && !isinf(number);
}

int IsZero(double number)
{
    return !(fabs(number) > MIN_DOUBLE_VALUE);
}