#include<stdio.h>
void main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
			printf("%d*%d=%2d ", i, j, i*j);
		printf("\n");
	}
}