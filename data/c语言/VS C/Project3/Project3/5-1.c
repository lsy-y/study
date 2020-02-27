#include<stdio.h>
double power(double x, int n)

{
	int i;
	double xn = 1;
	for (i = 1; i <= n; i++)
		xn *= x;
	return xn;
}
void main()
{
	int n;
	double x;
	printf("x,n = ");
	scanf("%lf,%d", &x, &n);
	printf("%.4f\n", power(x, n));
}