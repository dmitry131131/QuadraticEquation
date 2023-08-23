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
    double a = NAN, b = NAN, c = NAN;      // coefficient of quadratic equation

    struct ModeAndAnswers ModeAndAnswersData = {ERROR, {NAN, NAN}, {NAN, NAN}};

    switch (argc)
    {
    
    /* Mode with console input and console output */
    case 1:
        ConsoleInputConsoleOutput(&a, &b, &c, &ModeAndAnswersData);
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
                PrintErrorValue(FILE_NOT_OPENED);
            }
            else
            {
                FileOneInputConsoleOutput(&a, &b, &c, &ModeAndAnswersData, file);
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
                PrintErrorValue(FILE_NOT_OPENED);
            }
            else
            {
                FileManyInputConsoleOutput(&a, &b, &c, &ModeAndAnswersData, file);
            }
        }

        else if (!strcmp(argv[2], "t"))
        {
            FILE* file = fopen(argv[1], "r");
            if (file == NULL)
            {
                PrintErrorValue(FILE_NOT_OPENED);
            }
            else
            {
                SolvingFuncUnitTest(&a, &b, &c, &ModeAndAnswersData, file, argv[1]);
            }
        }

        else
        {
            PrintErrorValue(INVALID_CONSOLE_ARG);
        }
        break;

    default:
        PrintErrorValue(TOO_MANY_CONSOLE_ARG);
        break;
    }

    return 0;
}
