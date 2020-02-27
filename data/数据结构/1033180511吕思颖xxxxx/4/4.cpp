#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FLASE 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList; 

//Create the link list L with n elements from head to rear
void Createlist_L(LinkList &L,int n){
	LinkList q,p;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
	q=L;
	srand(time(0));
	for(i=0;i<=n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=rand()%90+10;
		q->next=p;
		q=p;
	}
	p->next=NULL;
}

//Output the linked list
Status Outputlist_L(LinkList L){
	LinkList p=L->next;
	if(p==NULL)return ERROR;
	while(p!=NULL){
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

//Sort the linked list
Status Sortlist_L(LinkList L){
	LinkList p,q;
	int temp;
	p=L->next;
	while(p->next){
		q=L->next;
		while(q->next){
			if(q->data<q->next->data){
				temp=q->data;
				q->data=q->next->data;
				q->next->data=temp;		
			}	
			q=q->next;
		}
		p=p->next;
	}
	return OK; 
}


int main(){
	LinkList L;
	printf("Create a list:");
	Createlist_L(L,3);
	printf("\n");
	printf("Output a list:");
	Outputlist_L(L);
	printf("\n");
	printf("°´·ÇµÝ¼õÊä³ö£º");
	Sortlist_L(L);
	Outputlist_L(L); 
}



