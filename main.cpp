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

#ifdef _SHOW_LOGG_MESSAGE

    struct LoggElement* _LoggBuffer = LoggBufferInit();

    FILE* _LoggFile = fopen("logs.txt", "w");

#endif

int main(int argc, char* argv[])
{   
    AddLogg();

    enum ErrorHandling ErrorCode = NO_ERRORS;

    ErrorCode = FlagsManager(argc, argv);

    #ifdef RUN_TEST

    if (ErrorCode != NO_ERRORS)
    {
        PrintErrorValue(ErrorCode, stdout);
        RemoveLogg_();
        return 0;
    }

    #endif

    if (ErrorCode)
    {
        PrintErrorValue(ErrorCode, stdout);
    }

    while (1)
    {   
        printf("Enter a b c ratios of quadratic equation or 'q' to exit\n");
        if ((ErrorCode = MainMode(stdin)))
        {
            if (getchar() == 'q')
            {
                SkipInput(stdin);
                RemoveLogg_();
                FreeBuffer_(_LoggBuffer);
                return 0;
            }
            else 
            {
                SkipInput(stdin);
                PrintErrorValue(ErrorCode, stdout);
            }

        printf("Please enter digital data\n");

        }
    }

    RemoveLogg_();
    FreeBuffer_(_LoggBuffer);

    return 0;
}
