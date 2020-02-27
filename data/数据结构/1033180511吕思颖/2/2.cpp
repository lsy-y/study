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

//�ӱ�β����ͷ���򴴽�n��Ԫ�صĵ����� 
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
//���������
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
//�ϲ� 
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
		pc->next=pa?pa:pb;   //����ʣ��Ƭ�� 
		free(Lb);           //�ͷ�lb��ͷ�ڵ� 

}
  

main(){
	LinkList La,Lb,Lc;
	printf("����La������5��Ԫ�أ�\n");
	CreateList_L(La,5);
	printf("���La����Ԫ�أ�\n");
	OutputList_L(La);
	printf("����Lb������5��Ԫ�أ�\n");
	CreateList_L(Lb,5);
	printf("���La����Ԫ�أ�\n");
	OutputList_L(Lb);
	printf("�ϲ�La��Lb!\n");
	MergeList_L(La,Lb,Lc);
	printf("����ϲ����Ԫ�أ�\n");
	OutputList_L(Lc);
} 
