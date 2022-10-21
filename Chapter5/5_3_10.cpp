//
// Created by kzheart on 2022/10/20.
//
#include "tree.h"

void getPreNValue(BiTree biTree, int &count, int n, int &x) {
    if (biTree != NULL) {
        if (count == n) {
            x = biTree->data;
        }
        count++;
        getPreNValue(biTree->lchild, count, n, x);
        getPreNValue(biTree->rchild, count, n, x);
    }
}

void getPreNValue(BiTree biTree, int n, int &x) {
    int count = 1;
    getPreNValue(biTree, count, n, x);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    BiTree biTree;
    buildTree(biTree, a, 6);
    int x = 0;
    printBiTree(biTree, 1);
    for (int i = 1; i <= 6; i++) {
        getPreNValue(biTree, i, x);
        printf("第%d个访问的是%d\n", i, x);
    }
}
