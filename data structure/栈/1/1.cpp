#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef int Status;
typedef struct{
	SElemType *top;
	SElemType *base;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S){
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status StackEmpty(SqStack &S){
	if(S.base)return TRUE;
	else return FALSE;
}

Status GetTop(SqStack &S,SElemType &e){
	if(S.top==S.base)return ERROR;
	e=*(S.top-1);
	return OK;
}

Status Push(SqStack &S,SElemType e){
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base)exit(OVERFLOW);
		S.top=S.base+S.stacksize; 
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}


Status Stackoutput(SqStack &S){
	SElemType *p;
	if(S.top==S.base)return ERROR;
	p=S.top;
	while(p!=S.base){
		printf("%d ",*--p);
	} 
	printf("\n");
	return OK;
}

Status StackTraverse(SqStack &S){
	SElemType *p;
	if(S.top==S.base)return ERROR;
	p=S.base;
	while(p!=S.top){
		printf("%d ",*p++);
	}
	printf("\n");
	return OK;
}

Status Pop(SqStack &S,SElemType &e){
	if(S.top==S.base)return ERROR;
	e=*--S.top;
	return OK;
}


int main(){
	int i,n,k,h,a,b;
	SqStack S;
	printf("����һ����ջ��\n");
	InitStack(S);
	printf("�ж��Ƿ�Ϊ�գ�\n");
	printf("StackElemType(S)=%d\n",StackEmpty(S));
	printf("����ջ��Ԫ�ظ�����\n");
	scanf("%d",&n);
	printf("����%d����ջԪ�ص�ֵ��\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		Push(S,k);
	} 
	printf("�����˳��ջԪ��ֵ��\n");
	Stackoutput(S);
	printf("���˳��ջԪ��ֵ��\n");
	StackTraverse(S);
	printf("������ջԪ��ֵ��\n");
	scanf("%d",&h);
	Push(S,h);
	printf("�����ջ���˳��Ԫ��ֵ��\n");
	StackTraverse(S);
	Pop(S,a);
	printf("�����1����ջԪ��ֵ��%d\n",a);
	Pop(S,a);
	printf("����ڶ�����ջԪ��ֵ��%d\n",a); 
	printf("������γ�ջ��˳��Ԫ��ֵ��");
	StackTraverse(S);
	GetTop(S,b);
	printf("���ջ��Ԫ��ֵ��%d\n",b); 
}


