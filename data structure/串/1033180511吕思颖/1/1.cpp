#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define FALSE 0
#define TRUE 1
#define MAXSTRING 255
typedef int Status;
typedef unsigned char SString[MAXSTRING+1];

Status Concat(SString &T,SString S1,SString S2)
{
	int i,j;
	int uncut;
	if(S1[0]+S2[0]<=MAXSTRING)
	{
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(j=1;j<=S2[0];j++)
			T[S1[0]+j]=S2[j];
		T[0]=S1[0]+S2[0];
		uncut=TRUE;
	}
	else if(S1[0]<MAXSTRING)
	{
		for(i=1;i<=S1[0];i++)T[i]=S1[i];
		for(j=1;j<=MAXSTRING-S1[0];j++){
			T[S1[0]+j]=S2[j];
		}
		T[0]=MAXSTRING;
		uncut=FALSE;
	}
	else
	{
		for(i=0;i<=MAXSTRING;i++){
			T[i]=S1[i];
		}
		uncut=FALSE;
	}
	return uncut;
}
	
Status SubString(SString &Sub,SString S,int pos,int len){
	int i;
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)return ERROR;
	for(i=0;i<len;i++)
	{
		Sub[i]=S[pos+i];
	}
	Sub[0]=len;
	return OK;	
}

int main(){
	SString T,S1,S2,S,Sub;
	int i,pos,len;
	printf("输入串S1的长度：");
	scanf("%d",&S1[0]);
	getchar();
	printf("输入串S1的值：");
	for(i=1;i<=S1[0];i++){
		scanf("%c",&S1[i]);
	} 
	printf("输出串S1的值： \n");
	for(i=1;i<=S1[0];i++){
		printf("%c",S1[i]);
	} 
	printf("\n");
	printf("输入串S2的长度：");
	scanf("%d",&S2[0]);
	getchar();
	printf("输入串S2的值：");
	for(i=1;i<=S2[0];i++){
		scanf("%c",&S2[i]);
	} 
	printf("输出串S2的值： \n");
	for(i=1;i<=S2[0];i++){
		printf("%c",S2[i]);
	} 
	printf("\n");
	Concat(T,S1,S2);
	printf("输出串S1和串S2的联结串的值：\n");
	for(i=1;i<=T[0];i++){
		printf("%c",T[i]);
	} 
	printf("\n");
	printf("输入串S的长度：");
	scanf("%d",&S[0]);
	getchar(); 
	printf("输入串S的值:");
	for(i=1;i<=S[0];i++)
	{
		scanf("%c",&S[i]);
	} 
	printf("输出串S的值：\n");
	for(i=1;i<=S[0];i++)
	{
		printf("%c",S[i]);
	} 
	printf("\n");
	printf("输入串S的子串Sub的开始的字符位置：");
	scanf("%d",&len);
	SubString(Sub,S,pos,len);
	printf("输出子串Sub的值：\n");
	for(i=1;i<=Sub[0];i++){
		printf("%c",Sub[i]);
	}
	printf("\n"); 
}


