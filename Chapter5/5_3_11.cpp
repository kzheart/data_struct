//
// Created by kzheart on 2022/10/21.
//
#include "tree.h"

void delTree(BiTree biTree) {
    if (biTree != NULL) {
        delTree(biTree->lchild);
        delTree(biTree->rchild);
        free(biTree);
    }
}

void delXRootTree(BiTree &biTree, int x) {
    if (biTree != NULL) {
        delXRootTree(biTree->lchild, x);
        delXRootTree(biTree->rchild, x);
        if (biTree->data == x) {
            delTree(biTree);
            biTree = NULL;
        }


    }

}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    BiTree biTree;
    buildTree(biTree, a, 7);
    printf("删除前:\n");
    printBiTree(biTree, 1);
    printf("删除后\n");
    delXRootTree(biTree, 2);
    printBiTree(biTree, 1);
}