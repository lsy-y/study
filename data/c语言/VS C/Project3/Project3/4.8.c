#include<stdio.h>
void main()
{
	int n,i, m,a,b,x;
	printf("n= ");
	scanf("%d", &n);
	i = 0;
	m = n;
	a = 0;
	do
	{
		x = m % 10;
		m = m / 10;
		i++;
		a =(a+x)*10;
	} while (m != 0);
	if (a / 10 == n)
		printf("%d是回文数", n);
	else printf("%d不是回文数", n);
}