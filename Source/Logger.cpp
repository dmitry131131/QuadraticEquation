/**
 * @file
 * @brief Sourse of logger func
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "StructAndEnums.h"
#include "Logger.h"
#include "InputOutput.h"

struct LoggElement* _LoggBuffer = LoggBufferInit();

#ifdef _SHOW_LOGG_MESSAGE

FILE* _LoggFile = fopen("logs.txt", "w");

#endif

int i = 0;

struct LoggElement* LoggBufferInit()
{
    #ifdef _SHOW_LOGG_MESSAGE
    
    return (struct LoggElement*) calloc(LOGGER_BUFFER_SIZE, sizeof(LoggElement));

    #else

    return (struct LoggElement*) calloc(0, sizeof(LoggElement));

    #endif
}

void FreeBuffer(struct LoggElement* BufferName)
{
    free(BufferName);
}

void WriteToBuffer(const char* file, const char* function, const int line)
{
    strcpy((_LoggBuffer + i)->file, file);
    strcpy((_LoggBuffer + i)->function, function);
    (_LoggBuffer + i)->line = line;
    i++;
}

void RemoveLogg()
{
    i--;
}

void OutputLogg(enum ErrorHandling ErrorCode, FILE* LoggFile, const char* filename)
{
    PrintErrorValue(ErrorCode, LoggFile, filename);

    int j = 0;

    for(j = 0; j < (i-1); j++)
    {
        fprintf(LoggFile, "%s(%s)/", (_LoggBuffer + j)->file, (_LoggBuffer + j)->function);
    }

    fprintf(LoggFile, "%s(%s)LINE: %d\n", (_LoggBuffer + j)->file, (_LoggBuffer + j)->function, (_LoggBuffer + j)->line);
}