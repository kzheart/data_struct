//
// Created by kzheart on 2022/10/17.
//
#include "tree.h"


void visit(BiNode *biNode) {
    printf(" %d ", biNode->data);
}

/**
 * 算法思想 层次遍历出压入栈中再出栈遍历
 */
void traverse(BiTree biTree) {
    BiTreeSqQueue q;
    BiTreeSqStack s;
    BiNode *p = biTree;
    EnQueue(q, p);
    while (!isEmpty(q)) {
        DeQueue(q, p);
        if (p->lchild != NULL) {
            EnQueue(q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(q, p->rchild);
        }
        push(s, p);
    }
    while (!isEmpty(s)) {
        pop(s, p);
        visit(p);
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    BiTree biTree;
    buildTree(biTree, a, 6);
    printf("层次遍历:");
    levelVisit(biTree, visit);
    printf("反层次遍历");
    traverse(biTree);
}