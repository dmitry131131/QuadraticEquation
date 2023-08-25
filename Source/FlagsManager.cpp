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
                i++;
            }
            else
            {   
                PrintFilename(argv[i + 1], VIOLET);
                PrintErrorValue(FILE_NOT_OPENED, stdout, argv[i + 1]);
                OutputLogg_(FILE_NOT_OPENED, _LoggFile, argv[i + 1]);
                return FILE_NOT_OPENED;
            }
        }
        else
        {
            RETURN(INVALID_CONSOLE_ARG);
        }
    }

    #endif

    if (ErrorCode == FOUND_EOF_FILE)
    {
        RETURN(NO_ERRORS);
    }
    else
    {
        RETURN(ErrorCode);
    }
}
