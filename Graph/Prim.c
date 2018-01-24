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

/* Prim算法生成连通图的最小生成树 */
void MiniSpanTree_Prim(MGraph G){
    int i, j, k, min;
    int adjvex[MAXVEX]; // 用于存储与当前顶点具有最小权重的边的顶点下标
    int lowcost[MAXVEX]; // 用于存储当前顶点与对应顶点间的最小权重
    adjvex[0] = 0; // 初始状态下，选择下标为0的顶点作为最小生成树中的第一个结点
    lowcost[0] = 0; // 顶点成为最小生成树中的结点时，权重值设为0
    for(i = 1; i < G.numVertex; i++){ 
        // 初始状态下，选择最小生成树中的第一个结点作为其余顶点的具有最小权重的边的顶点
        adjvex[i] = 0;
        lowcost[i] = G.arc[0][i];
    }
    for(i = 1; i < G.numVertex; i++){
        min = INFINITY;
        j = 1;
        k = 0;
        while(j < G.numVertex){ 
            // 获取最小权重，并记录其所属的顶点的下标
            if((lowcost[j] != 0) && (lowcost[j] < min)){
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d, %d)", adjvex[k], k); // 输出边信息
        lowcost[k] = 0; // 将该顶点放入最小生成树中
        for(j = 1; j < G.numVertex; j++){
            // 更新满足条件的顶点所对应的顶点信息以及权重信息
            if((lowcost[j] != 0) && (G.arc[k][j] < lowcost[j])){
                adjvex[j] = k;
                lowcost[j] = G.arc[k][j];
            }
        }
    }
}

int main(){
    printf("Hello World!");
    return 0;
}