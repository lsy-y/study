#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define FALSE 0
#define TRUE 1
#define LT(a,b)(a<b)
#define MAXSIZE 20
#define EQ(a,b)(a==b)
typedef struct
{
	int key;
	int otherinfo;
}RedType;

typedef struct
{
	RedType r[MAXSIZE + 1];
	int length;			
}SqList;

//初始化顺序表
int InitList(SqList &L)
{
	L.length = 0;
	return OK;
}

//创建n个元素的顺序表
int CreatList(SqList &L, int n)
{
	printf("输入%d个元素：\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &L.r[i].key);
		++L.length;
	}
	if (L.length == 0)return ERROR;
	return OK;
}

//输出顺序表
int DispList(SqList &L)
{
	if (L.length == 0)return ERROR;
	for (int i = 0; i < L.length; i++)
	{
		printf("%d", L.r[i].key);
	}
	printf("\n");
	return OK;
}

int InsertSort(SqList &L)
{
	for (i = 2; i <= L.length; ++i)
	{
		if (LT(L.r[i].key, L.r[i - 1].key)
		{
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
				for (int j = i-2;LT(L.r[0].key,L.r[j].key); i++)
				{
					L.r[j+1]=L.r[j];
				}
			L.r[j+1]=L.r[0];
		}
	}
}

int main()
{
	SqList L;
	int n;
	printf("初始化顺序表：");
	InitList(L);
	if (L.length == 0)
		printf("顺序表为空!\n");
	printf("输入顺序表的元素个数：");
	scanf("%d", &n);
	CreatList(L, n);
	printf("输出%d个元素的顺序表如下：\n");
	DispList(L);
	InsertSort(L);
	printf("直接插入排序结果如下：\n");
	DispList(L);

}