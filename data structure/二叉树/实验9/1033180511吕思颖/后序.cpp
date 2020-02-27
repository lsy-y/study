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
	struct BiThrNode *lchild,*rchild,*Parent;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;
BiThrTree pre=NULL;


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
		T->Parent=NULL;
		T->LTag=Link;
		T->RTag=Link;
		CreateBiThrTree(T->lchild);
		if(T->lchild)T->lchild->Parent=T;
		CreateBiThrTree(T->rchild); 
		if(T->rchild)T->rchild->Parent=T;
	}
	return OK;
}

void PostThreading(BiThrTree p)
{
	if(p)
	{
		PostThreading(p->lchild);
		PostThreading(p->rchild);
		if(!p->lchild)
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(pre&&!pre->rchild)
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
	}
}


Status PostOrderTraverse(BiThrTree T,Status (*PrintElement)(TElemType e))
{
	//后序遍历线索二叉树
	if(T)
	{
		BiThrTree p=T;
		pre=NULL;
		while(pre!=T)
		{
			while(p->LTag==Link)
			{
				p=p->lchild;
			}
			while(p&&p->RTag==Thread)
			{
				PrintElement(p->data);
				pre=p;
				p=p->rchild;
			}
			while(pre!=T&&p->rchild==pre)
			{
				PrintElement(p->data);
				pre=p;
				if(pre!=T)
				{
					p=p->Parent;
				} 
			}
			if(p->RTag==Link)
			{
				if(p->rchild==NULL)
				{
					PrintElement(p->data);
					return OK;
				}
				else p=p->rchild;
			}
		}
	}
	return OK;
}


Status main()
{
	BiThrTree P;
	printf("创建线索二叉树，按先序次序输入线索二叉树中结点的值：\n");
	CreateBiThrTree(P);
	PostThreading(P);
	printf("后序遍历线索二叉树，结果是：\n");
	PostOrderTraverse(P,PrintElement);
	printf("\n");
}
