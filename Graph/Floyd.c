#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 9
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

typedef int Patharc[MAXVEX];
typedef int ShortestPathTable[MAXVEX];

void ShortestPath_Floyd(MGraph G, ShortestPathTable *D, Patharc *P){
    // D是二维矩阵，用于存储任意两点间的最短路径权值之和
    // P是二维矩阵，用于存储最短路径中顶点的前驱顶点
    int i, j, k;
    for(i = 0; i < G.numVertex; i++){
        for(j = 0; j < G.numVertex; j++){
            (*D)[i][j] = G.arc[i][j]; // 初始状态下，D中每个元素的值为两个对应顶点间的弧上所带的权值
            (*P)[i][j] = j; // 初始状态下，P中每个元素的值为对应的终点所在的下标
        }
    }
    for(i = 0; i < G.numVertex; i++){
        for(k = 0; k < G.numVertex; k++){
            for(j = 0; j < g.numVertex; j++){
                if((*D)[i][j] > (*D)[i][k] + (*D)[k][j]){ // 比较现有的vi到vj的最短路径长度与加入中转点vk后形成的路径长度之间的大小
                    // 更新vi到vj的最短路径
                    (*D)[i][j] = (*D)[i][k] + (*D)[k][j];
                    (*P)[i][j] = (*P)[i][k];
                }
            }
        }
    }
}

int main(){
    printf("Hello World!!!");
    return 0;
}