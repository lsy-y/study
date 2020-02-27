#include<stdio.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Elemtype;
typedef int Status;
typedef struct
{
	Elemtype *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{
	L.elem = (Elemtype *)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;

}


void CreateList(SqList &L,int n)
{
    int i;
    printf("输入%d个元素：\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&L.elem[i]);
    printf("\n");
    L.length=n;
}

void DispLsit(SqList L)
{
    int i;
    if(L.length==0) return;
    for(i=0;i<L.length;i++)
        printf("%d",L.elem[i]);
    printf("\n");
}

//2.3
Status ListInsert_Sq(SqList &L, int i, Elemtype e)
{
	int *newcase, q, p;
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		newcase = (Elemtype *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(Elemtype));
		if (!newcase)
			exit(OVERFLOW);
		L.elem = newcase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p)
        *(p+1)=*p;
    *q=e;
    ++L.length;
    return OK;
}

//2.4
Status ListDelete_Sq(SqList &L,int i,Elemtype &e)
{
    int p,q;
	if((i<1)||(i>L.length))
        return ERROR;
	p=&(L.elem[i-1]);
	e=*p;
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)
		*(p-1)=*p;
	--L.length;
	return OK;
}

main()
{
	SqList L;
	int n,b;
	InitList_Sq(L);
	printf("创建顺序表");
	scanf("%d",&n);
	CreateList(L,n);
	printf("插入元素b：");
	scanf("%d",&b);
	printf("在顺序表第3个位置插入%d",b);
	ListInsert_Sq(L,3,b);
	DispLsit(L);
	//printf("删除元素b");
	//scanf("%d",&b);
	//printf("删除顺序表中第3个")
}
