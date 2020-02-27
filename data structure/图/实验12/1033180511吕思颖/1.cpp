#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define FALSE 0
#define TRUE 1
#define INFINITY INT_MAX   //最大值
#define MAX_VERTEX_NUM 20   //最大顶点个数
typedef int Status;
typedef int VRType;
typedef int InfoType;
typedef enum
{
	DG,DN,UDG,UDN 
}GraphKind;//{有向图，有向网，无向图，无向网}
typedef struct ArcCell
{
	VRType adj;    //VRType是顶点关系类型。对无权图，用1或0
	               //表示相邻否；对带权图，则为权值类型
	InfoType *info;//该弧相关信息的指针 
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef char VertexType;
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;                 //领接矩阵
	int vexnum,arcnum;              //图的当前顶点和弧数
	GraphKind kind;                 //图的种类标志  
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
	printf("输入顶点数G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("输入边数G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;i++)
	{
		printf("输入顶点G.vexs[%d]:",i);
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
		printf("输入第%d条边vi，vj和权值w（int）：\n",k+1);
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
	printf("输入顶点数G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("输入边数G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		printf("输入顶点G.vexs[%d]:",i);
		scanf("%c",&G.vexs[i]);
		getchar();
	}//构造顶点向量
 
	 //初始化邻接矩阵
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	}
	//构造邻接矩阵
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("输入第%d条边vi，vj和权值w（int）：\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);
		getchar();
		//确定v1和v2在G中的位置
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;//弧<v1,v2>的权值
	}
	return OK;
}
/*
有向图的构造
*/
Status CreateDG(MGraph &G)
{
	int i, j, k, w;
	VertexType v1, v2;
	printf("输入顶点数G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("输入边数G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		printf("输入顶点G.vexs[%d]:",i);
		scanf("%c",&G.vexs[i]);
		getchar();
	}//构造顶点向量
 
	 //初始化邻接矩阵
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	}
	//构造邻接矩阵
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("输入第%d条边vi，vj和权值w（int）：\n",k+1);
		scanf("%c %c ",&v1,&v2);
		//确定v1和v2在G中的位置
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;//1代表可达，0代表不可达
	}
	return OK;
}
/*
无向图的构造
*/
Status CreateUDG(MGraph &G)
{
	int i, j, k, w;
	VertexType v1, v2;
	printf("输入顶点数G.vexnum:");
	scanf("%d",&G.vexnum);
	printf("输入边数G.arcnum:");
	scanf("%d",&G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		printf("输入顶点G.vexs[%d]:",i);
		scanf("%c",&G.vexs[i]);
		getchar();
	}//构造顶点向量
 
	 //初始化邻接矩阵
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	}
	//构造邻接矩阵
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("输入第%d条边vi，vj和权值w（int）：\n",k+1);
		scanf("%c %c ",&v1,&v2);
		getchar();
		//确定v1和v2在G中的位置
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;//1代表可达，0代表不可达
		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	return OK;
}


Status CreateGraph(MGraph &G)
{
	printf("请输入图的种类：0表示DG，1表示DN，2表示UDG，3表示UDN\n");
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
    printf("输出邻接矩阵:\n");
    for(i=0;i<G.vexnum;++i)
	{
        printf("%c---",G.vexs[i]);
        for(j=0;j<G.vexnum;++j)
            if(G.arcs[i][j].adj==INFINITY)
                printf("%4s","  ∞");
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
 
 
