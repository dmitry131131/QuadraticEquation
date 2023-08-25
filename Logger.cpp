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

int i = 0;

struct LoggElement* LoggBufferInit()
{
    return (struct LoggElement*) calloc(LOGGER_BUFFER_SIZE, sizeof(LoggElement));
}

void FreeBuffer(struct LoggElement* BufferName)
{
    free(BufferName);
}

void WriteToBuffer(const char* file, const char* function, int line)
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

void OutputLogg(enum ErrorHandling ErrorCode, FILE* LoggFile)
{
    PrintErrorValue(ErrorCode, LoggFile);

    int j = 0;

    for(j = 0; j < (i-1); j++)
    {
        fprintf(LoggFile, "%s(%s)/", (_LoggBuffer + j)->file, (_LoggBuffer + j)->function);
    }

    fprintf(LoggFile, "%s(%s)LINE: %d\n", (_LoggBuffer + j)->file, (_LoggBuffer + j)->function, (_LoggBuffer + j)->line);
}