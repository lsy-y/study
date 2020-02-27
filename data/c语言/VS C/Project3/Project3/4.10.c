#include<stdio.h>
#include<math.h>
void main()
{
	int N;
	int i,x;
	double sqrti;
	printf("N = ");
	scanf("%d", &N);
	for (i = N+1;; i++)
	{
		sqrti = sqrt(i);
		for (x = 2; x <= i; x++)
			if (i%x == 0)break;
		if (x > sqrti)break;
	}
	printf("%d", i);
}