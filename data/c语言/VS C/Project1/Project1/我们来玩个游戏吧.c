#include<stdio.h>
void main()
{
	printf("�����������Ϸ�ɣ�");
	int ch;
	ch = getchar();
	putchar(ch);
	int a, b, c;
	printf("���������������һ�����֣�");
	scanf("%d",&a);
	switch (a)
	{
	case 520:printf("��Ҳ����ѽ��������");
		break;
	case 250:printf("�����ɵ��"); break;
	case 2:printf("���2"); break;
	default:printf("game over");
	}

}