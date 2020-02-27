#include<stdio.h>
#include<math.h>
void main()
{
	int k=0;
	double x2, x1;
	double fx, d;
	x1 = 0;
	x2 = 0;
	fx = x1 * exp(x1) - 1;
	d = (x1 + 1)*exp(x1);
	do 
	{
		x2 = x1 - fx / d;
		k++;
	} while (x2 - fabs(x1) < 10e-5);
	printf("%.2f", x2);
}