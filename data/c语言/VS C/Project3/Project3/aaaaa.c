#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n, i, k, x;
	int *s;
	s = malloc(1);
	int *s2;
	s2 = malloc(1);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	for (k = 0; k <= n; k++)
	{
		x = (int)(s[k] + s[k + 1]) / 2;
		s2[k] = x;
		printf("%-4d", s2[k]);
	}
	printf("\n");
}