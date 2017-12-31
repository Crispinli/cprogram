#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

/* 二叉链表结点结构定义 */
typedef struct BiTNode {
    struct BiTNode *lchild;
    TElemType data;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

/* 二叉树的前序遍历算法 */
void PreOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    printf("%c", T->data); // 显示根结点数据
    PreOrderTraverse(T->lchild); // 前序遍历左子树
    PreOrderTraverse(T->rchild); // 前序遍历右子树
}

/* 二叉树的中序遍历算法 */
void InOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

/* 二叉树的后序遍历 */
void PostOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

/* 根据扩展二叉树的前序遍历序列创建一棵二叉树 */
void CreateBiTree_Pre(BiTree T){
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#'){
        T = NULL;
    }else{
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T){
            exit(-1);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

/* 根据扩展二叉树的中序遍历序列创建一棵二叉树 */
void CreateBiTree_In(BiTree T){
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#'){
        T = NULL;
    }else{
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T){
            exit(-1);
        }
        CreateBiTree_In(T->lchild);
        T->data = ch;
        CreateBiTree_In(T->rchild);
    }
}

/* 根据扩展二叉树的后序遍历序列创建一棵二叉树 */
void CreateBiTree_Post(BiTree T){
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#'){
        T = NULL;
    }else{
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T){
            exit(-1);
        }
        CreateBiTree_Post(T->lchild);
        CreateBiTree_Post(T->rchild);
        T->data = ch;
    }
}

int main(){
    printf("%s", "Hello World!");
    return 0;
}