#include <stdio.h>
#include <stdlib.h>

void main()
#define PI 3.14
{
    float r,d,L,S,SS,V;
    float a;
    scanf("%f",&r);
    d=2*r;
    L=2*PI*r;
    S=PI*r*r;
    SS=4*PI*r*r;
    a=4/3;
    V=a*PI*r*r*r;
    printf("ֱ��     d=%.3f\n",d);
    printf("�ܳ�     L=%.3f\n",L);
    printf("���     S=%.3f\n",S);
    printf("������SS=%.3f\n",SS);
    printf("���     V=%.3f\n",V);
}


