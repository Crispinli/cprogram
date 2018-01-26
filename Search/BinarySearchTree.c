#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;

typedef struct BiNode {
    int data;
    struct BiNode *lchild;
    struct BiNode *rchlid;
} BiNode, *BiTree;

/* 在二叉排序树中查找 key */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p){
    if(!T){
        *p = f;
        return ERROR;
    }else if(key == T->data){
        *p = T;
        return OK;
    }else if(key < T->data){
        return SearchBST(T->lchild, key, T, p);
    }else if(key > T->data){
        return SearchBST(T->rchlid, key, T, p);
    }
}

/* 二叉排序树 T 中不包含关键字 key，则将其插入 T 中 */
Status InsertBST(BiTree *T, int key){
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p)){ // 查找不成功，p 所指向的结点无左子树或无右子树
        s = (BiTree)malloc(sizeof(BiNode));
        s->data = key;
        s->lchild = NULL;
        s->rchlid = NULL;
        if(!p){ // T 为空树
            *T = s; // 让 s 指向的结点成为根结点
        }else if(key > p->data){
            p->rchlid = s;
        }else if(key < p->data){
            p->lchild = s;
        }
        return OK;
    }else{
        return ERROR;
    }
}

/* 构建二叉排序树 */
void CreateBST(){
    int i;
    int a[10] = {62, 88, 58, 48, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL;
    for(i = 0; i < 10; i++){
        InsertBST(&T, a[i]);
    }
}

/* 在二叉排序树中查找关键字 key，若存在则删除 */
Status DeleteBST(BiTree *T, int key){
    if(!*T){
        return ERROR;
    }else{
        if(key == (*T)->data){
            return Delete(T);
        }else if(key < (*T)->data){
            return DeleteBST((*T)->lchild, key);
        }else if(key < (*T)->data){
            return DeleteBST((*T)->rchlid, key);
        }
    }
}

/* 删除操作 */
Status Delete(BiTree *p){
    BiTree q, s;
    if((*p)->rchlid == NULL){
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }else if((*p)->lchild == NULL){
        q = *p;
        *p = (*p)->rchlid;
        free(q);
    }else{
        q = *p;
        s = (*p)->lchild;
        while(s->rchlid){
            q = s;
            s = s->rchlid;
        }
        (*p)->data = s->data;
        if(q != *p){
            q->rchlid = s->lchild;
        }else{
            q->lchild = s->lchild;
        }
        free(s);
    }
}

int main(){
    printf("Hello World!");
    return 0;
}