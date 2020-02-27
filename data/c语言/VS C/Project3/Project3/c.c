#include<stdio.h>
static char x;
void fun()
{
	static int a = 2;
	int b = 2;
	a++;
	b++;
	printf("a = %d,b = %d\n", a, b);
}
void main()
{
	fun();
	fun();
	fun();
	printf("x = %d", x);
}