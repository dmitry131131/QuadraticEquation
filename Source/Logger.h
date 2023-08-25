/**
 * @file
 * @brief Logger functions and structures
*/
/// @brief Size of loggs buffer 
const int LOGGER_BUFFER_SIZE = 25;
/// @brief Size of filename cgar array
const int FILENAME_SIZE = 130;
/// @brief Struct with loggs elements
struct LoggElement {
    char file    [FILENAME_SIZE];     ///< name of file
    char function[FILENAME_SIZE];     ///< name of function
    int line;                         ///< line number
};

extern struct LoggElement* _LoggBuffer;

extern FILE* _LoggFile;
/// @brief Write logg to buffer
/// @param [in] file name of file
/// @param [in] function name of function
/// @param [in] line line number
void WriteToBuffer(const char* file, const char* function, const int line);
/// @brief Function remove logg from buffer
void RemoveLogg();
/// @brief Output logg buffer tn LoggFile flow
/// @param ErrorCode Error code
/// @param LoggFile name of flow
/// @param filename name of opened text file 
void OutputLogg(enum ErrorHandling ErrorCode, FILE* LoggFile, const char* filename);
/// @brief Buffer init function
struct LoggElement* LoggBufferInit();
/// @brief Function free buffer memory 
/// @param BufferName name of buffer
void FreeBuffer(struct LoggElement* BufferName);

#ifdef _SHOW_LOGG_MESSAGE

#define RETURN(Value) do{                                           \
    RemoveLogg();                                                  \
    return Value;                                                   \
} while (0)

#define AddLogg() do{                                               \
    WriteToBuffer(__FILE__, __func__, __LINE__);                    \
}while (0)

#define RemoveLogg_() do{                                           \
    RemoveLogg();                                                   \
}while(0)

#define FreeBuffer_(BufferName) do{                                 \
    FreeBuffer(BufferName);                                         \
}while(0)

#define OutputLogg_(ErrorCode, LoggFile, filename) do{              \
    OutputLogg(ErrorCode, LoggFile, filename);                      \
}while(0)

#else

#define RETURN(Value) do{                                           \
    return Value;                                                   \
}while(0)

#define RemoveLogg_() ;

#define AddLogg() ;

#define FreeBuffer_(BufferName) ;

#define OutputLogg_(ErrorCode, LoggFile, filename) ;

#endif
