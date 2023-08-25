/**
 * @file
 * @brief File with large functions for main file
 * Realised programm modes
*/
#include <stdio.h>
#include <math.h>

#include "config.h"
#include "StructAndEnums.h"
#include "Logger.h"
#include "InputOutput.h"
#include "Computational.h"
#include "MainMode.h"
#include "math_utilits.h"

enum ErrorHandling MainMode(FILE* file)
{
    AddLogg();

    struct ModeAndAnswers ModeAndAnswersData = {{{NAN, NAN}, {NAN, NAN}}, {NAN, NAN, NAN}, INPUT_ERROR};
    enum ErrorHandling ErrorCode = NO_ERRORS;

    if (!(ErrorCode = Input(ModeAndAnswersData.Coeff, file)))
    {
        if (!(ErrorCode = SolvingQuadraticEquation(&ModeAndAnswersData)))
        {
            ErrorCode = ConsoleOutput(&ModeAndAnswersData);
            SkipInput(file);
        }
    }

    RETURN(ErrorCode);
}
