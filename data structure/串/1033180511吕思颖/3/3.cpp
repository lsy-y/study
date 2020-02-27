#include<bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
#define MAX 255
typedef unsigned char sstring[MAX+1];

int create(sstring &s,int i){
	int j;
	s[0]=i;
	for(j=1;j<=i;j++){
		cin>>s[j];
	}
}

int getnext(sstring t,int next[]){
	int i=1,j=0;
	next[1]=0;
	while(i<t[0])
	{
		if(j==0||t[i]==t[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else j=next[i];
	}
}
//模式匹配 
int index(sstring s,sstring t,int pos)
{
	int i=pos,j=1;
	while(i<=s[0]&&j<=t[0])
	{
 		if(s[i]==t[i])
		 {
 			++i;
 			++j;
		 }
		 else
		 {
		 	i=i-j+2;
			 j=1; 
		 }
	} 
	if(j>t[0])return i-t[0];
	else return 0;
 }
 
int gaijin(sstring s,sstring t,int pos){
 	int i=pos,j=1;
 	int next[255];
 	getnext(t,next);
	while(i<s[0]&&j<=t[0])
	{
		if(j==0||s[i]==t[j])
		{
			i++;
			j++;
		}
		else j=next[j];
	}
	if(j>t[0])return i-t[0];
	else return 0;
 }
 
 int main()
 {
 	sstring s,t;
 	int i,j;
 	cout<<"输入主串s的长度：";
	cin>>i;
	cout<<"输入主串s的值：";
	create(s,i);
	cout<<"输入子串t的长度：";
	cin>>j;
	cout<<"输入子串t的值：" ;
	create(t,j);
	cout<<"输出子串t在主串s中的位置，若不包含，则输出0"<<endl;
	printf("位置为：%d",gaijin(s,t,1)); 
 }
