#include<stdio.h>

void main()
{
	int a, b, c, d, e;
	printf("�ֱ�����������λ����");
	scanf("%d %d", &b, &a);
	d = a % 10;                     //��λ��
	e = (a - d) / 10;                 //ǧλ��
	c = e * 1000 + d * 100 + b;
	printf("%d", c);
}