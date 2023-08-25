/**
 * @file 
 * @brief File with FlagsManager function
*/
#include <stdio.h>
#include <string.h>

#include "StructAndEnums.h"
#include "Logger.h"
#include "Test.h"
#include "InputOutput.h"
#include "MainMode.h"
#include "math_utilits.h"
#include "FlagsManager.h"

enum ErrorHandling FlagsManager(const int argc, char* argv[])
{
    AddLogg();

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
            if (FILE* file = OpenFile(argc, argv, &i))
            {
                PrintFilename(argv[i + 1], VIOLET);
                while (!(ErrorCode = MainMode(file))) {}
                /*
                if (!ErrorCode) 
                {
                    return ErrorCode;
                }
                */
                i++;
            }
            else
            {   
                PrintFilename(argv[i + 1], VIOLET);
                OutputLogg_(FILE_NOT_OPENED, _LoggFile);
                return FILE_NOT_OPENED;
            }
        }
        else
        {
            RemoveLogg_();
            return INVALID_CONSOLE_ARG;
        }
    }

    #endif

    RemoveLogg_();
    if (ErrorCode == FOUND_EOF_FILE)
    {
        return NO_ERRORS;
    }
    else
    {
        return ErrorCode;
    }
}
