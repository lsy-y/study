#include<stdio.h>
#include<math.h>
#define r1 3.5
#define r2 4.4
#define r3 5.0
#define r4 5.59
void main()
{
	int y;                                           //yΪ���ޣ�nΪ��Ϣ,xΪ����
	double x, n; 
	printf("���ޣ��꣩��");
	scanf("%d", &y);
	printf("����Ԫ����" );
	scanf("%lf", &x);                          
	if (y == 1)
		n = r1 / 100;
	else if (y == 2)
		n = r2 / 100;
	else if (y == 3)
		n = r3 / 100;
	else if (y == 5)
		n = r4 / 100;
	printf("�õ���%8.4f", x*pow(1 + n, y));
}