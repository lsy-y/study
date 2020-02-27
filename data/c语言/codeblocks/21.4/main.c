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
    printf("直径     d=%.3f\n",d);
    printf("周长     L=%.3f\n",L);
    printf("面积     S=%.3f\n",S);
    printf("球表面积SS=%.3f\n",SS);
    printf("体积     V=%.3f\n",V);
}


