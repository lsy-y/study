#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define OK 1
#define TRUE 1
#define FLASE 0
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//Initialize the sequential list
Status Initlist_Sq(SqList &L){
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)return OVERFLOW;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
} 


//Create the sequential list of n elements
Status Createlist_Sq(SqList &L,int n){
	int i;
	srand(time(0));
	for(i=0;i<n;i++){
		L.elem[i]=rand()%90+10;
		++L.length;
	}
	if(L.length==0)return ERROR;
	return OK;
}

//Output the sequential list of n elements
Status Outputlist_Sq(SqList &L){
	int i;
	if(L.length==0)return ERROR;
	for(i=0;i<L.length;i++){
		printf("%4d",L.elem[i]);	
	}
	printf("\n");
	return OK;
} 

//按值非递减排列
Status Listsort_Sq(SqList &L){
	int i,j,k,temp;
	if(L.length==0)return ERROR;
	for(i=0;i<L.length-1;i++){
		for(j=i+1;j<L.length-1;++j){
			k=i;
			if(L.elem[k]>L.elem[j]){
				k=j;
			}
			if(k!=i){
				temp=L.elem[k];
				L.elem[k]=L.elem[i];
				L.elem[i]=temp;
			}
		}
	}
} 


int main(){
	SqList L;
	printf("创建一个线性表：");
	Initlist_Sq(L);
	Createlist_Sq(L,5);
	printf("\n");
	printf("输出线性表："); 
	Outputlist_Sq(L);
	printf("\n");
	printf("按非递减顺序排列并输出：");
	Listsort_Sq(L); 
	Outputlist_Sq(L);
}
