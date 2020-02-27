#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define FALSE 0
#define TRUE 1
#define MAX_VERTEX_NUM 20   //最大顶点个数
typedef int Status;
typedef int InfoType;
bool visited[MAX_VERTEX_NUM];
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;
typedef char VertexType;
typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;
Status(*VisitFunc)(ALGraph G, int v);
typedef struct QNode 
{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue &Q) 
{
	//构造?个空队列
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q, int e) 
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue &Q, int &e) 
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}
Status QueueEmpty(LinkQueue Q) 
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
int LocateVex(ALGraph G, char v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == v)return i;
	}
	return -1;
}


Status CreateDG(ALGraph &G) 
{
	int i, j, k, lnclnfo;
	ArcNode *pi, *pj;
	char v1, v2;
	printf("输?顶点数G.vexnum:");
	scanf("%d", &G.vexnum);
	printf("输?边数G.arcnum:");
	scanf("%d", &G.arcnum);
	printf("输?边包含其它信息情况(1--包含，0--不包含):\n");
	scanf("%d", &lnclnfo);
	getchar();
	for (i = 0; i < G.vexnum; ++i) {
		printf("输?顶点G.vertices[%d].data:", i);
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; ++k) 
	{
		printf("请输?第%d条边的两个顶点(前?个顶点指向后?个顶点）:\n",k+1);
			scanf("%c%c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode *)malloc(sizeof(ArcNode)))) exit(OVERFLOW);
		pi->adjvex = j;
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;
		if (!(pj = (ArcNode *)malloc(sizeof(ArcNode)))) exit(OVERFLOW);
		pj->adjvex = i;
		pj->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = pj;
	}
	return OK;
}

Status CreateDN(ALGraph &G) 
{
	int i, j, k, lnclnfo;
	ArcNode *pi, *pj;
	char v1, v2;
	printf("输?顶点数G.vexnum:");
	scanf("%d", &G.vexnum);
	printf("输?边数G.arcnum:");
	scanf("%d", &G.arcnum);
	printf("输?边包含其它信息情况(1--包含，0--不包含):\n");
	scanf("%d", &lnclnfo);
	getchar();
	for (i = 0; i < G.vexnum; ++i)
	{
		printf("输?顶点G.vertices[%d].data:", i);
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; ++k) 
	{
		printf("请输?第%d条边的两个顶点(前?个顶点指向后?个顶点）:\n",k+1);
		scanf("%c%c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode *)malloc(sizeof(ArcNode)))) exit(OVERFLOW);
		pi->adjvex = j;
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;
		if (!(pj = (ArcNode *)malloc(sizeof(ArcNode)))) exit(OVERFLOW);
		pj->adjvex = i;
		pj->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = pj;
	}
	return OK;
}

Status CreateUDN(ALGraph &G) 
{
	//采?邻接表存储表示，构造?向图G (G.kind=UDG)。
	int i, j, k, lnclnfo;
	ArcNode *pi, *pj;
	char v1, v2;
	printf("输?顶点数G.vexnum:");
	scanf("%d", &G.vexnum);
	printf("输?边数G.arcnum:");
	scanf("%d", &G.arcnum);
	printf("输?边包含其它信息情况(1--包含，0--不包含):\n");
	scanf("%d", &lnclnfo);
	getchar();
	for (i = 0; i < G.vexnum; ++i) 
	{
		printf("输?顶点G.vertices[%d].data:", i);
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; ++k) 
	{
		printf("请输?第%d条边的两个顶点:\n", k + 1);
		scanf("%c%c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode *)malloc(sizeof(ArcNode)))) exit(OVERFLOW);
		pi->adjvex = j;
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;
		if (!(pj = (ArcNode *)malloc(sizeof(ArcNode)))) exit(OVERFLOW);
		pj->adjvex = i;
		pj->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = pj;
	}
	return OK;
}
Status CreateUDG(ALGraph &G)
{
	int i, j, k, Inclnfo;
	ArcNode *pi, *pj;
	char v1, v2;
	//scanf("%d %d %d",&G.vexnum,&G.arcnum,&Inclnfo);
	printf("输入顶点数G.vexnum:");
	scanf("%d", &G.vexnum);
	printf("输入边数G.arcnum:");
	scanf("%d", &G.arcnum);
	printf("输入边包含的其他信息情况（1--包含，0--不包含):");
	scanf("%d", &Inclnfo);
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		printf("输入顶点G.vertices[%d].data:", i);
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("请输入第%d条边的两个顶点：\n", k + 1);
		scanf("%c%c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode*)malloc(sizeof(ArcNode))))exit(OVERFLOW);
		pi->adjvex = j;
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;
		if (!(pj = (ArcNode*)malloc(sizeof(ArcNode))))exit(OVERFLOW);
		pj->adjvex = i;
		pj->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pj;

	}
	return OK;
}

Status CreateGraph(ALGraph &G)
{
	printf("请输入图的种类：0表示DG，1表示DN，2表示UDG，3表示UDN\n");
	scanf("%d", &G.kind);
	switch (G.kind)
	{
	//case 0:return CreateDG(G);
	//case 1:return CreateDN(G);
	case 2:return CreateUDG(G);
	//case 3:return CreateUDN(G);
	default:return ERROR;
	}
}

void list(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("输出邻接表：\n");
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%d: %c--->", i, G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("%3d", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}

Status Visit(ALGraph G, int v) 
{
	printf("%c ", G.vertices[v].data);
	return OK;
}
void DFS(ALGraph G, int v) {
	//从第v个顶点出发递归地深度优先遍历图G
	visited[v] = TRUE; VisitFunc(G, v);//访问第v个顶点
	ArcNode *p;
	int w;
	for (p = G.vertices[v].firstarc; p; p = p->nextarc) 
	{
		w = p->adjvex;
		if (!visited[w])
			DFS(G, w);
	}
}
void DFSTraverse(ALGraph G, Status(*Visit)(ALGraph G, int v)) 
{
	VisitFunc = Visit; int v;
	for (v = 0; v < G.vexnum; ++v) visited[v] = FALSE;
	for (v = 0; v < G.vexnum; ++v)
		if (!visited[v]) 
		{
			DFS(G, v); printf("\n");
		}
}
void BFSTraverse(ALGraph G, Status(Visit)(ALGraph G, int v)) {
	LinkQueue Q; int w, v, u;
	ArcNode *p;
	for (v = 0; v < G.vexnum; ++v) visited[v] = FALSE;
	InitQueue(Q);
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) 
		{
			visited[v] = TRUE; Visit(G, v);
			EnQueue(Q, v);
			while (!QueueEmpty(Q)) 
			{
				DeQueue(Q, u);
				for (p = G.vertices[u].firstarc; p; p = p->nextarc) 
				{
					w = p->adjvex;
					if (!visited[w]) 
					{
						visited[w] = TRUE; Visit(G, w);
						EnQueue(Q, w);
					}
				}
			}
		}
}
int main() 
{
	ALGraph G;
	CreateGraph(G);
	list(G);
	printf("深度优先遍历该图！\n");
	DFSTraverse(G, Visit);
	printf("?度优先遍历该图！\n");
	BFSTraverse(G, Visit);
}
