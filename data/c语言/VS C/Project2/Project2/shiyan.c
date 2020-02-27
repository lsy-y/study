#include<stdio.h>
main()
{
	int a, b, c;
	a = b = c = 1;
	a = ++b - (c++);       //a=2-1=1  b=2  c=2
	printf("a=%d,b=%d,c=%d\n", a, b, c);      //a=1,b=2,c=2   
	printf("a=%d,b=%d,c=%d\n", a++, b--, ++c);    //a=2,b=1,c=3
	printf("%d\n", (++a, b--, c + a / b, a + b));    //a=3,b=0,a+b=3
	printf("%d %d\n", a, b);// a=3,b=0
}