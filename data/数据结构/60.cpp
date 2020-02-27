#include <stdio.h>
#include<math.h>

int f(int a)
{
	int sum = 0, x;
	for (; a != 0;)
	{
		x = a % 10;
		sum += x;
		a = a / 10;
	}
	return sum;
}
int main()
{
	int n, a, b,m, aa[30][1], i,t1,x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &aa[i][1]);

	}
	for (i = 0; i < n; i++)
	{
		m = f(aa[i][1]);
		x=aa[i][1]/2;
		for (a = 1; a < x && a >= 1e-6;a++)
		{
			b = aa[i][1] - a;
			t1 = f(a) + f(b);
			if (t1 > m)
				m = t1;
		}
		printf("%d\n", m);
	}
}

















#include <stdio.h>
#include<math.h>

int f(int a)
{
	int sum = 0, x;
	for (; a != 0;)
	{
		x = a % 10;
		sum += x;
		a = a / 10;
	}
	return sum;
}
void main()
{
	int n, a, b,m, aa[30][1], i,t1,x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &aa[i][1]);

	}
	for (i = 0; i < n; i++)
	{
		m = f(aa[i][1]);
		x=aa[i][1]/2;
		for (a = 1; a < x && a >= 1e-6;a++)
		{
			b = aa[i][1] - a;
			t1 = f(a) + f(b);
			if (t1 > m)
				m = t1;
		}
		printf("%d\n", m);
	}
}
