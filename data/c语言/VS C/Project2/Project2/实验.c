#include<stdio.h>
int main()
{
	const int PRICE = 030;
	short sVar = 0x20;
	unsigned int iVar = 100;
	long lVar = 1234l;
	float fVar = 331.45f;
	long double dVar = 8.44e+11;
	char cVar = 'w';
	int boolVar1 = 6 > 7;
	int boolVar2 = 6 < 5;
	printf("constant PRICE=%d\n", PRICE);
	printf("svar=%d\n", sVar);
	printf("ivar=%d\n", iVar);
	printf("fvar=%f\n", fVar);
	printf("dvar=%e\n", dVar);
	printf("cvar=%c\n", cVar);
	printf("boolVar1=%d\n", boolVar1);
	printf("boolVar2=%d\n", boolVar2);
	printt("%s\n", "I am a student");
	return 0;
}