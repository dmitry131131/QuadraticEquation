/* Programm to solve quadratic equation */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "ComputationalFunc.h"


int main(int argc, char* argv[])
{
    double a = NAN, b = NAN, c = NAN;      // coefficient of quadratic equation

    struct ModeAndAnswers ModeAndAnswersData = {ERROR, {NAN, NAN}, {NAN, NAN}};

    switch (argc)
    {
    
    /* Mode with console input and console output */
    case 1:
        if (!ConsoleInput(&a, &b, &c))
        {
            if (!(IsFinite(a) && IsFinite(b) && IsFinite(c)))
                PrintErrorValue(COEFFICIENTS_NOT_NUMBER);
            else
                SolvingQuadraticEquation(a, b, c, &ModeAndAnswersData);

            if (IsFinite(ModeAndAnswersData.Answer1[0]) && IsFinite(ModeAndAnswersData.Answer1[1])
            && IsFinite(ModeAndAnswersData.Answer2[0]) && IsFinite(ModeAndAnswersData.Answer2[1]))
                ConsoleOutput(&ModeAndAnswersData);
            else
                PrintErrorValue(ANSWERS_NOT_NUMBER);
        }
        break;
    
    /* Mode with file input and console output */
    case 2:
        if (!strcmp(argv[1], "--help"))
        {
            HelpOutput();
        }
        else
        {
            FILE* file = fopen(argv[1], "r");
            if (file == NULL)
            {
                PrintErrorValue(FILE_NOT_OPENED);
            }
            else
            {
                if (!FileInput(&a, &b, &c, file))
                {
                    if (!(IsFinite(a) && IsFinite(b) && IsFinite(c)))
                        PrintErrorValue(COEFFICIENTS_NOT_NUMBER);
                    else
                        SolvingQuadraticEquation(a, b, c, &ModeAndAnswersData);

                    if (IsFinite(ModeAndAnswersData.Answer1[0]) && IsFinite(ModeAndAnswersData.Answer1[1])
                    && IsFinite(ModeAndAnswersData.Answer2[0]) && IsFinite(ModeAndAnswersData.Answer2[1]))
                        ConsoleOutput(&ModeAndAnswersData);
                    else
                        PrintErrorValue(ANSWERS_NOT_NUMBER);
                }
                else
                {  
                    PrintErrorValue(FILE_INPUT_ERROR);
                }
                if (fclose(file) == EOF)
                        PrintErrorValue(CLOSE_FILE_ERROR);
            }
        }
        break;
    
    /* Mode with processing of many input values*/
    case 3:
        if (!strcmp(argv[2], "m"))
        {
            FILE* file = fopen(argv[1], "r");
            if (file == NULL)
            {
                PrintErrorValue(FILE_NOT_OPENED);
            }
            else
            {
                int count = 1;
                while (!FileInput(&a, &b, &c, file))
                {
                    printf("%d\n", count);
                    if (!(IsFinite(a) && IsFinite(b) && IsFinite(c)))
                        PrintErrorValue(COEFFICIENTS_NOT_NUMBER);
                    else
                        SolvingQuadraticEquation(a, b, c, &ModeAndAnswersData);

                    if (IsFinite(ModeAndAnswersData.Answer1[0]) && IsFinite(ModeAndAnswersData.Answer1[1])
                    && IsFinite(ModeAndAnswersData.Answer2[0]) && IsFinite(ModeAndAnswersData.Answer2[1]))
                        ConsoleOutput(&ModeAndAnswersData);
                    else
                        PrintErrorValue(ANSWERS_NOT_NUMBER);
                    
                    ScipInput(file);
                    
                    count++;
                }
                
                if (fclose(file) == EOF)
                    PrintErrorValue(CLOSE_FILE_ERROR);
            }
            
        }

        else if (!strcmp(argv[2], "t"))
        {
            FILE* file = fopen(argv[1], "r");
            if (file == NULL)
            {
                PrintErrorValue(FILE_NOT_OPENED);
            }
            else
            {
                int count = 1;
                bool flag = true;
                while (!FileInput(&a, &b, &c, file))
                {
                    if (!(IsFinite(a) && IsFinite(b) && IsFinite(c)))
                        PrintErrorValue(COEFFICIENTS_NOT_NUMBER);
                    else
                        SolvingQuadraticEquation(a, b, c, &ModeAndAnswersData);

                    double Ans1[2] = {0, 0}, Ans2[2] = {0, 0};
                    fscanf(file, "%lf %lf %lf %lf", &Ans1[0], &Ans1[1], &Ans2[0], &Ans2[1]);
                    ScipInput(file);

                    if (!(EqualityNumbers(ModeAndAnswersData.Answer1[0], Ans1[0])
                    && EqualityNumbers(ModeAndAnswersData.Answer1[1], Ans1[1])
                    && EqualityNumbers(ModeAndAnswersData.Answer2[0], Ans2[0])
                    && EqualityNumbers(ModeAndAnswersData.Answer2[1], Ans2[1])))
                    {
                        printf("Unit test error in line %d of %s\n", count, argv[1]);
                        printf("Test values are: real: %.4lf complex: %.4lf\n real: %.4lf complex: %.4lf\n\n",
                        Ans1[0], Ans1[1], Ans2[0], Ans2[1]);
                        printf("Test values are: real: %.4lf complex: %.4lf\n real: %.4lf complex: %.4lf\n\n",
                        ModeAndAnswersData.Answer1[0], ModeAndAnswersData.Answer1[1],
                        ModeAndAnswersData.Answer2[0], ModeAndAnswersData.Answer2[1]);
                        flag = false;
                    }
                    
                    count++;
                }

                if (flag)
                {
                    printf("Unit test successfull!!!\n");
                }
            }
        }

        else
        {
            PrintErrorValue(INVALID_CONSOLE_ARG);
        }
        break;

    default:
        PrintErrorValue(TOO_MANY_CONSOLE_ARG);
        break;
    }

    return 0;
}
