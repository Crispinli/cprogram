#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;

// 双亲表示法的树中结点数据结构
typedef struct {
    TElemType data;
    int parent;
} PTNode;

// 双亲表示法的树的数据结构
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int r;  // 根的位置
    int n;  // 结点数
} PTrees;

// 孩子表示法的树中结点数据结构
typedef struct CTNode {
    int child;
    struct CTNode *next;
} *ChildPtr;

// 孩子表示法的表头结构
typedef struct {
    TElemType data;
    ChildPtr firstchild;
} CTBox;

// 孩子表示法的树结构
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n;
} CTree;

// 孩子兄弟表示法的结构
typedef struct CSNode {
    TElemType data;
    struct CSNode * firstchild;
    struct CSNode * rightsib;
} CSNode, *CSTree;

int main(){
    return 0;
}