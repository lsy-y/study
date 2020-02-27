#include <stdio.h>
#include <stdlib.h>
#define TURE 1
#define FLASE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAX_TREE_SIZE 100
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef int Status;
typedef char SElemType;
typedef struct 
{
    BiTree *base;
    BiTree *top;
    int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{
    S.base = (BiTree *)malloc(STACK_INIT_SIZE *sizeof(BiTree));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}
Status Push(SqStack &S,BiTree e)
{
    if(S.top - S.base >=S.stacksize)
	{
        S.base= (BiTree *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(BiTree));
        if(!S.base)exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}
Status Pop(SqStack &S,BiTree &e)
{
    if(S.top==S.base) return ERROR;
    e= * --S.top;
    return OK;
}
Status GetTop(SqStack S,BiTree &e)
{
    if(S.top == S.base) return ERROR;
    e= *(S.top-1);
    return OK;
}
Status StackEmpty(SqStack S)
{
    if(S.base==S.top) return OK;
    else
        return ERROR;
}
typedef BiTree QElemType;
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
    Q.front = Q.rear =(QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
    return OK;
}
Status EnQueue (LinkQueue &Q,QElemType e)
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}
Status DeQueue (LinkQueue &Q,QElemType &e)
{
    QueuePtr p;
    if(Q.front == Q.rear) return ERROR;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear == p) Q.rear=Q.front;
    free(p);
    return OK;
}
Status EmptyQueue(LinkQueue Q)
{
    if(Q.front == Q.rear) return 1;
    else
        return 0;
}
Status LenQueue(LinkQueue Q)
{
    if(Q.front==NULL) exit (OVERFLOW);
    int length=0;
    QueuePtr p=Q.front->next;
    while(p!=NULL)
	{
        length++;
        p=p->next;
    }
    return length;
}
Status Gethead(LinkQueue Q,QElemType &e)
{
    if(Q.front==NULL) exit(OVERFLOW);
    e=Q.front->data;
    return OK;
}
Status CreateBiTree(BiTree &T,SqStack &S)
{
    TElemType ch;
    if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
    scanf("%c",&ch);
    T->data=ch;
    Push(S,T);
    while(!StackEmpty(S))
	{
        scanf("%c",&ch);
        if(ch!='#')
		{
            T->lchild=(BiTNode *)malloc(sizeof(BiTNode));
            T->lchild->data=ch;
            Push(S,T->lchild);
        }
        else
            T->lchild=NULL;
        scanf("%c",&ch);
        if(ch!='#')
		{
            T->rchild=(BiTNode *)malloc(sizeof(BiTNode));
            T->rchild->data=ch;
            Push(S,T->rchild);
        }
        else
            T->rchild=NULL;
        Pop(S,T);
    }
    return OK;
}
Status PreOrderTraverse(BiTree T,SqStack S)
{
    BiTree p=T;
    InitStack(S);
    Push(S,p);
    while(!StackEmpty(S))
	{
        if(p!=NULL)
		{
            Push(S,p);
            printf("%c",p->data);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            p=p->rchild;
        }
    }
    return OK;
}
Status InOrderTraverse(BiTree T,SqStack S)
{
    BiTree p=T;
    while(p||!StackEmpty(S))
	{
        if(p) {Push(S,p);p=p->lchild;}
        else 
		{
            Pop(S,p);
            printf("%c",p->data);
            p=p->rchild;
        }
    }
    return OK;
}
Status PostTraverse(BiTree T,SqStack S)
{
    BiTree cur,pre;
    if(T==NULL)
	{
        printf("The tree is empty£¡\n");
        exit(OVERFLOW);
    }
    pre=NULL;cur=NULL;
    Push(S,T);
    while(!StackEmpty(S))
	{
        cur=NULL;
        GetTop(S,cur);
        if((cur->lchild==NULL&&cur->rchild==NULL)||(pre != NULL && (pre == cur->lchild ||pre == cur->rchild)))
        {
            printf("%c",cur->data);
            pre=cur;
            Pop(S,cur);
        }
        else
        {
            if(cur->rchild !=NULL)
			{
                Push(S,cur->rchild);
            }
            if(cur->lchild!=NULL)
                Push(S,cur->lchild);
        }
    }
    return OK;
}//´ý¸ÄÉÆ
Status LevelTraverse(BiTree T)
{
    LinkQueue Q;
    BiTree p;
    p=T;
    InitQueue(Q);
    if(p==NULL) exit(OVERFLOW);
    EnQueue(Q,p);
    while(!EmptyQueue(Q)){
        p=NULL;
        DeQueue(Q,p);
        if(p->lchild !=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild !=NULL)
            EnQueue(Q,p->rchild);
        printf("%c",p->data);
    }
    return OK;
}
Status TreeDepth(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    if(T==NULL) exit(OVERFLOW);
    EnQueue(Q,T);
    BiTree p;
    int level=0;
    int len=0;
    while(!EmptyQueue(Q))
	{
        len=LenQueue(Q);
        level++;
        while(len--)
		{
            DeQueue(Q,p);
            if(p->lchild) EnQueue(Q,p->lchild);
            if(p->rchild) EnQueue(Q,p->rchild);
        }
    }
    printf("%d",level);
    return OK;
}
Status Nodecount(BiTree T,SqStack S)
{
    BiTree p=T;
    int len=0;
    while(p||!StackEmpty(S))
	{
        if(p) {Push(S,p);p=p->lchild;}
        else 
		{
            Pop(S,p);
            len++;
            p=p->rchild;
        }
    }
    printf("%d",len);
    return OK;
}
void ExchangeBiTree(BiTree &T)
{
    LinkQueue Q;
    InitQueue(Q);
    if(T==NULL)
        exit(OVERFLOW);
    EnQueue(Q,T);
    while(!EmptyQueue(Q))
	{
        BiTree p;
        DeQueue(Q,p);
        if(p->lchild!=NULL)
            EnQueue(Q,T->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,T->lchild);
        BiTree temp;
        temp=p->lchild;
        p->lchild=p->rchild;
        p->rchild=temp;
    }
}
int main()
{
    BiTree T;
    SqStack S;
    InitStack(S);
    printf("Create a BiTree!:\n");
    CreateBiTree(T,S);
    printf("PreOrderTraver the BiTree!:\n");
    PreOrderTraverse(T,S);
    printf("\n");
    printf("InOrderTraverse the BiTree!:\n");
    InOrderTraverse(T,S);
    printf("\n");
    printf("PostOderTraverse the BiTree!:\n");
    PostTraverse(T,S);
    printf("\n");
    printf("LevelTraverse the BiTree!:\n");
    LevelTraverse(T);
    printf("\n");
    printf("Get the depth of the Bitree!:\n");
    TreeDepth(T);
    printf("\n");
    printf("Get the total numbers of the Bitree's root!\n");
    Nodecount(T,S);
    printf("\n");
    printf("Exchage the Bitree!\n");
    ExchangeBiTree(T);
    LevelTraverse(T);
    printf("\n");
}
