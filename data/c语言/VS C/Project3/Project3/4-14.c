#include<stdio.h>
void main()
{
	int i, n, f1 = 1, f2 = 1, f3;
	printf("n  =  ");
	scanf("%d", &n);
	if (n == 1 || n == 2)
		f3 = 1;
	else
	{
		for (i = 3; i <= n; i++)
		{
			f3 = f1 + f2;
			f1 = f2; f2 = f3;
		}
	}
	printf("Fibn(%d)=%d", n, f3);
}