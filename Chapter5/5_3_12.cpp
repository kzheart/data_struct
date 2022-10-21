//
// Created by kzheart on 2022/10/21.
//
#include "tree.h"

void printAncestor(BiTree biTree, int x) {
    BiNode *p = biTree;
    BiNode *r = NULL;
    BiTreeSqStack stack;
    while (!isEmpty(stack) || p) {
        if (p) {
            push(stack, p);
            p = p->lchild;
        } else {
            getTop(stack, p);
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            } else {
                pop(stack, p);
                if (p->data == x) {
                    //此时栈中所有元素均为p的父结点
                    while (!isEmpty(stack)) {
                        pop(stack, p);
                        printf(" %d ", p->data);
                    }
                    return;
                }
                r = p;
                p = NULL;
            }
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    BiTree biTree;
    buildTree(biTree, a, 8);
    printBiTree(biTree, 1);
    printAncestor(biTree, 5);
}