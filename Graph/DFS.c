#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define TRUE 1
#define FALSE 0

typedef int Boolean;
Boolean visited[MAXVEX];

typedef int EdgeType;
typedef char VertexType;

/* 邻接矩阵存储方式数据结构 */
typedef struct {
    VertexType vexs[MAXVEX]; /* 顶点表 */
    EdgeType arc[MAXVEX][MAXVEX]; /* 邻接矩阵 */
    int numVertex; /* 顶点个数 */
    int numEdges; /* 边个数 */
} MGraph;

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
} GraphAdjList;

/* 邻接矩阵的深度优先递归算法 */
void DFS_MGraph(MGraph G, int i){
    int j;
    visited[i] = TRUE;
    printf("%c", G.vexs[i]);
    for(j = 0; j < G.numVertex; j++){ // 对于顶点vi的所有邻接点
        if(G.arc[i][j] == 1 && visited[j] == FALSE){
            DFS_MGraph(G, j);
        }
    }
}

/* 邻接矩阵的深度优先遍历算法 */
void DFSTraverse_MGraph(MGraph G){
    int i;
    for(i = 0; i < G.numVertex; i++){
        visited[i] = FALSE;
    }
    for(i = 0; i < G.numVertex; i++){
        if(visited[i] == FALSE){
            DFS_MGraph(G, i);
        }
    }
}

/* 邻接表的深度优先递归算法 */
void DFS_ALGraph(GraphAdjList G, int i){
    EdgeNode *e;
    int j;
    printf("%c", G.adjList[i].data);
    visited[i] = TRUE;
    e = G.adjList[i].firstedge;
    while(e){ // 对于顶点vi的所有邻接点
        j = e->adjvex;
        if(visited[j] == FALSE){
            DFS_ALGraph(G, j); // 静态地看待递归过程
        }
        e = e->next;
    }
}

/* 邻接表的深度优先遍历算法 */
void DFSTraverse_ALGraph(GraphAdjList G){
    int i;
    for(i = 0; i < G.numVertextes; i++){
        visited[i] = FALSE;
    }
    for(i = 0; i < G.numVertextes; i++){
        if(visited[i] == FALSE){
            DFS_ALGraph(G, i);
        }
    }
}

int main(){
    printf("Hello World!");
    return 0;
}