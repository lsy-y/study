#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVREFLOW -2
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

Status CreatList(LinkList &L,int n)
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

Status OutputList(LinkList &L)
{
	LinkList p=L->next;
	if(p==NULL)return ERROR;
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

Status SortList(LinkList &L)
{
	LinkList p,q,pre;
	p=L->next;
	pre=L;
	if(!p)return ERROR;
	while(p!=NULL)
	{	
		if((p->data)<0)
		{
			q=p;
			p=p->next;
            q->next=L->next;
            L->next=q;
			pre->next=p;
		}
		else
		{
			p=p->next;
			pre=pre->next;
		}
	}
	return OK;
}

int main()
{
	LinkList L;
	printf("[创建线性链表（取值属于整数）]\n");
	printf("创建L，输入5个数字:");
	CreatList(L,5);
	OutputList(L);
	SortList(L);
	printf("输出排序后的线性链表：");
	OutputList(L); 
}
