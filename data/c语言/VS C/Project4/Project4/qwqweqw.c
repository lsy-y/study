#include<stdio.h>
void f(unsigned w, unsigned *p) 
{
	unsigned s = 0;    //��Ž��
	unsigned b = 1;    //���10����
	unsigned d = 0;	 //��Ŵ�����ȡ�ӵ�λ����λ������
	while (w > 10) {    //���λ���ֲ�ȡ
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

