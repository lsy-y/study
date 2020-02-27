#include<stdio.h>
void f(unsigned w, unsigned *p) 
{
	unsigned s = 0;    //存放结果
	unsigned b = 1;    //存放10的幂
	unsigned d = 0;	 //存放从依次取从低位到高位的数字
	while (w > 10) {    //最高位数字不取
		if (w / 10)
			d = w % 10;
		s = s + d * b;
		b = b * 10;
		w = w / 10;
	}
	return *p = s;
}
void main() 
{
	int w, v;
	scanf("%d", &w);
	f(w, &v);
	printf("%d\n", v);
}

