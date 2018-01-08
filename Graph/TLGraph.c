#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;

/* 边表的数据结构 */
typedef struct EdgeNode {
    EdgeType tailVex;
    EdgeType headVex;
    struct EdgeNode *headLink;
    struct EdgeNode *tailLink;
} EdgeNode;

/* 顶点表的数据结构 */
typedef struct VertexNode {
    VertexType data;
    EdgeNode *firstin;
    EdgeNode *firstout;
} VertexNode, Tlist[MAXVEX];

/* 以十字链表表示的有向图的数据结构 */
typedef struct GraphTList {
    Tlist tList;
    int numVertexes, numEdges;
} GraphTList;

/* 创建图的十字链表结构 */
void CreateGraph(GraphTList *G){
    int i, j, k;
    EdgeNode *e;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numVertexes);
    printf("请输入顶点信息：\n");
    for(i = 0; i < G->numVertexes; i++){
        scanf("%c", &G->tList[i]);
        G->tList[i].firstin = NULL;
        G->tList[i].firstout = NULL;
    }
    for(k = 0; k < G->numEdges; k++){
        printf("请输入边(vi, vj)上的顶点序号：\n");
        scanf("%d, %d", &i, &j);
        /* 有向图中，十字链表等同于邻接表和逆邻接表的结合 */
        /* 存储弧信息时，相当于先存邻接表，然后再存逆邻接表 */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->tailVex = i;
        e->headVex = j;
        // 邻接表部分（出表）
        e->tailLink = G->tList[i].firstout;
        G->tList[i].firstout = e;
        // 逆邻接表部分（入表）
        e->headLink = G->tList[j].firstin;
        G->tList[j].firstin = e;
    }
}

int main(){
    printf("Hello World!");
    return 0;
}
