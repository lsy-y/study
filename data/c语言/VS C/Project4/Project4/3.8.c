#include<stdio.h>
void main()
{
	int a;
	printf("输入一个月：");
	scanf("%d", &a);
	printf("英文名：");
	switch (a)
	{
	case 1:printf("January\n"); break;
	case 2:printf("february\n"); break;
	case 3:printf("March\n"); break;
	case 4:printf("April\n"); break;
	case 5:printf("May\n"); break;
	case 6:printf("June\n"); break;
	case 7:printf("July\n"); break;
	case 8:printf("August\n"); break;
	case 9:printf("September\n"); break;
	case 10:printf("October\n"); break;
	case 11:printf("November\n"); break;
	case 12:printf("December\n"); break;
	default: printf("没有这个月");
	}
}