#include<stdio.h>
void main()
{
	float a, b, c,number1;
	printf("input a,b,c:");
	scanf("%f %f %f",&a,&b,&c);
	number1 = a;
	a = b;
	b = c;
	c = number1;
	printf("%.2f %.2f %.2f",a,b,c);
}