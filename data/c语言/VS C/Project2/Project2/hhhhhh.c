#include<stdio.h>
void main()
{
	char a, b, c, d;
	scanf("%c%c", &a, &b);
	c = getchar();
	while (c == '\n')
		scanf("%c", &c);
	d = getchar();
	printf("%c%c%c%c\n", a, b, c, d);
}