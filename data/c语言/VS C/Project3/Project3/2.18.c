#include<stdio.h>
void main()
{
	printf("����һ����λ����");
	int a, b, c, d, e;
	scanf("%d",&a);
	b = a % 10;           //��λ
	c = a / 1000;     //    ǧλ
	d = (a - c * 1000) / 100;   //��λ
	e = (a - c * 1000 - d * 100) / 10;    //ʮλ
	printf("%d %d %d %d", b, e, d, c);
}