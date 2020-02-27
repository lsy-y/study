#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//�ӱ�β����ͷ���򴴽�n��Ԫ�صĵ����� 
void CreateList_L(LinkList &L,int n)
{
	LinkList p;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=n;i>0;--i)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}
//���������
Status OutputList_L(LinkList L)
{
	LinkList p=L->next;
	if(!p)return ERROR;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
} 

Status GetElem_L(LinkList &L,int i,ElemType &e)
{
	LinkList p;
	int j;
	p=L->next;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)return ERROR;
	e=p->data;
	return OK;
} 

//�������в���һ��Ԫ��
Status ListInsert_L(LinkList &L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p=L;
	j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j<i-1)return ERROR;
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
} 
 
 //�ӵ�������ɾ��һ��Ԫ��
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	int j;
	LinkList p,q;
	p=L;
	j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j<i-1)return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}

int main()
{
	ElemType b,d,dd;
	LinkList L;
	printf("��������������5��Ԫ�أ�\n");
	CreateList_L(L,5);
	printf("�������������Ԫ�أ�\n");
	OutputList_L(L);
	printf("����������2��λ��Ԫ�ص�dd��\n");
	GetElem_L(L,2,dd);
	printf("dd=%d\n",dd);
	printf("����Ԫ��b:");
	scanf("%d",&b);
	printf("�ڵ������4��λ�ò��뵽%d!\n",b);
	ListInsert_L(L,4,b);
	printf("��������������������Ԫ�أ�\n");
	OutputList_L(L);
	printf("ɾ���������3��λ�õ�Ԫ�أ�\n");
	ListDelete_L(L,3,d);
	printf("���ɾ����������������Ԫ�أ�\n");
	OutputList_L(L); 
}  
