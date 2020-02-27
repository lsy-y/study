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
int Nodenum=0;//统计树的节点个数 
int Count=0;//统计树中叶子节点的个数

Status CreateCSTree(CSTree &T)
{
	//算法6.4
	//按先序次序输入树中节点的值（一个字符），#字符表示空树，
	//构造二叉链表表示的树T
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
	//算法6.1
	//采用二叉链表储存结构
	//先根遍历树T的递归算法
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
	//采用二叉链表存储结构
	//后根遍历树T的递归算法
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

//用递归方法求树的深度 
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
	//统计树的节点的个数
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
	//输出树的叶子节点，并统计叶子节点个数 
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
	//复制树
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
    printf("创建树，按先序次序输入树中结点的值：\n");
    CreateCSTree(T);
    NodeCountCSTree(T);
    printf("树的结点个数为:%d\n",Nodenum);
    printf("树的深度为:%d\n",CSTreeDepth(T));
    printf("先根遍历树，结果是:\n");
    PreOrderTraverse(T);
    printf("\n");
    printf("后根遍历树，结果是:\n");
    PostOrderTraverse(T);
    printf("\n");
    printf("输出树的叶子结点:\n");
    LeafCountCSTree(T);
    printf("\n");
    printf("统计树的叶子结点个数:%d\n",Count);
    if(CopyCSTree(T,B)==OK) printf("成功复制树T到树B!\n");
    if(DestroyCSTree(T)==OK) printf("成功销毁树T!\n");
    if(ClearCSTree(T)==OK) printf("将树T置为空树！\n");
    printf("先根遍历树，结果是:\n");
    PreOrderTraverse(B);
    printf("\n");
    printf("后根遍历树，结果是:\n");
    PostOrderTraverse(B);
    printf("\n");
}

