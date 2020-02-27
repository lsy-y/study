#include<stdio.h>
void main()
{
	printf("我们来玩个游戏吧！");
	int ch;
	ch = getchar();
	putchar(ch);
	int a, b, c;
	printf("请输入你最爱的数字一个数字：");
	scanf("%d",&a);
	switch (a)
	{
	case 520:printf("我也爱你呀！！！！");
		break;
	case 250:printf("你个大傻子"); break;
	case 2:printf("你才2"); break;
	default:printf("game over");
	}

}