#include<stdio.h>
void main()
{
	int i, n;
	long t = 1;
	printf("Input n=?");
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
		t = t * i;
	printf("%d!=%d\n", n, t);
}