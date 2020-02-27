#include<stdio.h>
void main()
{
	int a = 5, b = 3, c;
	double d = 2;
	c = a - b + a % b;
	printf("c=%d\n", c);
	printf("d=%d\n", c*d + a / d * b + a / b);
}