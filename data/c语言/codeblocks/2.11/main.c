#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1,b=3,c=5;
    int *p1=&a,*p2=&b,*p=&c;
    *p=*p1*(*p2);
    (*p1)++;
    --*p2;
    printf("a=%d %d\n",a,*p1);
    printf("b=%d %d\n",b,*p2);
    printf("c=%d %d %d\n",c,*&c,*p);
}
