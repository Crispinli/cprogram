#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct EdgeNode {
    int adjvex;
    int weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {
    int in;
    int data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes;
    int numEdges;
} graphAdjList, *GraphAdjList;

int *etv, *ltv;
int *stack2;
int top2;

Status TopologicalSort(GraphAdjList GL){
    EdgeNode *e;
    int i, k;
    int top = 0;
    int gettop;
    int count = 0;
    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i = 0; i < GL->numVertexes; i++){
        etv[i] = 0;
        if(GL->adjList[i].in == 0){
            stack[++top] = i;
        }
    }
    top2 = 0;
    while(top != 0){
        gettop = stack[top--];
        count++;
        stack2[++top2] = gettop;
        for(e = GL->adjList[gettop].firstedge; e; e = e->next){
            k = e->adjvex;
            if(--GL->adjList[k].in == 0){
                stack[++top] = k;
            }
            if(etv[k] < etv[gettop] + e->weight){
                etv[k] = etv[gettop] + e->weight;
            }
        }
    }
    if(count == GL->numVertexes){
        return OK;
    }else{
        return ERROR;
    }
}

void CriticalPath(GraphAdjList GL){
    EdgeNode *e;
    int i, k;
    int gettop;
    int ete, lte;
    TopologicalSort(GL);
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i = 0; i < GL->numVertexes; i++){
        ltv[i] = etv[GL->numVertexes - 1];
    }
    while(top2 != 0){
        gettop = stack2[top2--];
        for(e = GL->adjList[gettop].firstedge; e; e = e->next){
            k = e->adjvex;
            if(ltv[gettop] > ltv[k] - e->weight){
                ltv[gettop] = ltv[k] - e->weight;
            }
        }
    }
    for(i = 0; i < GL->numVertexes; i++){
        for(e = GL->adjList[i].firstedge; e; e = e->next){
            k = e->adjvex;
            ete = etv[i];
            lte = ltv[k] - e->weight;
            if(ete == lte){
                printf("<v%d, v%d> length: %d, ", GL->adjList[i].data, GL->adjList[k].data, e->weight);
            }
        }
    }
}

int main(){
    printf("Hello World!");
    return 0;
}