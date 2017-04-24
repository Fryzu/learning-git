//Rozwiązywanie równania - solving equations

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define E 2.71828182845904523536

double function(double x, double *table)
{
	double result = ((table[0])*sin(((table[1])*x+(table[2])))+(table[3])*pow(E, ((table[4])*x+(table[5])))+(table[6])*fabs((table[7])*x+(table[8]))+(table[9]));

	return result;
}

void rootBinSearch(double left_argument, double right_argument, double *table)
{
	double center_argument;
	double left;
	double right;
	double center;

	while(left_argument<=right_argument)
	{
		center_argument = (left_argument+right_argument)/2;
		left = function(left_argument, table);
		right = function(right_argument, table);
		center = function(center_argument, table);

		if(fabs(center)<0.00000009)
		{
			printf("%.8lf\n", center_argument);
			break;
		}
		else if(((left<=0)&&(center>0))||((left>=0)&&(center<0)))
		{
			right_argument = center_argument;
		}
		else if(((right<=0)&&(center>0))||((right>=0)&&(center<0)))
		{
			left_argument = center_argument;
		}
	}
}

int main()
{
	double x;
	double left_argument;
	double right_argument;
	double table[10];

	scanf("%lf %lf", &left_argument, &right_argument);
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &(table[0]), &(table[1]), &(table[2]), &(table[3]), &(table[4]), &(table[5]), &(table[6]), &(table[7]), &(table[8]), &(table[9]));
	
	rootBinSearch(left_argument, right_argument, table);

	return 0;
}
