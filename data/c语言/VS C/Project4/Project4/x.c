#include<stdio.h>
void main()
{
	int n;
	int rightDigit;
	printf("����һ������");
	scanf("%d", &n);
	printf("��ת����Ϊ��");
	do {
		rightDigit = n % 10;
		printf("%d", rightDigit);
		n = n / 10;
	} while (n != 0);
	printf("\n");
}