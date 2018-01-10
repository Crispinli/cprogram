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

/* 边集数组 Edge 结构的定义 */
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

/* 将邻接矩阵转换为边集数组 */
void Arc2Edges(MGraph G, Edge *edges){
    int m, n, i, j, k;
    Edge temp;
    m = G.numEdges;
    n = G.numVertex;
    k = 0;
    EdgeType **arc;
    arc = G.arc;
    for(i = 0; i < n; i++){ // 获取边集数组
        for(j = i + 1; j < n; j++){
            if(arc[i][j] != INFINITY){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = arc[i][j];
            }
        }
    }
    for(i = 0; i < m; i++){ // 根据 weight 从小到大排序
        for(j = i + 1; j < m; j++){
            if(edges[i].weight > edges[j].weight){
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

/* 查找连线顶点的尾部下标 */
int Find(int *parent, int f){
    while(parent[f] > 0){
        f = parent[f];
    }
    return f;
}

/* Kruskal算法求解连通网的最小生成树 */
void MiniSpanTree_Kruskal(MGraph G){
    int i, m, n;
    Edge edges[MAXVEX];
    int parent[MAXVEX];
    Arc2Edges(G, edges);
    for(i = 0; i < G.numVertex; i++){ // 有多少个顶点，parent数组就有多少个元素
        parent[i] = 0;
    }
    for(i = 0; i < G.numEdges; i++){ // 对于边集数组中的每一条边
        // 开始检测是否有回路
        m = Find(parent, edges[i].begin);
        n = Find(parent, edges[i].end);
        if(m != n){ // 无回路
            parent[m] = n;
            printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int main(){
    printf("Hello World!");
    return 0;
}