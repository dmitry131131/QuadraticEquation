/**
 * @file
 * @brief Sourse file of computational functions
*/
#include <stdio.h>
#include <math.h>
#include "StructAndEnums.h"
#include "ComputationalFunc.h"

/* solving quadratic equation function */
void SolvingQuadraticEquation(struct ModeAndAnswers* ModeAndAnswersData)
{
    double D = NAN;     // Discriminant  

    if (!IsZero(ModeAndAnswersData->Coeff[0]))
    {
        D = (pow(ModeAndAnswersData->Coeff[1], 2)) - (4 * ModeAndAnswersData->Coeff[0] * ModeAndAnswersData->Coeff[2]);
        if (D < 0)
        {
            /* Two complex solutions */
            TwoComplexSolutions(ModeAndAnswersData->Coeff, D, ModeAndAnswersData);
        }
        else if (D > 0)
        {
            /* Two real solutions */
            TwoRealSolutions(ModeAndAnswersData->Coeff, D, ModeAndAnswersData);
        }
        else
        {
            /* One real solution */
            OneRealSolution(ModeAndAnswersData->Coeff, D, ModeAndAnswersData);
        }
    }

    else if (!IsZero(ModeAndAnswersData->Coeff[1]))
    {
        /* Lineral equation */
        LineralEquation(ModeAndAnswersData->Coeff, ModeAndAnswersData);
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

void TwoComplexSolutions(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = TWO_COMPLEX_SOLUTONS;
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = (-Coeff[1])/(2*Coeff[0]);
    ModeAndAnswersData->Answer1[1] = sqrt(-D)/(2*Coeff[0]);
    ModeAndAnswersData->Answer2[1] = -(sqrt(-D)/(2*Coeff[0]));
}

void TwoRealSolutions(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = TWO_REAL_SOLUTIONS;
    ModeAndAnswersData->Answer1[0] = (-Coeff[1])/(2*Coeff[0]) + (sqrt(D)) / (2 * Coeff[0]);
    ModeAndAnswersData->Answer2[0] = (-Coeff[1])/(2*Coeff[0]) - (sqrt(D)) / (2 * Coeff[0]);
    ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}

void OneRealSolution(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = ONE_REAL_SOLUTION;
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = (-Coeff[1] + (sqrt(D))) / (2 * Coeff[0]);
    ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}

void LineralEquation(const double* Coeff, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = LINERAL_EQUATION;
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = (-Coeff[2])/Coeff[1];
    ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}

void NotEquation(struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = NOT_EQUATION;
    ModeAndAnswersData->Answer1[0] = ModeAndAnswersData->Answer2[0] = ModeAndAnswersData->Answer1[1] = ModeAndAnswersData->Answer2[1] = 0;
}