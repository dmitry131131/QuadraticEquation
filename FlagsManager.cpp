/**
 * @file 
 * @brief File with FlagsManager function
*/
#include <stdio.h>
#include <string.h>
#include "StructAndEnums.h"
#include "InputOutput.h"
#include "MainMode.h"
#include "math_utilits.h"
#include "FlagsManager.h"

enum ErrorHandling FlagsManager(const int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h"))
        {
            HelpOutput();
        }
        else if (!strcmp(argv[i], "-f"))
        {   
            if (argc >= i + 1) 
            {
                FILE* file = fopen(argv[i+1], "r");
                if (file == NULL)
                {
                    PrintErrorValue(FILE_NOT_OPENED);
                    return FILE_NOT_OPENED;
                }
                else
                {   
                    printf("Input file: %s\n", argv[i+1]);
                    while (!MainMode(file)) {SkipInput(file);}
                    i++;
                }
            }
            else
            {
                return INVALID_CONSOLE_ARG;
            }
        }
        else
        {
            PrintErrorValue(INVALID_CONSOLE_ARG);
            return INVALID_CONSOLE_ARG;
        }
    }
    return NO_ERRORS;
}