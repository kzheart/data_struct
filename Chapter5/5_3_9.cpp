//
// Created by kzheart on 2022/10/20.
//
#include "tree.h"

void swapLR(BiTree tree) {
    if (tree != NULL) {
        swapLR(tree->lchild);
        swapLR(tree->rchild);
        BiNode *p = tree->lchild;
        tree->lchild = tree->rchild;
        tree->rchild = p;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    BiTree biTree;
    buildTree(biTree, a, 6);
    printf("交换前:\n");
    printBiTree(biTree, 1);
    swapLR(biTree);
    printf("交换后:\n");
    printBiTree(biTree, 1);
}
