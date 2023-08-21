/* Programm to solve quadratic equation */

#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

int main() 
{
    double a = NAN, b = NAN, c = NAN;      // coefficient of quadratic equation

    struct ModeAndAnswers ModeAndAnswersData = {ERROR, {NAN, NAN}};

    if (ConsoleInput(&a, &b, &c) == 3)
    {
        if (!(IsFinite(a) && IsFinite(b) && IsFinite(c)))
            PrintErrorValue(COEFFICIENTS_NOT_NUMBER);
        else
            SolvingQuadraticEquation(a, b, c, &ModeAndAnswersData);

        if (IsFinite(ModeAndAnswersData.Answers[0]) && IsFinite(ModeAndAnswersData.Answers[1]))
            ConsoleOutput(&ModeAndAnswersData);
        else
            PrintErrorValue(ANSWERS_NOT_NUMBER);
    }
    else
        PrintErrorValue(EXCEEDED_INPUT_LIMIT);

    return 0;
}