#include<stdio.h>
void main()
{
	int n;
	int rightDigit;
	printf("����һ������");
	scanf("%d", &n);
	printf("��ת����Ϊ��");
	while(n!=0)
	{rightDigit = n % 10;
		printf("%d", rightDigit);
		n = n / 10;
	} 
	printf("\n");
}