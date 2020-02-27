#include<stdio.h>
int sub(int x, int y);
int add(int x, int y);
void main()
{
	int a = 10, b = 20, c;
	int menu;
	int(*p)(int, int);
	printf("1--add\n2--sub\nYour selection:");
	scanf("%d", &menu);
	if (menu == 1)
		p = add;
	else p = sub;
	c = p(a, b);
	printf("c=%d,(*p)(a,b) = %d\n", c, (*p)(a, b));
}
int sub(int x, int y)
{
	return x - y;
}
int add(int x, int y)
{
	return x + y;
}
