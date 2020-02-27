#include<stdio.h>
#include<math.h>
#define PI 3.1415926
void main()
{
	double d, x, x2, xn, t, n, sinx = 0.0;
	int sign = 1, i = 1;
	printf("(输入x（单位为度）：");
	scanf("%lf", &d);
	x = d / 180.0*PI;
	x2 = x * x;
	xn = x;
	n = 1;
	t = sign * xn / n;
	do
	{
		sinx = sinx + t;
		sign = sign * (-1);
		xn = xn * x2;
		n = n * (i + 1)*(i + 2);
		t = sign * xn / n;
		i = i + 2;
	} while (fabs(t) >= 1e-6);
	printf("sin(%.1f)=%.2f", d, sinx);
}