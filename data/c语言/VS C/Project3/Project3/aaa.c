#include <stdio.h>
int fun()
{
	static int x = 1;
	x *= 2;
	return x;
}
main()
{
	int i, s = 1;
	for (i = 1; i <= 3; i++)
		s *= fun();
	printf("%d\n", s);
}
