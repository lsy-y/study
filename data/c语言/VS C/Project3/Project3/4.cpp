#include<stdio.h>
#include<math.h>
int fibonacci(int n)
{
	if (n < 1e-6 || n == 1)
		return n;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}
void main()
{
	int n;
	printf("Input n = ");
	scanf("%d", &n);
	printf("%d", fibonacci(n));
}