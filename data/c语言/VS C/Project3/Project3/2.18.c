#include<stdio.h>
void main()
{
	printf("输入一个四位数：");
	int a, b, c, d, e;
	scanf("%d",&a);
	b = a % 10;           //个位
	c = a / 1000;     //    千位
	d = (a - c * 1000) / 100;   //百位
	e = (a - c * 1000 - d * 100) / 10;    //十位
	printf("%d %d %d %d", b, e, d, c);
}