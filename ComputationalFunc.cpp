/**
 * @file
 * @brief Sourse file of computational functions
*/
#include <stdio.h>
#include <math.h>
#include "StructAndEnums.h"
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
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = (-b)/(2*a);
    ModeAndAnswersData->Answer1[1] = sqrt(-D)/(2*a);
    ModeAndAnswersData->Answer2[1] = -(sqrt(-D)/(2*a));
}

void TwoRealSolutions(const double a, const double b, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = TWO_REAL_SOLUTIONS;
    ModeAndAnswersData->Answer1[0] = (-b)/(2*a) + (sqrt(D)) / (2 * a);
    ModeAndAnswersData->Answer2[0] = (-b)/(2*a) - (sqrt(D)) / (2 * a);
    ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}

void OneRealSolution(const double a, const double b, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = ONE_REAL_SOLUTION;
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = (-b + (sqrt(D))) / (2 * a);
    ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}

void LineralEquation(const double b, const double c, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = LINERAL_EQUATION;
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = (-c)/b;
    ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}

void NotEquation(struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = NOT_EQUATION;
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}