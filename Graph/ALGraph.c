#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;

/* 边表数据结构 */
typedef struct EdgeNode {
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

/* 顶点表数据结构 */
typedef struct VertexNode {
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

/* 以邻接表表示的图的数据结构 */
typedef struct {
    AdjList adjList;
    int numVertextes;
    int numEdges;
} GrapgAdjList;

/* 创建邻接表 */
void CreateALGraph(GrapgAdjList *G){
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertextes, &G->numEdges);
    printf("请输入顶点信息：\n");
    for(i = 0; i < G->numVertextes; i++){
        scanf("%c", &G->adjList[i]);
        G->adjList[i].firstedge = NULL;
    }
    for(k = 0; k < G->numEdges; k++){
        printf("请输入边(vi, vj)上的顶点序号：\n");
        scanf("%d,%d", &i, &j);
        /* 在无向图中，vi和vj互为邻接点，所以边信息要针对vi和vj来进行两次存储 */
        /* 在有向图中，vi为弧尾，vj为弧头，无论是邻接表或逆邻接表，只需存储一次即可*/
        // 存储vi的邻接点vj
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        // 存储vj的邻接点vi
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

int main(){
    printf("Hello World!");
    return 0;
}