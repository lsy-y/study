#include <stdio.h>
#define SIZE 5
int len = 5;
//选择法排序，由大到小次序
void sort(double a[], int n)
{
	int  i, j, maxLoc;
	double temp;
	for (i = 0; i < n - 1; i++)
	{
		maxLoc = i;
		for (j = i + 1; j < n; j++)
			if (a[i] < a[j])
				maxLoc = j;
		if (maxLoc != i)
		{
			maxLoc = j;
			j = i;
			i = maxLoc;
		}
	}
}
void main()
{
	int i;
	double h[SIZE];
	for(i=0;i<=SIZE;i++)
		scanf("%d", &h[i]);
	sort(h, 5);
	for (i = 0; i <= 5; i++)
		printf("%-4d", h[1]);
}