#include<stdio.h>
#include<math.h>
void main()
{
	int i;
	int x = 1;
	for (i = 9; i >= 1; i--)
	{
		x = (x + 1)*2;
	}
	printf("��һ�칲��%d������", x);
}