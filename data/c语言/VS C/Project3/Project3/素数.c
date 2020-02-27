#include<stdio.h>
#include<string.h>
#define N 20

//—°‘Ò≈≈–Ú
void sort(char a[], int n) {
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
			temp = a[i];
			a[i] = a[maxLoc];
			a[maxLoc] = temp;
		}
	}
}
void main()
{
	char x[N][20];
	int i, k;
	for (i = 0; i < N; i++)
		gets(x[i]);
	printf("\n");
}
