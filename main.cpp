/**
 * @file
 * @brief main file
*/
#include <stdio.h>

#include "config.h"

#include "StructAndEnums.h"
#include "InputOutput.h"
#include "MainMode.h"
#include "FlagsManager.h"
#include "Test.h"

int main(int argc, char* argv[])
{
    enum ErrorHandling ErrorCode = NO_ERRORS;

    #ifdef RUN_TEST
    if((ErrorCode = Tester("test.txt")))
    {
        printf("Test Failed!\n");
        return 0;
    }
    
    printf("Test successfull!\n\n");
    
    #endif
    FlagsManager(argc, argv);

    while (1)
    {   
        printf("Enter a b c ratios of quadratic equation or 'q' to exit\n");
        if ((ErrorCode = MainMode(stdin)))
        {
            if (getchar() == 'q')
            {
                SkipInput(stdin);
                return 0;
            }
            else 
            {
                SkipInput(stdin);
                PrintErrorValue(ErrorCode);
            }
        printf("Please enter digital data\n");
        }
    }

    return 0;
}
