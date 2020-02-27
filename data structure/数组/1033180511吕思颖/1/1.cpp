#include<bits/stdc++.h>
using namespace std;
#include<stdarg.h>
#include<math.h> 
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
#define max 8
typedef struct
{
	int *base;
	int *bounds; //数组维界基址 
	int dim;// 维数 
	int *constants;
 }array;
 int init(array &a,int dim,...)
 {
    int i;
	va_list ap;
	int elemtotal=1;
	if(dim<1||dim>max)return ERROR;
	a.dim=dim;
	a.bounds=(int*)malloc(dim*sizeof(int));
	if(!a.bounds)exit(OVERFLOW);
	va_start(ap,dim);
	for(i=0;i<dim;i++)
	{
		a.bounds[i]=va_arg(ap,int);
		if(a.bounds[i]<0)return UNDERFLOW;
		elemtotal*=a.bounds[i];
	}
	va_end(ap);
	a.base=(int*)malloc(elemtotal*sizeof(int));
	if(!a.base)exit(OVERFLOW);
	a.constants=(int*)malloc(dim*sizeof(int));
	if(!a.constants)exit(OVERFLOW);
	a.constants[dim-1]=1;
	for(i=dim-2;i>=0;i--)
	{
		a.constants[i]=a.bounds[i+1]*a.constants[i+1];
	}
	return OK;
 }// init
 
 int destroy(array &a)
 {
	if(a.base)free(a.base);
	if(a.bounds)free(a.bounds);
	if(a.constants)free(a.constants);
	a.base=a.bounds=a.constants=NULL;
	return OK;
 }//destroy
 
 int locate(array a,va_list ap,int &off)
 {
	int j,i;
	off=0;
	for(i=0;i<a.dim;i++)
	{
		j=va_arg(ap,int);
		if(j<0||j>=a.bounds[i])return ERROR;
		off+=a.bounds[i]*j;
	}
	return OK;
 }
 
 int value(array a,int &e,int i,...)
 {
	va_list ap;
	int result,off;
	va_start(ap,i);
	if((result=locate(a,ap,off))<=0)return result;
	e=*(a.base+off);
	return OK;
 } 
 int assign(array &a,int e,...)
 {
	va_list ap;
	int result,off;
	va_start(ap,e);
	if((result=locate(a,ap,e))<=0)return result;
	*(a.base+off)=e;
	return OK;
 }
 int main()
 {
	array a;
	int e=0;
	init(a,3,2,3,4);
	assign(a,100,1,2,3);
	if(value(a,e,0,1,2,3)==OK)printf("输出e的值：%d\n",e);
	if(destroy(a)==OK)printf("数组a销毁成功！\n"); 
 }
 
