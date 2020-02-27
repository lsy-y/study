#include<stdio.h>

void main()
{
	int a, b, c, d, e;
	printf("分别输入两个二位数：");
	scanf("%d %d", &b, &a);
	d = a % 10;                     //百位数
	e = (a - d) / 10;                 //千位数
	c = e * 1000 + d * 100 + b;
	printf("%d", c);
}