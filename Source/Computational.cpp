/**
 * @file
 * @brief Sourse file of computational functions
*/
#include <stdio.h>
#include <math.h>
#include "StructAndEnums.h"
#include "Logger.h"
#include "Computational.h"
#include "math_utilits.h"

/* solving quadratic equation function */
enum ErrorHandling SolvingQuadraticEquation(struct ModeAndAnswers* ModeAndAnswersData)
{
    AddLogg();
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
    if (IsFinite(ModeAndAnswersData->Answers[0].Real) && IsFinite(ModeAndAnswersData->Answers[0].Complex)
     && IsFinite(ModeAndAnswersData->Answers[1].Real) && IsFinite(ModeAndAnswersData->Answers[1].Complex))
    {
        RETURN(NO_ERRORS);
    }
    OutputLogg_(ANSWERS_NOT_NUMBER, _LoggFile, NULL);
    return ANSWERS_NOT_NUMBER;
}

void TwoComplexSolutions(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = TWO_COMPLEX_SOLUTONS;
    ModeAndAnswersData->Answers[0].Real = ModeAndAnswersData->Answers[1].Real = (-Coeff[1])/(2*Coeff[0]);
    ModeAndAnswersData->Answers[0].Complex =   sqrt(-D)/(2*Coeff[0]);
    ModeAndAnswersData->Answers[1].Complex = -(sqrt(-D)/(2*Coeff[0]));
}

void TwoRealSolutions(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = TWO_REAL_SOLUTIONS;
    ModeAndAnswersData->Answers[0].Real = (-Coeff[1])/(2*Coeff[0]) + (sqrt(D)) / (2 * Coeff[0]);
    ModeAndAnswersData->Answers[1].Real = (-Coeff[1])/(2*Coeff[0]) - (sqrt(D)) / (2 * Coeff[0]);
    ModeAndAnswersData->Answers[0].Complex = ModeAndAnswersData->Answers[1].Complex = 0;
}

void OneRealSolution(const double* Coeff, const double D, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = ONE_REAL_SOLUTION;
    ModeAndAnswersData->Answers[0].Real =    ModeAndAnswersData->Answers[1].Real = (-Coeff[1] + (sqrt(D))) / (2 * Coeff[0]);
    ModeAndAnswersData->Answers[0].Complex = ModeAndAnswersData->Answers[1].Complex = 0;
}

void LineralEquation(const double* Coeff, struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = LINERAL_EQUATION;
    ModeAndAnswersData->Answers[0].Real =    ModeAndAnswersData->Answers[1].Real = (-Coeff[2])/Coeff[1];
    ModeAndAnswersData->Answers[0].Complex = ModeAndAnswersData->Answers[1].Complex = 0;
}

void NotEquation(struct ModeAndAnswers* ModeAndAnswersData)
{
    ModeAndAnswersData->OutputMode = NOT_EQUATION;
    ModeAndAnswersData->Answers[0].Real = ModeAndAnswersData->Answers[1].Real
    = ModeAndAnswersData->Answers[0].Complex = ModeAndAnswersData->Answers[1].Complex = 0;
}