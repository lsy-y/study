#include<stdio.h>
#include<math.h>
void main()
{
	int x, y, m,n,i;                               
	printf("��һ���˽�������ʮ����������");
	printf("n = ");
	scanf("%d", &n);
	i = 0;
	m = 0;
	do
	{
		x = n % 10;
		y = x * pow(8, i);
		m = m + y;
		i++;
		n = n / 10;
	} while (n != 0);
	printf("%d", m);
}