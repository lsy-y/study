#include<stdio.h>
void main()
{
	char a, b, c;
	char A, B, C;
	scanf("%c %c %c", &A, &B, &C);
	if (A <= C)
	{
		if (B >= C)
			printf("%c %c %c", A, C, B);
		else if (B <= A)
			printf("%c %c %c", B, A, C);
		else printf("%c %c %c", A, B, C);
	}
	else if (A > C)
	{
		if (B < C)
			printf("%c %c %c", B, C, A);
		else if (B > A)
			printf("%c %c %c", C, A, B);
		else printf("%c %c %c", C, B, A);
	}
}