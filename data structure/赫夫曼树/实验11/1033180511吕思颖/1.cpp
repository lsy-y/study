#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;      //��̬��������洢�շ�����
typedef char **HuffmanCode;//��̬��������洢�շ��������
//�����
void Select(HuffmanTree &HT, int u, int &s1, int &s2)
{
	int j;
	j = 1;
	while (j < u&&HT[j].parent != 0) 
		j++;
	s1 = j;
	while (j <= u)
	{
		if (HT[j].parent == 0 && HT[j].weight < HT[s1].weight) s1 = j; //��weight ��С����Ϊs1
		j++;
	}
	HT[s1].parent = u + 1;
	j = 1;
	while (j <= u && HT[j].parent != 0)
		j++;
	s2 = j;
	while (j <= u) 
	{
		if (HT[j].parent == 0 && HT[j].weight < HT[s2].weight) s2 = j;
		j++;
	}
	if (s1 > s2) 
	{
		j = s1; s1 = s2; s2 = j;
	}
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) 
{
	//w���n���ַ���Ȩֵ����>0),�����������HT,�����n���ַ��ĺշ�������HC
	if (n <= 1) return;
	int m = 2 * n - 1, i, j, s1, s2;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); //��1��ʼ
	for (i = 1; i <= n; ++i) 
	{
		//p��ָ���һ
		HT[i].weight = w[i - 1];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}//��ʼ��ÿ��Ҷ�ӽ��
	for (i = n + 1; i <= m; ++i) 
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}//��ʼ��ʣ�µĽ��
	printf("\n�շ������Ĺ������������ʾ:\n");
	printf("HT��̬:\n ���      weight   parent  lchild  rchild");
	for (i = 1; i <= m; i++)
		printf("\n %4d%8d%8d%8d%8d", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	for (i = n + 1; i <= m; ++i) 
	{
		//���շ�����
		//��HT[1..i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2��
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		printf("\nselect: s1=%d,s2=%d\n", s1, s2);
		printf("���    weight   parent   lchild   rchild");
		for (j = 1; j <= i; j++)
			printf("\n%4d%8d%8d%8d%8d", j, HT[j].weight, HT[j].parent, HT[j].lchild, HT[j].rchild);
	}
	printf("\n");
	//---��Ҷ�ӵ���������ÿ���ַ��ĺշ�������---
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	char *cd; unsigned int c, f;
	int start;
	cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i) 
	{
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)//��Ҷ�ӵ������������
			if (HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
	printf("��������ĺշ�������:\n");
	for (i = 1; i <= n; i++)
		printf("%2d    %s\n", i, HC[i]);
}//HuffmanCoding
int main() 
{
	int w[] = { 5,29,7,8,14,23,3,11 }, n = 8;
	HuffmanTree HT;
	HuffmanCode HC;
	HuffmanCoding(HT, HC, w, n);
}

