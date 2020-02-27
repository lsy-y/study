#include <stdio.h>
#include <stdlib.h>

void main()
{
    float a,b,c,d;
    a=3.31e-9;
    b=2.01e-7;
    c=7.15e-6;
    d=(a*b)/(b+c);
    printf("%.7e",d);

}
