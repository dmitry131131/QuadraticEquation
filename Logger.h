/**
 * @file
 * @brief Logger functions and structures
*/

const int LOGGER_BUFFER_SIZE = 25;
const int FILENAME_SIZE = 130;

struct LoggElement {
    char file    [FILENAME_SIZE];
    char function[FILENAME_SIZE];
    int line;
};

extern struct LoggElement* _LoggBuffer;

extern FILE* _LoggFile;

void WriteToBuffer(const char* file, const char* function, int line);

void RemoveLogg();

void OutputLogg(enum ErrorHandling ErrorCode, FILE* LoggFile);

struct LoggElement* LoggBufferInit();

void FreeBuffer(struct LoggElement* BufferName);

#ifdef _SHOW_LOGG_MESSAGE

#define AddLogg() do{                                               \
    WriteToBuffer(__FILE__, __func__, __LINE__);                    \
}while (0)

#define RemoveLogg_() do{                                           \
    RemoveLogg();                                                   \
}while(0)

#define FreeBuffer_(BufferName) do{                                 \
    FreeBuffer(BufferName);                                         \
}while(0)

#define OutputLogg_(ErrorCode, LoggFile) do{                        \
    OutputLogg(ErrorCode, LoggFile);                                \
}while(0)

#else

#define RemoveLogg_() ;

#define AddLogg() ;

#define FreeBuffer_(BufferName) ;

#define OutputLogg_(ErrorCode, LoggFile) ;

#endif
