#include<stdio.h>
void main()
{
	int a;       //��Ǯ
	int b;      //���͸���
	int c;      //�ܸ���
	int d;
	scanf("%d", &a);
	d = a / 2;
	b = d % 5;
	c = d + b;
	printf("�������%d������", c);

}