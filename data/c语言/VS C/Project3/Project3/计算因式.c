#include<stdio.h>
void main()
{
	int n, k;
	printf(" ‰»În?");
	scanf("%d", &n);
	for (k = 1; k <= n; k++)
		if (n%k == 0)
			printf("%d\n", k);
	printf("\n");
}