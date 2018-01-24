#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY 65535

typedef int EdgeType;
typedef char VertexType;

/* 邻接矩阵存储方式数据结构 */
typedef struct {
    VertexType vexs[MAXVEX]; /* 顶点表 */
    EdgeType arc[MAXVEX][MAXVEX]; /* 邻接矩阵 */
    int numVertex; /* 顶点个数 */
    int numEdges; /* 边个数 */
} MGraph;


/* 建立无向网图的邻接矩阵表示 */
void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertex, &G->numEdges);
    for(i = 0; i < G->numVertex; i++){
        printf("请输入顶点信息：\n");
        scanf("%c", &G->vexs[i]);
    }
    printf("顶点信息输入完毕。\n");
    for(i = 0; i < G->numVertex; i++){ /* 初始化邻接矩阵 */
        for(j = 0; j < G->numEdges; j++){
            G->arc[i][j] = INFINITY;
        }
    }
    for(k = 0; k< G->numEdges; k++){
        printf("输入边(vi, vj)上的下标i，下标j和权重w：\n");
        scanf("%d,%d,%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

int main(){
    printf("Hello World!");
    return 0;
}