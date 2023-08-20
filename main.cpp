/* Programm to solve quadratic equation */

#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

int main() 
{
    double a = NAN, b = NAN, c = NAN;      // coefficient of quadratic equation
    OutputMode OutputMode = ERROR;
    double* Answers;

    if (ConsoleInput(&a, &b, &c) == 3)
    {
        if (!(IsFinite(a) && IsFinite(b) && IsFinite(c)))
            PrintErrorValue(COEFFICIENTS_NOT_NUMBER);
        else
            Answers = SolvingQuadraticEquation(a, b, c, &OutputMode);

        if (IsFinite(Answers[0]) && IsFinite(Answers[1]))
            ConsoleOutput(Answers, OutputMode);
        else
            PrintErrorValue(ANSWERS_NOT_NUMBER);
    }
    else
        PrintErrorValue(EXCEEDED_INPUT_LIMIT);

    return 0;
}