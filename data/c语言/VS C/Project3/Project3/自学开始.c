#include<stdio.h>

void main()
{
	float a, b;
	int c, d;
	char op;
	printf("Input two numbers:");
	scanf("%f %f", &a, &b);
	printf("Input an option:");
	scanf("%c",&op);
	fflush(stdin);
	scanf("%c", &op);
	printf("%.2f%c%.2f=%.2f", a, op, b, a + b);
	if (op == '+')
		printf("%.2f%c%.2f=%.2f", a, op, b, a + b);
	else if (op == '-');
	printf("%.2f%c%.2f=%.2f", a, op, b, a - b);
}