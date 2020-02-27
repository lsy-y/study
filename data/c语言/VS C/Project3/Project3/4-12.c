#include<stdio.h>
void main()
{
	int a, b, c, count;
	count = 0;
	for(a=1;a<=4;a++)
		for(b=0;b<=4;b++)
			if (a != b)
			{
				for(c=0;c<=4;c++)
					if (a != b && b != c && a != c)
					{
						printf("%5d", a * 100 + b * 10 + c);
						count = count + 1;
						if (count % 10 == 0 && count != 0)
							printf("\n");
					}
			}
	printf("\n");
}