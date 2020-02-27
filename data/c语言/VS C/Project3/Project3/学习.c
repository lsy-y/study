#include<stdio.h>
void main()
{
	char a, b, c;
	for (a = 'A'; a <= 'C'; a++)
		for (b = 'A'; b <= 'C'; b++)
			for (c = 'A'; c <= 'C'; c++)
				if ((a != b && a != c && b != c) && (a != 'C'&&b != 'B'&&c != 'A'))
					printf("X--%d,Y--%d,Z--%d\n", a, b, c);
}