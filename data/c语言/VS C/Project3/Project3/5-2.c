#include<stdio.h>
int isPerfect(int x);
void displayPerfect(int x);
void main()
{
	int x;
	for (x = 1; x < 10000; x++)
		if (isPerfect(x))
			displayPerfect(x);
}
int isPerfect(int x)
{
	int y = 0, i;
	for (i = 1; i < x; i++)
		if (x%i == 0)
			y += i;
	if (y == x)
		return 1;
	else return 0;
}
void displayPerfect(int x)
{
	int i;
	printf("%d = ", x);
	for(i=1;i<x;i++)
		if (x%i == 0)
		{
			if (i != 1)
				printf("+");
			printf("%d", i);
		}
	printf("\n");
}