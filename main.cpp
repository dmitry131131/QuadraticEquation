/**
 * @file
 * @brief main file
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "StructAndEnums.h"
#include "InputOutputFunc.h"
#include "ComputationalFunc.h"
#include "MainFuncModes.h"

int main(int argc, char* argv[])
{

    struct ModeAndAnswers ModeAndAnswersData = {ERROR, {NAN, NAN, NAN}, {{NAN, NAN}, {NAN, NAN}}};

    switch (argc)
    {
    
    /* Mode with console input and console output */
    case 1:
        ConsoleInputConsoleOutput(&ModeAndAnswersData);
        break;
    
    /* Mode with file input and console output */
    case 2:
        if (!strcmp(argv[1], "--help"))
        {
            HelpOutput();
        }
        else
        {
            FILE* file = fopen(argv[1], "r");
            if (file == NULL)
            {
                PrintErrorValue(FILE_NOT_OPENED, __func__);
            }
            else
            {
                FileOneInputConsoleOutput(&ModeAndAnswersData, file);
            }
        }
        break;
    
    /* Mode with processing of many input values*/
    case 3:
        if (!strcmp(argv[2], "m"))
        {
            FILE* file = fopen(argv[1], "r");
            if (file == NULL)
            {
                PrintErrorValue(FILE_NOT_OPENED, __func__);
            }
            else
            {
                FileManyInputConsoleOutput(&ModeAndAnswersData, file);
            }
        }

        else if (!strcmp(argv[2], "t"))
        {
            FILE* file = fopen(argv[1], "r");
            if (file == NULL)
            {
                PrintErrorValue(FILE_NOT_OPENED, __func__);
            }
            else
            {
                SolvingFuncUnitTest(&ModeAndAnswersData, file, argv[1]);
            }
        }

        else
        {
            PrintErrorValue(INVALID_CONSOLE_ARG, __func__);
        }
        break;

    default:
        PrintErrorValue(TOO_MANY_CONSOLE_ARG, __func__);
        break;
    }

    return 0;
}
