#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

BiThrTree pre; // 全局变量，始终指向刚刚访问过的结点

/* 中序遍历线索化 */
void InOrderThreading(BiThrTree p){
    if(p){
        InOrderThreading(p->lchild);
        if(!p->lchild){
            p->LTag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild){
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InOrderThreading(p->rchild);
    }
}

/* 中序遍历二叉线索链表表示的二叉树T */
Status InOrderTraverse_Thr(BiThrTree T){
    BiThrTree p;
    p = T->lchild;
    while(p != T){
        while(p->LTag == Link){ // 找到所在子树的序列中的第一个结点
            p = p->lchild;
        }
        printf("%c", p->data);
        while(p->RTag == Thread && p->rchild != T){
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}

int main(){
    printf("%s", "Hello World!");
    return 0;
}