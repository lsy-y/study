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


void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);//������������
		if(!p->lchild)//��ǰ������ 
		{
			p->LTag=Thread;
			p->lchild=pre; 
		} 
		if(!pre->rchild)//������� 
		{
			pre->RTag=Thread;
			pre->rchild=p; 
		}
		pre=p;
		InThreading(p->rchild);//������������ 
	}
}




Status InOrderThreading(BiThrTree &Thrt,BiThrTree T)
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
		InThreading(T);
		pre->rchild=Thrt;
		pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return OK;
}



Status InOrderTraverse_Thr(BiThrTree T,Status (*PrintElement)(TElemType e))
{
	//����������������� 
	BiThrTree p;
	p=T->lchild;//pָ������ 
	while(p!=T)
	{
		while(p->LTag==Link)p=p->lchild;
		if(!PrintElement(p->data))return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			PrintElement(p->data);//���ʺ�̽�� 
		}
		p=p->rchild; 
	}
	return OK;
} 


Status main()
{
	BiThrTree T,Thrt;
	printf("����������������������������������������н���ֵ��\n");
	CreateBiThrTree(T);
	if(InOrderThreading(Thrt,T)==OK)
		printf("�ɹ����������������б�\n");
	printf("�����������������������ǣ�\n");
	InOrderTraverse_Thr(Thrt,PrintElement);
	printf("\n");
}
