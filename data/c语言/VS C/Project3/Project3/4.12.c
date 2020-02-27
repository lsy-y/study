#include<stdio.h>
void main()
{
	 int n = 15;
	 int i;
	 double t;
	 double sum;
	t = 1;
	i = 0;
	sum = 0;
    do
	{
		t = t * (i + 1);
		//printf("%.1f\n", t);
		sum = sum + t;
		i++;
	} while (i < n);
	printf("%.1f", sum);
}