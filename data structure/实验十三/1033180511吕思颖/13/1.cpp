#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFINITY 32767
#define MAX_VERTEX_NUM 20
typedef int Status;
typedef int VRType;
typedef int InfoType;
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef struct ArcCell {
	VRType adj;
	InfoType *info;
}ArcCell, AdjMaxtrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef char VertexType;
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMaxtrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;
int LocateVex(MGraph G, char v) {
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (G.vexs[i] == v) return i;
	return -1;
}
Status CreateDN(MGraph &G) {
	int i, j, k, w;
	VertexType v1, v2;
	printf("输入顶点数G.vexnum:");
	scanf("%d", &G.vexnum);
	printf("输入边数G.arcnum:");
	scanf("%d", &G.arcnum);
	getchar();
	for (i = 0; i < G.vexnum; i++) {
		printf("输入顶点G.vexs[%d]:", i);
		scanf("%c", &G.vexs[i]);
		getchar();
	}
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	for (k = 0; k < G.arcnum; ++k) {
		printf("输入第%d条边vi,vj和vi->vj的权值w(int)\n", k + 1);
		scanf("%c %c %d", &v1, &v2, &w);
		getchar();
		i = LocateVex(G, v1); j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
	}
	return OK;
}
void ShortestPath_FLOYD(MGraph G) {
	int P[G.arcnum + 1][G.arcnum + 1][G.arcnum + 1], D[G.arcnum + 1][G.arcnum + 1], v, w, u, i, j;
	for (v = 0; v < G.vexnum; ++v)
		for (w = 0; w < G.vexnum; w++) {
			D[v][w] = G.arcs[v][w].adj;
			for (u = 0; u < G.vexnum; ++u)
				if (D[v][w] < INFINITY&&D[v][w] != 0) {
					P[v][w][v] = TRUE; P[v][w][w] = TRUE;
				}
		}
	for (u = 0; u < G.vexnum; ++u)
		for (v = 0; v < G.vexnum; ++v)
			for (w = 0; w < G.vexnum; ++w)
				if (D[v][u] + D[u][w] < D[v][w]) {
					D[v][w] = D[v][u] + D[u][w];
					for (i = 0; i < G.vexnum; ++i)
						P[v][w][i] = P[v][u][i];
				}
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			if (D[i][j] != 9)
				printf("%c到%c的最短路径为:%d\n", G.vexs[i], G.vexs[j], D[i][j]);
}
int main() {
	printf("构造有向网G:\n");
	MGraph G;
	CreateDN(G);
	printf("FLOYD算法求最短路径！\n");
	ShortestPath_FLOYD(G);
}