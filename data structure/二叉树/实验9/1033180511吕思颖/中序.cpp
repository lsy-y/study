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


void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);//左子树线索化
		if(!p->lchild)//建前驱线索 
		{
			p->LTag=Thread;
			p->lchild=pre; 
		} 
		if(!pre->rchild)//后继线索 
		{
			pre->RTag=Thread;
			pre->rchild=p; 
		}
		pre=p;
		InThreading(p->rchild);//右子树线索化 
	}
}




Status InOrderThreading(BiThrTree &Thrt,BiThrTree T)
{
	//中序遍历二叉线索树T,并将其中序线索化，Thrt指向头结点
	if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))exit(OVERFLOW);
	Thrt->LTag=Link;
	Thrt->RTag=Thread;//建头结点
	Thrt->rchild=Thrt; 
	if(!T)Thrt->lchild=Thrt;
	else
	{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;
		pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return OK;
}



Status InOrderTraverse_Thr(BiThrTree T,Status (*PrintElement)(TElemType e))
{
	//中序遍历线索二叉树 
	BiThrTree p;
	p=T->lchild;//p指向根结点 
	while(p!=T)
	{
		while(p->LTag==Link)p=p->lchild;
		if(!PrintElement(p->data))return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			PrintElement(p->data);//访问后继结点 
		}
		p=p->rchild; 
	}
	return OK;
} 


Status main()
{
	BiThrTree T,Thrt;
	printf("创建线索二叉树，按先序次序输入线索二叉树中结点的值：\n");
	CreateBiThrTree(T);
	if(InOrderThreading(Thrt,T)==OK)
		printf("成功建立中序线索化列表！\n");
	printf("中序遍历线索二叉树，结果是：\n");
	InOrderTraverse_Thr(Thrt,PrintElement);
	printf("\n");
}
