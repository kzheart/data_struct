//
// Created by kzheart on 2022/10/20.
//
#include "tree.h"

void twoBranchCount(BiTree tree, int &count) {
    if (tree != NULL) {
        if (tree->rchild != NULL && tree->lchild != NULL)
            count++;
        twoBranchCount(tree->lchild, count);
        twoBranchCount(tree->rchild, count);
    }
}

int twoBranchCount(BiTree tree) {
    int count = 0;
    twoBranchCount(tree, count);
    return count;
}


int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    BiTree biTree;
    buildTree(biTree, a, 7);
    printBiTree(biTree, 1);
    printf("双分支结点个数:%d", twoBranchCount(biTree));
}