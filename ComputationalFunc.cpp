/* Computational functions file */
#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

/* solving quadratic equation function */
void SolvingQuadraticEquation(const double a, const double b, const double c, struct ModeAndAnswers* ModeAndAnswersData)
{
    double D = NAN;     // Discriminant  

    if (!IsZero(a))
    {
        D = (b * b) - (4 * a * c);
        if (D < 0)
        {
            /* Two complex solutions */
            TwoComplexSolutions(a, b, D, ModeAndAnswersData);
        }
        else if (D > 0)
        {
            /* Two real solutions */
            TwoRealSolutions(a, b, D, ModeAndAnswersData);
        }
        else
        {
            /* One real solution */
            OneRealSolution(a, b, D, ModeAndAnswersData);
        }
    }

    else if (!IsZero(b))
    {
        /* Lineral equation */
        LineralEquation(b, c, ModeAndAnswersData);
    }

    else
    {
        /* Not equation */
        NotEquation(ModeAndAnswersData);
    }
}

int IsFinite(const double number)
{
    return !isnan(number) && !isinf(number);
}

int IsZero(const double number)
{
    return !(fabs(number) > MIN_DOUBLE_VALUE);
}

int EqualityNumbers(const double a, const double b)
{
    return !(fabs(a - b) > MIN_DOUBLE_VALUE);
}

void TwoComplexSolutions(const double a, const double b, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = TWO_COMPLEX_SOLUTONS;
    ModeAndAnswersData->Answers[0] = (-b)/(2*a);
    ModeAndAnswersData->Answers[1] = sqrt(-D)/(2*a);
}

void TwoRealSolutions(const double a, const double b, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = TWO_REAL_SOLUTIONS;
    ModeAndAnswersData->Answers[0] = (-b)/(2*a);
    ModeAndAnswersData->Answers[1] = (sqrt(D)) / (2 * a);
}

void OneRealSolution(const double a, const double b, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = ONE_REAL_SOLUTION;
    ModeAndAnswersData->Answers[0] = ModeAndAnswersData->Answers[1] = (-b + (sqrt(D))) / (2 * a);
}

void LineralEquation(const double b, const double c, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = LINERAL_EQUATION;
    ModeAndAnswersData->Answers[0] = ModeAndAnswersData->Answers[1] = (-c)/b;
}

void NotEquation(struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = NOT_EQUATION;
    ModeAndAnswersData->Answers[0] = ModeAndAnswersData->Answers[1] = 0;
}