/**
 * @file
 * @brief file with test func
*/

#include <stdio.h>
#include <math.h>
#include "StructAndEnums.h"
#include "InputOutput.h"
#include "Computational.h"
#include "MainMode.h"
#include "math_utilits.h"
#include "Test.h"

enum ErrorHandling Tester(const char* filename)
{
    FILE* file = fopen(filename, "r");
    enum ErrorHandling ErrorCode = NO_ERRORS;
    if (file == NULL)
    {
        return FILE_NOT_OPENED;
    }
    else 
    {
        printf("Test file: %s\n", filename);
        ErrorCode = TestMode(file);
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
                return FILE_INPUT_ERROR;
            }
        }
    }

    if (ErrorCode == FOUND_EOF_FILE)
        return NO_ERRORS;
    else
        return ErrorCode;
}
