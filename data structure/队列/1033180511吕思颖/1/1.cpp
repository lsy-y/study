#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;
typedef struct QNode
{
	QElemType data;
	struct QNode *next; 
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

Status CLearQueue(LinkQueue &Q)
{
	QueuePtr p,q;
	if(!Q.front)exit(OVERFLOW);
	p=Q.front->next;
	Q.front->next=NULL;
	while(p!=Q.rear){
		free(p);
		p=p->next; 
	}
	Q.rear=Q.front;
}

Status QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)return TRUE;
	else return FALSE; 
}

int QueueLength(LinkQueue Q)
{
	QueuePtr p;
	int n=0;
	p=Q.front->next;
	if(Q.front==Q.rear)return ERROR;
	while(p){
		p=p->next;
		n++;
	} 
	return n;
} 

Status GetHead(LinkQueue Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear)return ERROR;
	p=Q.front;
	return e=p->data;
	return OK;
}
Status EnQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear)return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.front=Q.rear;
	free(p);
	return OK; 
}

Status QueueTraverse(LinkQueue &Q)
{
	QueuePtr p=Q.front->next;
	if(p==NULL)return ERROR;
	while(p){
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}


int main()
{
	int i,n;
	QElemType k,h,a,f;
	LinkQueue Q;
	printf("����һ���ն��У�\n");
	InitQueue(Q);
	printf("�ж϶����Ƿ�Ϊ�գ�\n");
	printf("QueueEmpty(Q)=%d\n",QueueEmpty(Q));
	printf("�������е�Ԫ�ظ�����\n");
	scanf("%d", &n);
	printf("����%d��������е�Ԫ�ص�ֵ��\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &k);
		EnQueue(Q, k);
	}
    printf("�������Ԫ�صĸ�����%d\n",QueueLength(Q));
	printf("�������Ԫ�ص�ֵ��\n");
	QueueTraverse(Q);
	printf("���������е�Ԫ�ص�ֵ��");
	scanf("%d", &h);
	EnQueue(Q, h);
	printf("�������һ������Ԫ�غ����Ԫ�ص�ֵ��\n");
	QueueTraverse(Q);
    DeQueue(Q, a);
	printf("�����1��ɾ���Ķ�ͷԪ�ص�ֵ��%d\n", a);
	DeQueue(Q, a);
	printf("�����2��ɾ���Ķ�ͷԪ�ص�ֵ��%d\n", a);
	printf("�������ɾ����ͷԪ�غ���е�Ԫ��ֵ��");
	QueueTraverse(Q);
	GetHead(Q, f);
	printf("�����ͷԪ�ص�ֵ��%d\n",f);
	printf("�������Ԫ�صĸ�����%d\n",QueueLength(Q));
	printf("��Q��Ϊ�ն��У�\n");
	CLearQueue(Q);
	printf("�������Ԫ�صĸ�����%d\n",QueueLength(Q));
	printf("�ж϶����Ƿ�Ϊ�գ�\n");
	printf("QueueEmpty(Q)=%d\n",QueueEmpty(Q));
}
