#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//Create the linked list L with n elements from head to rear
void CreateList_L(LinkList &L,int n){
	LinkList p,q;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
	q=L;                                    
	srand(time(0));
	for(i=1;i<=n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=rand()%90+10;
		q->next=p;
		q=p;
	}
	p->next=NULL;
} 

//Output the linked list
Status OutputList_L(LinkList L){
	LinkList p=L->next;
	if(p==NULL)return ERROR;
	while(p!=NULL){
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

//Data elements of the linked list are converse
Status ListConverse_L(LinkList &L){
	LinkList p,q;
	p=L->next;
	L->next=NULL;
	while(p){
		q=p;
		p=p->next;
		q->next=L->next;
		L->next=q;
	}
	return OK;
}


int main(){
	LinkList L;
	printf("Create the linked list,");
	CreateList_L(L,5);
	printf("Output all elements of the linked list!\n");
	OutputList_L(L);
	ListConverse_L(L);
	printf("Output all converse elements of the linked list!\n");
	OutputList_L(L);
}
