#include<stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];            /*存放顺序元素*/
	int length;                        /*存放顺序表的长度*/
}SqList;


//初始化顺序表
void InitList(SqList &L)
{
	L.length = 0;
}


//创建n个元素的顺序表
void CreateList(SqList &L, int n)
{
	int i;
	printf("输入%d个元素：\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &L.data[i]);
	printf("\n");
	L.length = n;
}

//判断空表
int ListEmpty(SqList L)
{
	return(L.length == 0);
}

//求顺序表长度
int ListLength(SqList L)
{
	return(L.length);
}


//输出顺序表
void DispLsit(SqList L)
{
	int i;
	if (L.length == 0) return;
	for (i = 0; i < L.length; i++)
		printf("%d", L.data[i]);
	printf("\n");
}

//取顺序表位置i的元素值
int GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length) return 0;
	e = L.data[i - 1];
	return 1;
}

//在顺序表中查找值为e的元素位置
int LocataElem(SqList L, ElemType e)
{
	int i = 1;
	while (i <= L.length&&L.data[i - 1] != e)
		i++;
	if (i <= L.length)
		return i;
	else return 0;
}

//向顺序表中插入一个元素
int ListInsert(SqList &L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L.length + 1)return 0;
	for (j = L.length - 1; i >= i - 1; j--)
		L.data[j + 1] = L.data[j];
	L.data[i - 1] = e;
	++L.length;
	return 1;
}

//从顺序表中删除一个元素
int ListDelete(SqList &L, int i, ElemType &e)
{
	int j;
	if (i<1 || i>L.length)
		return 0;
	e = L.data[i - 1];
	for (j = i - 1; j < L.length - 1; j++)
		L.data[j] = L.data[j + 1];
	--L.length;
	return 1;
}

main()
{
	ElemType dd, a, b;
	SqList L;
	InitList(L);
	if (ListEmpty(L))
		printf("顺序表为空！\n");
	printf("创建顺序表！");
	CreateList(L, 5);
	printf("输出顺序表所有元素！\n");
	DispLsit(L);
	printf("输出顺序表长度!\n");
	printf("ListLength(L)=%d\n", ListLength(L));
	printf("判断顺序表是否为空！\n");
	printf("ListEmpty(L)=%d\n", ListEmpty(L));
	printf("输出顺序表第3个位置元素到dd!\n");
	GetElem(L, 3, dd);
	printf("dd=%d\n", dd);
	printf("查找元素a：");
	scanf("%d", &a);
	printf("元素%d在顺序表的位置为：%d\n", a, LocataElem(L, a));
	printf("插入元素b：");
	scanf("%d", &b);
	printf("在顺序表第4个位置插入%d!\n", b);
	ListInsert(L, 4, b);
	printf("输出插入操作后顺序表所有元素！\n");
	DispLsit(L);
	printf("删除顺序表第3个位置的元素！\n");
	ListDelete(L, 3, dd);
	printf("输出删除操作后顺序表所有元素！\n");
	DispLsit(L);
}
