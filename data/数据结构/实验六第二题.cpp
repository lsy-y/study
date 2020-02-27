#include<bits/stdc++.h>
using namespace std;
typedef struct {
	char *ch;
	int length;
}hstring;
int initstring(hstring &T){
	T.ch=(char*)malloc(T.length*sizeof(char));
}
int clearstring(hstring &S){
	if(S.ch){
		free(S.ch);
		S.length=0;
	}
}
int substring(hstring &sub,hstring S,int pos,int len){	
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return -1;
	for (int i = 0; i < len; i++)
		sub.ch[i] = S.ch[pos + i - 1];
	sub.length = len;
}
int shanchu(hstring &S,int pos){
	for(int i=pos-1;i<S.length-1;i++){
		S.ch[i]=S.ch[i+1];
		S.length--;
	}
}
int concat(hstring &S,hstring T,int pos){
	 if(pos<1||pos>S.length+1)return 0;
	 if(T.length){
	 	if(!(S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char))))
	 	exit(0);
	 	for(int i=S.length-1;i>=pos-1;i--){
	 		S.ch[T.length+i]=S.ch[i];
		 }
 	    for(int i=0;i<T.length;i++){
 	    	S.ch[pos-1+i]=T.ch[i];
		 }
		 S.length=S.length+T.length;
	 }
}
int output(hstring S){
	for(int i=0;i<S.length;i++){
		cout<<S.ch[i]<<" ";
	}
}
int main(){
	hstring T,S,sub;
	int pos,i,len;  
	initstring(T);
    initstring(S);
    initstring(sub);
	cout<<"输入串S的长度：";
	scanf("%d",&S.length);
	getchar();
	cout<<"输入串S："<<endl;
	for(i=0;i<S.length;i++){
		scanf("%c",&S.ch[i]);
	} 
	cout<<"输入串T的长度：";
	scanf("%d",&T.length);
	getchar();
	cout<<"输入串T："<<endl;
	for(i=0;i<T.length;i++){
		scanf("%c",&T.ch[i]);
	}
	
	cout<<"输入S中要删除的字符的位置："  ;
	scanf("%d",&pos);
	shanchu(S,pos);
	cout<<"输出剩下的字符串S："<<endl;
	output(S);
	cout<<endl;
 	cout<<"输入串s的子串sub的开始字符位置：";
	scanf("%d",&pos);
	cout<<"输入串s的子串sub的长度：";
	scanf("%d",&len);
	substring(sub,S,pos,len);
	cout<<"输出字符串sub："<<endl;
	output(sub);
	cout<<endl;
	cout<<"输入T联接到S的第POS位："; 
	scanf("%d",&pos);
 	concat(S,T,pos);
 	cout<<"联接后的S："<<endl;
 	output(S);
    cout<<endl; 
    printf("S的长度为%d\n",S.length);
	printf("T的长度为%d\n",T.length);
	cout<<"清空字符串S！"<<endl;
	clearstring(S);
	printf("S的长度为%d\n",S.length);
}
