#include<stdio.h>
int main()
{
	const int PRICE = 030;
	short sVar = 0x20;
	unsigned int iVar = 100, *p = &iVar;
	long lVar = 1234l;
	float fVar = 331.45f;
	long double dVar = 8.44e+11;
	char cVar = 'w';
	int boolVar1 = 6 > 7;
	int boolVar2 = 6 > 5;
	printf("constant PRICE=%d\n", PRICE);
	printf("svar=%d\n", sVar);
	printf("ivar=%d\n", iVar);
	printf("Address of ivar=%d,   %d\n", &iVar, p);
	printf("Content of ivar=%d,   %d\n", iVar, *p);
	*p = *p + 1;
	printf("After add 1,Content of iVar=%d,  %d\n", iVar, *p);
	printf("fvar=%f\n", fVar);
	printf("dvar=%f\n", dVar);
	printf("cvar=%f\n", cVar);
	printf("boolVar1=%d\n", boolVar1);
	printf("boolVar2=%d\n", boolVar2);
	printf("%s\n", "I am a student");
	return 0;
}