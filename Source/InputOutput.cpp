/**
 * @file
 * @brief Sourse file with input/output functions
*/
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#include "StructAndEnums.h"
#include "InputOutput.h"
#include "Computational.h"

enum ErrorHandling SkipInput(FILE* flow)
{   
    int ch = 0;
    while (1) 
    {
        ch = getc(flow);
        if (ch == '\n') return NO_ERRORS;
        if (ch == EOF) return FOUND_EOF_FILE;
    }

    return NO_ERRORS;
}

enum ErrorHandling Input(double* Coeff, FILE* file)
{
    int log = fscanf(file ,"%lf %lf %lf", &Coeff[0], &Coeff[1], &Coeff[2]);

    #ifndef RUN_TEST

    int ch;
    if ((ch = getc(file)) == 'q' || (ch == EOF)) {}

    else if (ch != '\n') 
    {
        ungetc(ch, file);
        return INVALID_INPUT;
    }

    ungetc(ch, file);

    #endif

    switch (log)
    {
    case 3:
        return NO_ERRORS;
        break;

    case EOF:
        return FOUND_EOF_FILE;
        break;

    default:
        return COEFFICIENTS_NOT_NUMBER;
        break;
    }
    return COEFFICIENTS_NOT_NUMBER;
}

enum ErrorHandling ConsoleOutput(struct ModeAndAnswers* const ModeAndAnswersData)
{
    switch (ModeAndAnswersData->OutputMode)
    {
    case NOT_EQUATION:
        printf("This is not equation:\n"
               "a and b ratios mustn't be 0\n\n");
        break;

    case LINERAL_EQUATION:
        printf("This is not quadratic equation\n"
               "But solution of linear equation is: %.4lf\n\n", ModeAndAnswersData->Answers[0].Real);
        break;

    case ONE_REAL_SOLUTION:
        printf("Equation has one real solution\n");
        printf("Solution is: %.4lf\n\n", ModeAndAnswersData->Answers[0].Real);
        break;

    case TWO_REAL_SOLUTIONS:
        printf("Equation has two real solution\n");
        printf("First solution: %.4lf\n",    ModeAndAnswersData->Answers[0].Real);
        printf("Second solution: %.4lf\n\n", ModeAndAnswersData->Answers[1].Real);
        break;

    case TWO_COMPLEX_SOLUTONS:
        printf("Equation has not got real solution\n"
               "Complex solutions:\n"
               "Real part   Imaginary part\n");
        printf("%-11.4lf %.4lf\n",   ModeAndAnswersData->Answers[0].Real, ModeAndAnswersData->Answers[0].Complex);
        printf("%-11.4lf %.4lf\n\n", ModeAndAnswersData->Answers[1].Real, ModeAndAnswersData->Answers[1].Complex);
        break;
    
    case INPUT_ERROR:
        return CONSOLE_OUTPUT_ERROR;
        break;

    default:
        return CONSOLE_OUTPUT_ERROR;
        break;
    }

    return NO_ERRORS;
}

void PrintErrorValue(ErrorHandling ErrorCode, FILE* flow, const char* filename)
{
    ChangeColor(RED);

    switch (ErrorCode)
    {
    case NO_ERRORS:
        ChangeColor(GREEN);
        fprintf(flow, "Programm done successfully!\n\n");
        ChangeColor(NONE);
        break;

    case COEFFICIENTS_NOT_NUMBER:
        fprintf(flow, "Coefficients not a number or infinity!\n\n");
        break;

    case ANSWERS_NOT_NUMBER:
        fprintf(flow, "Answers are not a numbers or infinity!\n\n");
        break;

    case FOUND_EOF_STDIN:
        fprintf(flow, "Found EOF in stdin flow\n\n");
        break;

    case CONSOLE_OUTPUT_ERROR:
        fprintf(flow, "Output error!\n\n");
        break;

    case FILE_NOT_OPENED:
        fprintf(flow, "File %s error: %s\n", filename, strerror(errno));
        break;

    case FILE_INPUT_ERROR:
        fprintf(flow, "Invalid data in file!\n\n");
        break;

    case FOUND_EOF_FILE:
        fprintf(flow, "Found EOF in file!\n\n");
        break;

    case CLOSE_FILE_ERROR:
        fprintf(flow, "File %s close error:  %s\n", filename, strerror(errno));
        break;

    case INVALID_CONSOLE_ARG:
        fprintf(flow, "Invalid console argument!\n\n");
        break;

    case TEST_FAILED:
        fprintf(flow, "Test Failed!\n\n");
        break;

    case INVALID_INPUT:
        fprintf(flow, "Invalid input format!\n\n");
        break;

    default:
        break;
    }

    ChangeColor(NONE);
}

FILE* OpenFile(const int argc, const char* const argv[], int* i)
{
    if (argc >= (*i + 1)) 
    {
        FILE* file = fopen(argv[*i+1], "r");
        return file;
    }

    else
    {
        (*i)++;
        return NULL;
    }
}

void ChangeColor(enum Colors color)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color)
    {
    case RED:
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        break;

    case GREEN:
        SetConsoleTextAttribute(console, FOREGROUND_GREEN);
        break;
    
    case BLUE:
        SetConsoleTextAttribute(console, FOREGROUND_BLUE);
        break;
    
    case VIOLET:
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED);
        break;

    case NONE:
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        break;
    
    default:
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        break;
    }
}

void PrintFilename(char* file, enum Colors color)
{
    printf("Input file: ");
    ChangeColor(color);
    printf("%s\n", file);
    ChangeColor(NONE);
}

void HelpOutput()
{
    printf( "# Programm to solve quadratic equation\n"
            "\n"
            "Usage: [flag]\n"
            "# []               -- console input and console output\n"
            "Enter a b c decimal coefficients separated by a space\n\n"

            "# [-f] [filename]  -- input first 3 numbers in row from and output solutions to console\n"
            "programm works until End Of File\n\n"

            "# [-h]             -- output help information about programm"

            "# [-t] [filename]  -- test mode:\n"
            "programm read first 3 numbers, solve equation and compare roots with roots in file\n"
            "a b c  real1 complex1 real2 complex2\n"
            "a, b, c - decimal coefficient\n"
            "real1, real2 - real parts of first and second answers\n"
            "complex1, complex2 - complex parts of first and second answers\n\n");
}
