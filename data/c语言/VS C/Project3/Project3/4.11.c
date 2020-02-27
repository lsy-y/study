#include<stdio.h>
void main()
{
	int N;
	int i,m,n;
	printf("N = ");
	scanf("%d", &N);
	for (m = 0; m <= N; m++)
	{	
		i = m+1;
		n = m;
		do 
		{
		
			printf("%d", n);
			i--;
		} while (i >= 1);
		printf("\n");
	}
}