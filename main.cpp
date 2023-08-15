/* Programm to solve quadratic equation */

#include <stdio.h>
#include "headfile.h"

int main(void) 
{
	double a, b, c;      // ratios of quadratic equation
	
	printf("Enter a b c ratios of quadratic equation\n");
	while (1)
	{
		if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
		{
			printf("Please enter digital data\n");
			ScipInput();
		}
		else
			break;
	}

	Solving(a, b, c);
}