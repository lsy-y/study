#include<stdio.h>
void main()
{
	char a;
	printf("����һ���ַ���");
	a = getchar();
	if (a >= 97 && a <= 122 || a >= 65 && a <=90)
		printf("It is alpha\n");
	else if (a >= 48 && a <= 57)
		printf("It is digit!\n");
	else printf("It is other char");
}
