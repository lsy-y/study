#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define FALSE 0
#define TRUE 1
#define INFINITY INT_MAX   //���ֵ
#define MAX_VERTEX_NUM 20   //��󶥵����
typedef int Status;
typedef int VRType;
typedef int InfoType;
typedef enum
{
	DG,DN,UDG,UDN 
}GraphKind;//{����ͼ��������������ͼ��������}
typedef struct ArcCell
{
	VRType adj;    //VRType�Ƕ����ϵ���͡�����Ȩͼ����1��0
	               //��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ����
	InfoType *info;//�û������Ϣ��ָ�� 
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef char VertexType;
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;                 //��Ӿ���
	int vexnum,arcnum;              //ͼ�ĵ�ǰ����ͻ���
	GraphKind kind;                 //ͼ�������־  
}MGraph;

int LocateVex(MGraph G,char v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)return i;
	return -1;
}

Status CreateUDN(MGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	printf("���붥����G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("�������G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;i++)
	{
		printf("���붥��G.vexs[%d]:",i);
		scanf("%c",&G.vexs[i]);
		getchar(); 
	} 
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=NULL;
		}
	}
	for(k=0;k<G.arcnum;++k)
	{
		printf("�����%d����vi��vj��Ȩֵw��int����\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);
		getchar();
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=w;
		G.arcs[j][i].adj=G.arcs[i][j].adj; 
	}
	return OK;
} 



Status CreateDN(MGraph &G)
{
	int i, j, k, w;
	VertexType v1, v2;
	printf("���붥����G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("�������G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		printf("���붥��G.vexs[%d]:",i);
		scanf("%c",&G.vexs[i]);
		getchar();
	}//���춥������
 
	 //��ʼ���ڽӾ���
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	}
	//�����ڽӾ���
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("�����%d����vi��vj��Ȩֵw��int����\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);
		getchar();
		//ȷ��v1��v2��G�е�λ��
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;//��<v1,v2>��Ȩֵ
	}
	return OK;
}
/*
����ͼ�Ĺ���
*/
Status CreateDG(MGraph &G)
{
	int i, j, k, w;
	VertexType v1, v2;
	printf("���붥����G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("�������G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		printf("���붥��G.vexs[%d]:",i);
		scanf("%c",&G.vexs[i]);
		getchar();
	}//���춥������
 
	 //��ʼ���ڽӾ���
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	}
	//�����ڽӾ���
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("�����%d����vi��vj��Ȩֵw��int����\n",k+1);
		scanf("%c %c ",&v1,&v2);
		//ȷ��v1��v2��G�е�λ��
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;//1����ɴ0�����ɴ�
	}
	return OK;
}
/*
����ͼ�Ĺ���
*/
Status CreateUDG(MGraph &G)
{
	int i, j, k, w;
	VertexType v1, v2;
	printf("���붥����G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("�������G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		printf("���붥��G.vexs[%d]:",i);
		scanf("%c",&G.vexs[i]);
		getchar();
	}//���춥������
 
	 //��ʼ���ڽӾ���
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	}
	//�����ڽӾ���
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("�����%d����vi��vj��Ȩֵw��int����\n",k+1);
		scanf("%c %c ",&v1,&v2);
		getchar();
		//ȷ��v1��v2��G�е�λ��
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;//1����ɴ0�����ɴ�
		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	return OK;
}


Status CreateGraph(MGraph &G)
{
	printf("������ͼ�����ࣺ0��ʾDG��1��ʾDN��2��ʾUDG��3��ʾUDN\n");
	scanf("%d",&G.kind);
	switch(G.kind)
	{
		case DG:return CreateDG(G);
		case DN:return CreateDN(G);
		case UDG:return CreateUDG(G);
		case UDN:return CreateUDN(G);
		default:return ERROR;
	} 
}

void list(MGraph G){
    int i,j;
    printf("����ڽӾ���:\n");
    for(i=0;i<G.vexnum;++i)
	{
        printf("%c---",G.vexs[i]);
        for(j=0;j<G.vexnum;++j)
            if(G.arcs[i][j].adj==INFINITY)
                printf("%4s","  ��");
            else
                printf("%4d",G.arcs[i][j].adj);
        printf("\n");
    }
}

int  main()
{
	MGraph G;
	CreateGraph(G);
	list(G);
}
 
 
