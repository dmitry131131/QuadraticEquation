/**
 * @file
 * @brief File with large functions for main file
 * Realised programm modes
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "StructAndEnums.h"
#include "InputOutputFunc.h"
#include "ComputationalFunc.h"
#include "MainFuncModes.h"

enum ErrorHandling ConsoleInputConsoleOutput(struct ModeAndAnswers* ModeAndAnswersData)
{
    if (!ConsoleInput(ModeAndAnswersData->Coeff))
        {
            if (!(IsFinite(ModeAndAnswersData->Coeff[0]) && IsFinite(ModeAndAnswersData->Coeff[1]) && IsFinite(ModeAndAnswersData->Coeff[2])))
            {
                PrintErrorValue(COEFFICIENTS_NOT_NUMBER, __func__);
                return COEFFICIENTS_NOT_NUMBER;
            }
            else
            {
                SolvingQuadraticEquation(ModeAndAnswersData);
            }

            if (IsFinite(ModeAndAnswersData->Answer1[0]) && IsFinite(ModeAndAnswersData->Answer1[1])
            && IsFinite(ModeAndAnswersData->Answer2[0]) && IsFinite(ModeAndAnswersData->Answer2[1]))
            {
                ConsoleOutput(ModeAndAnswersData);
            }
            else
            {
                PrintErrorValue(ANSWERS_NOT_NUMBER, __func__);
                return ANSWERS_NOT_NUMBER;
            }
        }
    return NO_ERRORS;
}

enum ErrorHandling FileOneInputConsoleOutput(struct ModeAndAnswers* ModeAndAnswersData, FILE* file)
{
    if (!FileInput(ModeAndAnswersData->Coeff, file))
    {
        if (!(IsFinite(ModeAndAnswersData->Coeff[0]) && IsFinite(ModeAndAnswersData->Coeff[1]) && IsFinite(ModeAndAnswersData->Coeff[2])))
        {
            PrintErrorValue(COEFFICIENTS_NOT_NUMBER, __func__);
            return COEFFICIENTS_NOT_NUMBER;
        }
        else
        {
            SolvingQuadraticEquation(ModeAndAnswersData);
        }

        if (IsFinite(ModeAndAnswersData->Answer1[0]) && IsFinite(ModeAndAnswersData->Answer1[1])
        && IsFinite(ModeAndAnswersData->Answer2[0]) && IsFinite(ModeAndAnswersData->Answer2[1]))
        {
            ConsoleOutput(ModeAndAnswersData);
        }
        else
        {
            PrintErrorValue(ANSWERS_NOT_NUMBER, __func__);
            return ANSWERS_NOT_NUMBER;
        }
    }

    else
    {  
        PrintErrorValue(FILE_INPUT_ERROR, __func__);
        return FILE_INPUT_ERROR;
    }
    if (fclose(file) == EOF)
    {
        PrintErrorValue(CLOSE_FILE_ERROR, __func__);
        return CLOSE_FILE_ERROR;
    }
    return NO_ERRORS;
}

enum ErrorHandling FileManyInputConsoleOutput(struct ModeAndAnswers* ModeAndAnswersData, FILE* file)
{
    int count = 1;
    while (!FileInput(ModeAndAnswersData->Coeff, file))
    {
        printf("%d\n", count);
        if (!(IsFinite(ModeAndAnswersData->Coeff[0]) && IsFinite(ModeAndAnswersData->Coeff[1]) && IsFinite(ModeAndAnswersData->Coeff[2])))
        {
            PrintErrorValue(COEFFICIENTS_NOT_NUMBER, __func__);
            return COEFFICIENTS_NOT_NUMBER;
        }
        else
        {
            SolvingQuadraticEquation(ModeAndAnswersData);
        }

        if (IsFinite(ModeAndAnswersData->Answer1[0]) && IsFinite(ModeAndAnswersData->Answer1[1])
        && IsFinite(ModeAndAnswersData->Answer2[0]) && IsFinite(ModeAndAnswersData->Answer2[1]))
        {
            ConsoleOutput(ModeAndAnswersData);
        }
        else
        {
            PrintErrorValue(ANSWERS_NOT_NUMBER, __func__);
            return ANSWERS_NOT_NUMBER;
        }
                    
        ScipInput(file);           
        count++;
    }
                
    if (fclose(file) == EOF)
    {
        PrintErrorValue(CLOSE_FILE_ERROR, __func__);
        return CLOSE_FILE_ERROR;
    }
    return NO_ERRORS;
}

enum ErrorHandling SolvingFuncUnitTest(struct ModeAndAnswers* ModeAndAnswersData, FILE* file, char* argv)
{
    int count = 1;
    bool flag = true;
    while (!FileInput(ModeAndAnswersData->Coeff, file))
    {
        if (!(IsFinite(ModeAndAnswersData->Coeff[0]) && IsFinite(ModeAndAnswersData->Coeff[1]) && IsFinite(ModeAndAnswersData->Coeff[2])))
        {
            PrintErrorValue(COEFFICIENTS_NOT_NUMBER, __func__);
            return COEFFICIENTS_NOT_NUMBER;
        }
        else
        {
            SolvingQuadraticEquation(ModeAndAnswersData);
        }

        double Ans1[2] = {0, 0}, Ans2[2] = {0, 0};
        fscanf(file, "%lf %lf %lf %lf", &Ans1[0], &Ans1[1], &Ans2[0], &Ans2[1]);
        ScipInput(file);

        if (!(EqualityNumbers(ModeAndAnswersData->Answer1[0], Ans1[0])
        && EqualityNumbers(ModeAndAnswersData->Answer1[1], Ans1[1])
        && EqualityNumbers(ModeAndAnswersData->Answer2[0], Ans2[0])
        && EqualityNumbers(ModeAndAnswersData->Answer2[1], Ans2[1])))
        {
            printf("Unit test error in line %d of %s\n", count, argv);
            printf("Test values are: real: %.4lf complex: %.4lf\n real: %.4lf complex: %.4lf\n\n",
            Ans1[0], Ans1[1], Ans2[0], Ans2[1]);
            printf("Test values are: real: %.4lf complex: %.4lf\n real: %.4lf complex: %.4lf\n\n",
            ModeAndAnswersData->Answer1[0], ModeAndAnswersData->Answer1[1],
            ModeAndAnswersData->Answer2[0], ModeAndAnswersData->Answer2[1]);
            flag = false;
        }
                    
        count++;
    }

    if (flag)
    {
        printf("Unit test successfull!!!\n");
    }
    return NO_ERRORS;
}