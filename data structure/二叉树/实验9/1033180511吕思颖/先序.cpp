#include<stdio.h>
#include<stdlib.h> 
#include<stdarg.h>
#include<math.h> 
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
typedef char TElemType;
typedef int Status;
typedef enum PointerTag
{
	Link,Thread
};
typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

BiThrTree pre;


Status PrintElement(TElemType e)
{
	//���Ԫ��e��ֵ 
	printf("%-4c",e);
	return OK;
}

Status CreateBiThrTree(BiThrTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')T=NULL;
	else
	{
		if(!(T=(BiThrNode*)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
		T->data=ch;
		T->LTag=Link;
		T->RTag=Link;
		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild); 
	}
	return OK;
}

void PreThreading(BiThrTree p)
{
	if(p)
	{
		if(!p->lchild)
		{
			p->lchild=pre;
			p->LTag=Thread; 
		}
		if(pre!=NULL&&!pre->rchild)
		{
			pre->rchild=p;
			pre->RTag=Thread;
		}
		pre=p;
		if(p->LTag==Link)
		{
			PreThreading(p->lchild);
		}
		if(p->RTag==Link)
		{
			PreThreading(p->rchild);
		}
	}
} 

Status PreOrderThreading(BiThrTree &Thrt,BiThrTree T)
{
	//�����������������T,������������������Thrtָ��ͷ���
	if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
	Thrt->LTag=Link;
	Thrt->RTag=Thread;//��ͷ���
	Thrt->rchild=Thrt; 
	if(!T)Thrt->lchild=Thrt;
	else
	{
		Thrt->lchild=T;
		pre=Thrt;
		PreThreading(T);
		pre->rchild=Thrt;
		pre->RTag=Thread;
		Thrt->rchild=pre;
		
	}
	return OK; 
}

Status PreOrderTraverse_Thr(BiThrTree HeadNode,Status (*PrintElement)(TElemType e))
{
	//�����������������
	BiThrTree p=HeadNode->lchild;
	while(p!=HeadNode)
	{
		while(p->lchild!=NULL&&p->LTag==Link)
		{
			PrintElement(p->data);
			p=p->lchild;
			
		}
		PrintElement(p->data);
		if(p->LTag==Thread)
			p=p->rchild;
	}
	return OK;
}


Status main()
{
	BiThrTree T,Thrt;
	printf("����������������������������������������н���ֵ��\n");
	CreateBiThrTree(T);
	if(PreOrderThreading(Thrt,T)==OK)
		printf("�ɹ����������������б�\n");
	printf("�����������������������ǣ�\n");
	PreOrderTraverse_Thr(Thrt,PrintElement);
	printf("\n");
}
