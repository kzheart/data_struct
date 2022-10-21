//
// Created by kzheart on 2022/10/18.
//
#include "tree.h"

/**
 * 算法思想 使用层序遍历逐层遍历
 * 核心: 每次出队元素之后 最后进入队列的那个元素即为下一层的最后一个元素
 * @return
 */
int getHeight(BiTree biTree) {
    if (biTree == NULL)
        return 0;
    BiTreeSqQueue queue;
    EnQueue(queue, biTree);
    int last = 0;//记录队列中每一层的最后一个结点
    int level = 0;
    while (!isEmpty(queue)) {
        BiNode *biNode;
        DeQueue(queue, biNode);
        if (biNode->lchild != NULL)
            EnQueue(queue, biNode->lchild);
        if (biNode->rchild != NULL)
            EnQueue(queue, biNode->rchild);
        if (queue.front - 1 == last) {
            last = queue.rear - 1;
            level++;
        }

    }
    return level;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    BiTree biTree;
    buildTree(biTree, a, 15);
    printBiTree(biTree, 1);
    printf("height:%d", getHeight(biTree));
}