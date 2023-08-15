/* Supporting functions file */

#include <stdio.h>
#include <math.h>
#include "headfile.h"

/* solving quadratic equation function */
void Solving(double a, double b, double c)
{
	double D;
	if ((a > 0) || (a < 0))
	{
		D = (b * b) - (4 * a * c);
		if (D < 0)
		{
			printf("Equation has not got real solution\n");
		}
		else if (D > 0)
		{
			printf("Equation has two real solution\n");
			printf("First solution: %.2lf\n", (-b + (sqrt(D))) / (2 * a));
			printf("Second solution: %.2lf\n", (-b - (sqrt(D))) / (2 * a));
		}
		else
		{
			printf("Equation has one real solution\n");
			printf("Solution is: %.2lf\n", ((-b) + sqrt(D)) / (2 * a));
		}
	}
	else
	{
		printf("This is not quadratic equation\n"
				"But solution is: %.2lf\n", (-c)/b);

	}
}

void ScipInput()
{
	char ch;           // trash variable to skip trash simbols from stdin flow
	while ((ch = (char) getchar()) != '\n')
		;         // empty operator
}
