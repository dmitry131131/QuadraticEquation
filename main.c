/* Programm to solve quadratic equation */

#include <stdio.h>
#include "headfile.h"

int main(void) 
{
	double a, b, c;      // ratios of quadratic equation
	char ch;           // trash variable to skip trash simbols from stdin flow

	printf("Enter a b c ratios of quadratic equation\n");
	while (1)
	{
		if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
		{
			printf("Please enter digital data\n");
			while ((ch = getchar()) != '\n')
				;         // empty operator
		}
		else
			break;
	}

	solving(a, b, c);
}