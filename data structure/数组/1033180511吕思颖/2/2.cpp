#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h> 
#include<time.h>
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
#define max 12500
#define MU 5
#define NU 6 
typedef struct
{
	int i,j;
	int e;
}T;
typedef struct
{
	T data[max+1];
	int mu,nu,tu;
}TS;

int create(TS &M)
{
	int e,i,j,k=1;
	M.mu=MU;
	M.nu=NU;
	srand((unsigned)time(NULL));
	M.tu=rand()%15;
	for(i=1;i<=M.mu;i++)
	{
		for(j=1;j<=M.nu;j++)
		{
			e=rand()%30;printf("%");
			if(e!=0)
			{
				M.data[k].i=i;
				M.data[k].j=j;
				M.data[k].e=e;
				k++;
				if(k==M.tu)break;
			}
		}
	}
	return OK;
}

int transpose(TS m,TS &t)
{
	int q=1;
	int col,p;
	t.mu=m.nu;
	t.nu=m.mu;
	t.tu=m.tu;
	if(t.tu)
	{
        for(col=1;col<=m.nu;++col)
		{
            for(p=1;p<=m.tu;p++)
		    {
                if(m.data[p].j==col)
	            {
				    t.data[q].i=m.data[p].j;
				    t.data[q].j=m.data[p].i;
				    t.data[q].e=m.data[p].e;
				    ++q;
		       	}
		    }
	    }
	}
	return OK;
}

int print(TS M)
{
	int k;
	printf("mu=%-2d, nu=%-2d, tu=%-2d",M.mu,M.nu,M.tu);
	printf("\n");
	for(k=1;k<=M.tu;k++)
	{
		printf("i=%-2d. j=%-2d, e=%-2d",M.data[k].i,M.data[k].j,M.data[k].e);
		printf("\n");
	}
}

int main()
{
	TS m,t;
	create(m);//	printf("-------1111-----------");
	transpose(m,t);
	printf("Êä³öÏ¡Êè¾ØÕóm£º\n");
	print(m);
	printf("Êä³ö×ªÖÃ¾ØÕót£º\n");
	print(t); 
}
