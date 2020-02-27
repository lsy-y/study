#include<stdio.h>
#include<math.h>
void main()
{
	int i, n,m;
	double e = 1.0;
	n = 1;
	i = 1;

	do
	{	m = 1 / n;
	    e = e + m;
		n = n * (i + 1);
		i++;
	} while (m >= 1e-6);
	printf("e=%f", e);
}