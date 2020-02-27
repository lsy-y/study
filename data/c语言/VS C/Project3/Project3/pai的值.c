#include<stdio.h>
#include<math.h>
double arctan(double);
double f();
void main()
{
	printf("PI = %lf\n",f());
}
double arctan(double x)
{
	int i=1;
	double b, r,xx,a;       //i为分母 b为分子 xx为x的平方 a=b/i
	xx = x * x;
	i = 1;
	b = x;
	r = 0;
	while (fabs(b / i > 1e-15))
	{
		a = b / i;
		r = (i % 4 == 1) ? r + a : r - a;
		i += 2;
		b = b * xx;
	}
	return r;
}
double f()
{
	double a, b, pi;
	a = 16.0*arctan(1 / 5.0);
	b = 4.0 * arctan(1 / 239.0);
	pi = a - b;
	return pi;
}