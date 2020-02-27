#include<stdio.h>
void main()
{
	int n;
	int rightDigit;
	printf("输入一个数：");
	scanf("%d", &n);
	printf("反转序列为：");
	do {
		rightDigit = n % 10;
		printf("%d", rightDigit);
		n = n / 10;
	} while (n != 0);
	printf("\n");
}