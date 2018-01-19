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

void ShortestPath_Dijsktra(MGraph G, int v0, Patharc *P, ShortestPathTable *D){
    // 数组P用于存储该数组下标所对应的顶点在最短路径中的前驱顶点
    // 数组D用于存储该数组下标所对应的顶点与源点的最短路径的权值之和
    int i, j;
    int k;
    int min;
    int final[MAXVEX]; // 用于标识从源点v0到数组下标所代表的顶点之间的最短路径是否已经求得
    for(i = 0; i < G.numVertex; i++){ // 初始化
        final[i] = 0; // 初始状态下，所有顶点与源点之间的最短路径全未求得
        (*P)[i] = v0; // 初始状态下，设置所有顶点在最短路径中的前驱顶点均为源点
        (*D)[i] = G.arc[v0][i]; // 初始状态下，暂定数组D中的值为源点到各顶点的弧所带的权值
    }
    final[v0] = 1; // 表明要求顶点v0到其余顶点的最短路径
    (*D)[v0] = 0; // 自身到自身无环，所以设置为0
    for(i = 0; i < G.numVertex; i++){
        min = INFINITY;
        for(j = 0; j < G.numVertex;j++){ // 从数组D中查找具有最小最短路径的顶点
            if(final[j] == 0 && min > (*D)[j]){
                min = (*D)[j];
                k = j;
            }
        }
        final[k] = 1;
        for(j = 0; j < G.numVertex; j++){ // 根据上步求得的顶点对数组D进行松弛并更新数组P
            if(final[j] == 0 && min + G.arc[k][j] < (*D)[j]){
                (*D)[j] = min + G.arc[k][j];
                (*P)[j] = k;
            }
        }
    }
}

int main(){
    printf("Hello World!");
    return 0;
}