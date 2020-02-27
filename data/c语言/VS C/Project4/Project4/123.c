#include<stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];            /*���˳��Ԫ��*/
	int length;                        /*���˳���ĳ���*/
}SqList;


//��ʼ��˳���
void InitList(SqList &L)
{
	L.length = 0;
}


//����n��Ԫ�ص�˳���
void CreateList(SqList &L, int n)
{
	int i;
	printf("����%d��Ԫ�أ�\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &L.data[i]);
	printf("\n");
	L.length = n;
}

//�жϿձ�
int ListEmpty(SqList L)
{
	return(L.length == 0);
}

//��˳�����
int ListLength(SqList L)
{
	return(L.length);
}


//���˳���
void DispLsit(SqList L)
{
	int i;
	if (L.length == 0) return;
	for (i = 0; i < L.length; i++)
		printf("%d", L.data[i]);
	printf("\n");
}

//ȡ˳���λ��i��Ԫ��ֵ
int GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length) return 0;
	e = L.data[i - 1];
	return 1;
}

//��˳����в���ֵΪe��Ԫ��λ��
int LocataElem(SqList L, ElemType e)
{
	int i = 1;
	while (i <= L.length&&L.data[i - 1] != e)
		i++;
	if (i <= L.length)
		return i;
	else return 0;
}

//��˳����в���һ��Ԫ��
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

//��˳�����ɾ��һ��Ԫ��
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
		printf("˳���Ϊ�գ�\n");
	printf("����˳���");
	CreateList(L, 5);
	printf("���˳�������Ԫ�أ�\n");
	DispLsit(L);
	printf("���˳�����!\n");
	printf("ListLength(L)=%d\n", ListLength(L));
	printf("�ж�˳����Ƿ�Ϊ�գ�\n");
	printf("ListEmpty(L)=%d\n", ListEmpty(L));
	printf("���˳����3��λ��Ԫ�ص�dd!\n");
	GetElem(L, 3, dd);
	printf("dd=%d\n", dd);
	printf("����Ԫ��a��");
	scanf("%d", &a);
	printf("Ԫ��%d��˳����λ��Ϊ��%d\n", a, LocataElem(L, a));
	printf("����Ԫ��b��");
	scanf("%d", &b);
	printf("��˳����4��λ�ò���%d!\n", b);
	ListInsert(L, 4, b);
	printf("������������˳�������Ԫ�أ�\n");
	DispLsit(L);
	printf("ɾ��˳����3��λ�õ�Ԫ�أ�\n");
	ListDelete(L, 3, dd);
	printf("���ɾ��������˳�������Ԫ�أ�\n");
	DispLsit(L);
}
