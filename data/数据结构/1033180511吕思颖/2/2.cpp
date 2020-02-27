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

//从表尾到表头逆向创建n个元素的单链表 
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
//输出单链表
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
//合并 
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LinkList pa;
	LinkList pb;
	LinkList pc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		} 
			}
		pc->next=pa?pa:pb;   //插入剩余片段 
		free(Lb);           //释放lb的头节点 

}
  

main(){
	LinkList La,Lb,Lc;
	printf("创建La，输入5个元素：\n");
	CreateList_L(La,5);
	printf("输出La所有元素！\n");
	OutputList_L(La);
	printf("创建Lb，输入5个元素：\n");
	CreateList_L(Lb,5);
	printf("输出La所有元素！\n");
	OutputList_L(Lb);
	printf("合并La和Lb!\n");
	MergeList_L(La,Lb,Lc);
	printf("输出合并后的元素：\n");
	OutputList_L(Lc);
} 
