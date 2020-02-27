#include<stdio.h>
#include<math.h>
int computRoots(double a, double b, double c, double *x1, double *x2);
int main()
{
	double a, b, c;
	double x1, x2;
	int flag;
	printf("Input a,b,c?  ");
	scanf("%lf,%lf,%lf", &a, &b, &c);
	flag = computRoots(a, b, c, &x1, &x2);
	if (flag == 0 || flag == 2)
		printf("此方程没有实根或此方程不是一元二次方程.\n");
	else
		printf("此方程实根为：x1=%8.4f,x2=%8.4f\n", x1, x2);
}
int computRoots(double a, double b, double c, double *x1, double *x2)
{
	int result;
	double t;
	if (fabs(a) < 1e-6)
		return 0;
	else
	{
		t = b * b - 4 * a*c;
		if (fabs(t) < 1e-6)
		{
			*x1 = *x2 = -b / (2 * a);
			result = 1;
		}
		else if (t > 1e-6)
		{
			*x1 = (-b + sqrt(t)) / (2.0*a);
			*x2 = (-b - sqrt(t)) / (2.0*a);
			result = 2;
		}
		else result = 0;
	}
	return result;
}
