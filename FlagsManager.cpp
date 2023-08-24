/**
 * @file 
 * @brief File with FlagsManager function
*/
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "StructAndEnums.h"
#include "Test.h"
#include "InputOutput.h"
#include "MainMode.h"
#include "math_utilits.h"
#include "FlagsManager.h"

enum ErrorHandling FlagsManager(const int argc, char* argv[])
{

    enum ErrorHandling ErrorCode = NO_ERRORS;

    #ifdef RUN_TEST

        ErrorCode = Tester(argc, argv);

    #else

    for (int i = 1; i < argc; i++)
    {

        if (!strcmp(argv[i], "-h"))
        {  
            HelpOutput();
        }

        else if (!strcmp(argv[i], "-f"))
        {
            if (argc >= (i + 1)) 
            {
                FILE* file = fopen(argv[i+1], "r");

                if (file == NULL)
                {
                    ErrorCode = FILE_NOT_OPENED;
                }

                else
                {
                    printf("Input file: %s\n", argv[i + 1]);
                    while (!MainMode(file)) {SkipInput(file);}
                    i++;
                }
            }

            else
            {
                ErrorCode = FILE_NOT_OPENED;
            }
        }

        else
        {
            ErrorCode = INVALID_CONSOLE_ARG;
        }

    }

    #endif

    return ErrorCode;
}