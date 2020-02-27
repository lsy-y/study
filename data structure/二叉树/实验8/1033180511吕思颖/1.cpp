#include<stdio.h>
#include<stdlib.h> 
#include<stdarg.h>
#include<math.h> 
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
typedef struct BITNODE
{
	char data;
	struct BITNODE *left,*right;
}BITNODE,*BITREE;

int num=0;
int c=0;
int create(BITREE &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch==' ')T=NULL;
	else
	{
		if(!(T=(BITNODE*)malloc(sizeof(BITNODE))))exit(OVERFLOW);
		T->data=ch;
		create(T->left);
		create(T->right);
	}
	return OK;
}//createtree

int preorder(BITREE T)
{
	if(T)
	{
		printf("%c",T->data);
		if(preorder(T->left));
			if(preorder(T->right))return OK;
		return ERROR;
	}
	else return OK;
}//PreORderTraverse

int inorder(BITREE T)
{
	int m=0;
	if(T)
	{
		if(inorder(T->left))m=1;
		printf("%c",T->data);
		if(m)
			if(inorder(T->right))return OK;
		return ERROR;
	}
	else return OK;
}//InOrderTraverse

int postorder(BITREE T)
{
	if(T)
	{
		if(postorder(T->left))
			if(postorder(T->right))
			{
				printf("%c",T->data);
				return OK;
			}
		return ERROR;
	}
	else return OK;
}//PostOrderTraverse

int Depth(BITREE T)
{
	int leftDepth,rightDepth;
	if(T==NULL)return 0;
	else
	{
		leftDepth=Depth(T->left);
		rightDepth=Depth(T->right);
		if(leftDepth>=rightDepth)return leftDepth+1;
		else return rightDepth+1; 
	}
}

int NodeCount(BITREE T)
{
	if(T)
	{
		num++;
		if(NodeCount(T->left))
			if(NodeCount(T->right))return OK;
		return ERROR;
	}
	else return OK;
}//NodeCount



int LeftCount(BITREE T)
{
	if(T)
	{
		if(T->left==NULL&&T->right==NULL)
		{
			printf("%c",T->data);
			c=c+1;
		}
		if(LeftCount(T->left))
			if(LeftCount(T->right))return OK;
		return ERROR; 
	}
	else return OK;
}//LeafCount


int Exchange(BITREE &T)
{
	BITREE p;
	if(T)
	{
		if(T->left||T->right)
		{
			p=T->left;
			T->left=T->right;
			T->right=p;
		}
		if(Exchange(T->left))
			if(Exchange(T->right))return OK;
		return ERROR;
	}
	else return OK;
}//ExchangeBiTree

int copy(BITREE T,BITREE &B)
{
	if(T==NULL)B=NULL;
	else
	{
		if(!(B=(BITNODE*)malloc(sizeof(BITNODE))))exit(OVERFLOW);
		B->data=T->data;
		copy(T->left,B->left);
		copy(T->right,B->right);
	}
	return OK;
}//CopyBiTree

int destroy(BITREE &T)
{
	if(T)
	{
		destroy(T->left);
		destroy(T->right);
		free(T);
	}
	return OK;
}//DestroyTree

int clear(BITREE &T)
{
	if(T)
	{
		T=NULL;
	}
	return OK;
}//ClearTree

int main()
{
	BITREE T,B;
	printf("�������������������������������нڵ��ֵ��\n");
	create(T);
	NodeCount(T);
	printf("�������Ľڵ����Ϊ��%d\n",num);
	printf("�����������Ϊ��%d\n",Depth(T));
	printf("�������������������ǣ�\n");
	preorder(T);
	printf("\n");
	printf("�������������������ǣ�\n");
	inorder(T);
	printf("\n");
	printf("�������������������ǣ�\n");
	postorder(T);
	printf("\n");
	printf("�����������Ҷ�ӽڵ㣺\n");
	LeftCount(T);
	printf("\n");
	printf("ͳ�ƶ�������Ҷ�ӽڵ������%d\n",c);
	printf("���������������нڵ������������\n");
	Exchange(T);
	if(copy(T,B)==OK)printf("�ɹ����ƶ�����T��������B��\n");
	if(destroy(T)==OK)printf("�ɹ����ٶ�����T!\n");
	if(clear(T)==OK)printf("��������T��Ϊ������\n");
	printf("�������������B������ǣ�\n");
	preorder(T);
	printf("\n");
	printf("�������������B������ǣ�\n");
	inorder(T);
	printf("\n");
	printf("�������������B������ǣ�\n");
	postorder(T);
	printf("\n");
}
