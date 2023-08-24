/**
 * @file
 * @brief file with test func
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "StructAndEnums.h"
#include "InputOutput.h"
#include "Computational.h"
#include "MainMode.h"
#include "math_utilits.h"
#include "Test.h"

enum ErrorHandling Tester(const int argc, char* argv[])
{
    enum ErrorHandling ErrorCode = NO_ERRORS;

    for (int i = 1; i < argc; i++)
    {

        FILE* file = NULL;

        if (!strcmp(argv[i], "-t"))
        {
            if (argc >= i)
            {
                file = fopen(argv[i + 1], "r");
            }
        }
        else 
        {
            return INVALID_CONSOLE_ARG;
        }

        if (file != NULL)
        {
            printf("Test file: %s\n", argv[i + 1]);
            ErrorCode = TestMode(file);
            i++;
        }
        else
        {
            ErrorCode = FILE_NOT_OPENED;
        }
    }

    return ErrorCode;
}

enum ErrorHandling TestMode(FILE* file)
{
    struct ModeAndAnswers ModeAndAnswersData = {ERROR, {NAN, NAN, NAN}, {{NAN, NAN}, {NAN, NAN}}};
    enum ErrorHandling ErrorCode = NO_ERRORS;

    while(!(ErrorCode = Input(ModeAndAnswersData.Coeff, file)))
    {
        if (!(ErrorCode = SolvingQuadraticEquation(&ModeAndAnswersData)))
        {   
            double Ans1[2] = {};
            double Ans2[2] = {};
            fscanf(file, "%lf %lf %lf %lf", &Ans1[0], &Ans1[1], &Ans2[0], &Ans2[1]);
            SkipInput(file);

            if (!(EqualityNumbers(ModeAndAnswersData.Answers[0].Real, Ans1[0])
            && EqualityNumbers(ModeAndAnswersData.Answers[0].Complex, Ans1[1])
            && EqualityNumbers(ModeAndAnswersData.Answers[1].Real, Ans2[0])
            && EqualityNumbers(ModeAndAnswersData.Answers[1].Complex, Ans2[1])))
            {
                printf("Test values are: real: %.4lf complex: %.4lf\n real: %.4lf complex: %.4lf\n\n",
                Ans1[0], Ans1[1], Ans2[0], Ans2[1]);
                printf("Test values are: real: %.4lf complex: %.4lf\n real: %.4lf complex: %.4lf\n\n",
                ModeAndAnswersData.Answers[0].Real, ModeAndAnswersData.Answers[0].Complex,
                ModeAndAnswersData.Answers[1].Real, ModeAndAnswersData.Answers[1].Complex);

                ErrorCode = TEST_FAILED;
                break;
            }

            else ErrorCode = NO_ERRORS;

        }
    }

    if (ErrorCode == FOUND_EOF_FILE)
    {
        return NO_ERRORS;
    }
    else
    {
        return ErrorCode;
    }
}
