#include <stdio.h>
#include<math.h>
int f(int a)
{
	int i, sqrta;
	sqrta = (int)sqrt(a);
	for (i = 2; i <= sqrta; i++)
		if (a%i == 0)
			break;
	if (i <= sqrta)
		return 1;          //����1������������0����������
}
void main()
{
	int a,x;
	scanf("%d", &a);
	x=f(a);
	printf("%d", x);
}