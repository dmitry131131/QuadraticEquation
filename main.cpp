/* Programm to solve quadratic equation */

#include <stdio.h>
#include <math.h>
#include "ComputationalFunc.h"

ErrorHandling ErrorCode = NO_ERRORS;

int main() 
{
    double a = NAN, b = NAN, c = NAN;      // coefficient of quadratic equation
    OutputMode OutputMode = ERROR;
    double* Answers;

    if (ConsoleInput(&a, &b, &c) == 3)
    {
        if (IsFinite(a) && IsFinite(b) && IsFinite(c))
            Answers = SolvingQuadraticEquation(a, b, c, &OutputMode);
        else
            ErrorCode = COEFFICIENTS_NOT_NUMBER;

        if (IsFinite(Answers[0]) && IsFinite(Answers[1]))
            ConsoleOutput(Answers, OutputMode);
        else
            ErrorCode = ANSWERS_NOT_NUMBER;
    }
    else
        ErrorCode = EXCEEDED_INPUT_LIMIT;

    ProgrammEnding();
    return 0;
}