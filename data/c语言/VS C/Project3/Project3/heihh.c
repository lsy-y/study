#include<stdio.h>
void main()
{
	int i, sum, n;
	printf("����n��");
	scanf("%d", &n);
	sum = 0;
	for (i = 1; i <= n; i++)
		sum += i;
	printf("sum=%d\n", sum);
}