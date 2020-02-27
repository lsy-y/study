#include<stdio.h>
void main()
{
	int x; x = 1;
	scanf("%d", &x);
		switch (x / 10)
		{
		case 6:
		case 7:
			printf("Pass\n"); break;
		case 8:
			printf("Good\n"); break;
		case 9:
		case 10:
			printf("VeryGood\n"); break;
		default:
			printf("Fail\n");
			break;
		}

}