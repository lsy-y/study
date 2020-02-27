#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
#define OK 1
typedef int ElemType;
typedef int Status;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L) {                                         
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}


void CreateList(SqList &L,int n)
{
	int i;
	printf("输入%d个元素:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&L.elem[i]);
	L.length=n;
}     
void DispList(SqList L)
{
	int i;
	if(L.length==0) return;
	for(i=0;i<L.length;i++)
		printf("%4d",L.elem[i]);
	printf("\n");
}        
void MergeList(SqList La,SqList Lb,SqList &Lc)
{
	InitList_Sq(Lc);
	int *pa,*pb,*pc,*pa_last,*pb_last;
	pa=La.elem;
	pb=Lb.elem;
	pc=Lc.elem;
	Lc.listsize=Lc.length=La.length+Lb.length;
	pc=Lc.elem=(ElemType*)malloc((Lc.listsize)*sizeof(ElemType));
	if(!Lc.elem)
		exit(OVERFLOW);
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa<=*pb) 
		    *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;
	while(pb<=pb_last) *pc++=*pb++;
}
int main()
{
	SqList La,Lb,Lc;
	ElemType a,b;
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);
	printf("输入线性表La的长度:");
	scanf("%d",&a);
	printf("创建了线性表La\n");
	CreateList(La,a);
	printf("输入线性表Lb的长度:");
	scanf("%d",&b);
	printf("创建了线性表Lb\n");
	CreateList(Lb,b);
	MergeList(La,Lb,Lc);
	printf("输出归并后的所有元素Lc：");
	DispList(Lc);
}
