#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROE 0
#define FALSE 0
#define OVERFLOW -2
typedef int Status;
typedef char SElemType;
typedef struct
{
    SElemType *top;
    SElemType *base;
    int stacksize;
}SqStack;


