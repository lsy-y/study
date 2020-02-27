#include<stdio.h>
void main()
{
	int a;
	int b = 0;
	scanf("%d", &a);
	if (!a)
		b++;
	else if (a == 0)
		if (a)
			b += 2;
		else b += 3;
	printf("%d", b);
}