#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;
typedef int Status;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//构造一个空的线性表L
Status InitList_Sq(SqList &L){
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)return OVERFLOW;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
} 

//Create the sequential list if n elements
Status ListCreate_Sq(SqList &L,int n){
	int i;
	srand(time(0));
	for(i=0;i<n;i++){
		L.elem[i]=rand()%90+10;
		++L.length;
	}
	printf("\n");
	if(L.length==0)return ERROR;
	return OK;
}

//Output the list
Status ListOutput_Sq(SqList L){
	int i;
	if(L.length==0)return ERROR;
	for(i=0;i<L.length;i++)
    	printf("%-4d",L.elem[i]);
	printf("\n");
	return OK;
}

//Data elements of the sequential list are converse
Status ListConverse_Sq(SqList &L){
	ElemType temp;
	int i;
	if(L.length==0)return ERROR;
	for(i=0;i<(int)L.length/2;i++){
		temp=L.elem[i];
		L.elem[i]=L.elem[L.length-i-1];
		L.elem[L.length-i-1]=temp;
	}
	return OK;
} 

int main(){
	SqList L;
	printf("Initialize the sequential list!");
	InitList_Sq(L);
	if(L.length==0)
    	printf("The sequential list is empty!\n");
	printf("Create the sequential list,");
	ListCreate_Sq(L,5);
	printf("Output all elements of the sequential list!\n");
	ListOutput_Sq(L);
	ListConverse_Sq(L);
	printf("Output all converse elements of the sequential list\n");
	ListOutput_Sq(L);
	return OK;
}

