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
	//输出元素e的值 
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
	//先序遍历二叉线索树T,并将其先序线索化，Thrt指向头结点
	if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
	Thrt->LTag=Link;
	Thrt->RTag=Thread;//建头结点
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
	//先序遍历线索二叉树
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
	printf("创建线索二叉树，按先序次序输入线索二叉树中结点的值：\n");
	CreateBiThrTree(T);
	if(PreOrderThreading(Thrt,T)==OK)
		printf("成功建立先序线索化列表！\n");
	printf("先序遍历线索二叉树，结果是：\n");
	PreOrderTraverse_Thr(Thrt,PrintElement);
	printf("\n");
}
