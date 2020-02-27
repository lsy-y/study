#include<stdio.h>
void main()
{
	int a;       //价钱
	int b;      //赠送个数
	int c;      //总个数
	int d;
	scanf("%d", &a);
	d = a / 2;
	b = d % 5;
	c = d + b;
	printf("你可以买%d个鸡蛋", c);

}