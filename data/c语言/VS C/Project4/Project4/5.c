#include<stdio.h>
void main()
{
	double a, b, c, min;
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a < b)
	{
		if (a < c)
			min = a;
		else min = c;
	}
	else
	{
		if (b < c)
			min = b;
		else min = c;
	}
	printf("最小数为；%f", min);
}