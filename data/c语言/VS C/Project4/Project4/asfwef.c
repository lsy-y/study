#include<stdio.h>
#define length 5
void main()
{
	int a[length] = { 1,2,3,4,5 };
	int i, *p = a;
	printf("%d\n", *p);
	for (i = 0; i <= length - 1; i++)
		printf("%-4d  ", a[i]);
	printf("\n");
	for (i = 0; i <= length - 1; i++)
		printf("%-4d  ", *(a + i));
	printf("\n");
	for (i = 0; i <= length - 1; i++)
		printf("%-4d  ", *(p + i));
	printf("\n");
	for (i = 0; i <= length - 1; i++)
		printf("%-4d  ", p[i]);
	printf("\n");
	for (i = 0; i <= length - 1; i++)
		printf("%d   ", *(p++));
	printf("\n");
}