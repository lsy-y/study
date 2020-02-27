#include<stdio.h>
#include<math.h>
void main()
{
	int N,n,a,sqrtn;
	printf("N= ");
	scanf("%d", &N);
	
	for (n = 1; n <= N; n++)
	{
		sqrtn = (int)sqrt(n);
		for (a = 2; a <= n; a++)
			if (n%a == 0 && n != 0)break;
		if (a > sqrtn)
			printf("%d ", n);
	}
}