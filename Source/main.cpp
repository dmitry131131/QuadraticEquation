/**
 * @file
 * @brief main file
*/
#include <stdio.h>

#include "StructAndEnums.h"
#include "Logger.h"
#include "InputOutput.h"
#include "MainMode.h"
#include "FlagsManager.h"
#include "Test.h"


int main(int argc, char* argv[])
{   
    AddLogg();

    enum ErrorHandling ErrorCode = NO_ERRORS;

    ErrorCode = FlagsManager(argc, argv);

    #ifdef RUN_TEST

    if (ErrorCode != NO_ERRORS)
    {
        if ((ErrorCode != FILE_NOT_OPENED) && (ErrorCode != CLOSE_FILE_ERROR))
        {
            PrintErrorValue(ErrorCode, stdout, NULL);
        }  
        RemoveLogg_();
        return 0;
    }

    #endif

    if ((ErrorCode != NO_ERRORS) && (ErrorCode != FILE_NOT_OPENED) && (ErrorCode != CLOSE_FILE_ERROR))
    {
        PrintErrorValue(ErrorCode, stdout, NULL);
    }

    while (1)
    {
        printf("Enter a b c ratios of quadratic equation or 'q' to exit\n");
        if ((ErrorCode = MainMode(stdin)))
        {
            if (ErrorCode != FOUND_EOF_FILE)
            {
                if (getchar() == 'q')
                {
                    SkipInput(stdin);
                    FreeBuffer_(_LoggBuffer);
                    RETURN(0);
                }
                else
                {
                    SkipInput(stdin);
                    PrintErrorValue(ErrorCode, stdout, NULL);
                }
            }
            else 
            {
                FreeBuffer_(_LoggBuffer);
                RETURN(0);
            }

        printf("Please enter digital data\n");

        }
    }

    FreeBuffer_(_LoggBuffer);

    RETURN(0);
}
