#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;
typedef struct CSNode
{
	ElemType data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
int Nodenum=0;//ͳ�����Ľڵ���� 
int Count=0;//ͳ������Ҷ�ӽڵ�ĸ���

Status CreateCSTree(CSTree &T)
{
	//�㷨6.4
	//����������������нڵ��ֵ��һ���ַ�����#�ַ���ʾ������
	//������������ʾ����T
	ElemType ch;
	scanf("%c",&ch);
	if(ch=='#')T=NULL;
	else
	{
		if(!(T=(CSNode*)malloc(sizeof(CSNode))))exit(OVERFLOW);
		T->data=ch;
		CreateCSTree(T->firstchild);
		CreateCSTree(T->nextsibling);
	} 
	return OK;
} 


Status PreOrderTraverse(CSTree T)
{
	//�㷨6.1
	//���ö���������ṹ
	//�ȸ�������T�ĵݹ��㷨
	if(T)
	{
		printf("%c",T->data);
		if(PreOrderTraverse(T->firstchild))
			if(PreOrderTraverse(T->nextsibling))return OK;
		return ERROR;
	} 
	else return OK;
} 

Status PostOrderTraverse(CSTree T)
{
	//���ö�������洢�ṹ
	//���������T�ĵݹ��㷨
	int m=0;
	if(T)
	{
		if(PostOrderTraverse(T->firstchild))m=1;
		printf("%c",T->data);
		if(m)
		{
			if(PostOrderTraverse(T->nextsibling))return OK;
		}
		return ERROR;
	} 
	else return OK;
}

//�õݹ鷽����������� 
Status CSTreeDepth(CSTree T)
{
	int h1,h2;
	if(T==NULL)return 0;
	else
	{
		h1=CSTreeDepth(T->firstchild);
		h2=CSTreeDepth(T->nextsibling);
		if(h1+1>=h2)return h1+1;
		else return h2;
	}
}


Status NodeCountCSTree(CSTree T)
{
	//ͳ�����Ľڵ�ĸ���
	if(T)
	{
		Nodenum++;
		if(NodeCountCSTree(T->firstchild))
			if(NodeCountCSTree(T->nextsibling))return OK;
		return ERROR;
	} 
	else return OK;
}//NodeCountCSTree


Status LeafCountCSTree(CSTree T)
{
	//�������Ҷ�ӽڵ㣬��ͳ��Ҷ�ӽڵ���� 
	if(T)
	{
		if(T->firstchild==NULL&&T->nextsibling==NULL)
		{
			printf("%c",T->data);
			Count++;
		}
		if(LeafCountCSTree(T->firstchild))
            if(LeafCountCSTree(T->nextsibling)) return OK;
        return ERROR;
    }
	else return OK;
}



Status CopyCSTree(CSTree T,CSTree &B)
{
	//������
	if(T==NULL)
		B=NULL;
	else
	{
		if(!(B=(CSNode*)malloc(sizeof(CSNode))))exit(OVERFLOW);
		B->data=T->data;
		CopyCSTree(T->firstchild,B->firstchild);
		CopyCSTree(T->nextsibling,B->nextsibling);
	} 
	return OK;
}


Status DestroyCSTree(CSTree &T){
    if(T){
        DestroyCSTree(T->firstchild);
        DestroyCSTree(T->nextsibling);
        free(T);
    }
    return OK;
}//DestroyCSTree




Status ClearCSTree(CSTree &T){
    if(T){
        T=NULL;
    }
    return OK;
}//ClearCSTree



int main(){
    CSTree T,B;
    printf("������������������������н���ֵ��\n");
    CreateCSTree(T);
    NodeCountCSTree(T);
    printf("���Ľ�����Ϊ:%d\n",Nodenum);
    printf("�������Ϊ:%d\n",CSTreeDepth(T));
    printf("�ȸ��������������:\n");
    PreOrderTraverse(T);
    printf("\n");
    printf("����������������:\n");
    PostOrderTraverse(T);
    printf("\n");
    printf("�������Ҷ�ӽ��:\n");
    LeafCountCSTree(T);
    printf("\n");
    printf("ͳ������Ҷ�ӽ�����:%d\n",Count);
    if(CopyCSTree(T,B)==OK) printf("�ɹ�������T����B!\n");
    if(DestroyCSTree(T)==OK) printf("�ɹ�������T!\n");
    if(ClearCSTree(T)==OK) printf("����T��Ϊ������\n");
    printf("�ȸ��������������:\n");
    PreOrderTraverse(B);
    printf("\n");
    printf("����������������:\n");
    PostOrderTraverse(B);
    printf("\n");
}

