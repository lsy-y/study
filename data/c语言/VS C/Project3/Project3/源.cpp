#include<stdio.h>
void main()
{
	int n = 12345, d;
	while (n != 0)
	{
		d = n % 10;
		printf("%d", d);
		n /= 10;
	}
}