//
// Created by kzheart on 2022/10/19.
//
#include "tree.h"

/**
 * 算法思想 按层序遍历 遇到空的直接将NULL也入队，当出队的时候如果遇到NULL之后又有不是NULL的 则不是完全二叉树
 */
bool isCompleteBiTree(BiTree biTree) {
    if (biTree != NULL) {
        BiTreeSqQueue biTreeSqQueue;
        BiNode *p = biTree;
        EnQueue(biTreeSqQueue, biTree);
        bool flag = false;//标记是否遇到NULL
        while (!isEmpty(biTreeSqQueue)) {
            DeQueue(biTreeSqQueue, p);
            if (p != NULL && !flag) {//p不为空并且此时还没遇到过NULL
                EnQueue(biTreeSqQueue, p->lchild);
                EnQueue(biTreeSqQueue, p->rchild);
            }
            if (p != NULL && flag)//p不为空 并且之前还遇到过NULL 则说明这是非完全二叉树
                return false;
            if (p == NULL)
                flag = true;
        }
        return true;
    } else
        return false;
}

int main() {
    int a[] = {1, 2, 4, 5, 6};
    BiTree biTree;
    buildTree(biTree, a, 5);
    printf("%d", isCompleteBiTree(biTree));
}