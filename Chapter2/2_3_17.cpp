//
// Created by kzheart on 2022/10/13.
//
#include "common.h"

/**
 * 算法思想 两个指针 一个正着遍历一个倒着遍历 判断是否相同
 */

bool isSymmetry(DoubleLinkList a, DoubleLinkList b) {
    DoubleLinkNode *pa = a->next;
    DoubleLinkNode *pb = b->pre;
    while (pa != a && pb != b) {
        if (pa->data != pb->data)
            return false;
        pa = pa->next;
        pb = pb->pre;
    }
    if (pa == a && pb == b) {
        return true;
    } else {
        return false;
    }
}


int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[] = {7, 6, 5, 4, 3, 2, 1};
    DoubleLinkList al;
    DoubleLinkList bl;
    initCycleDoubleHead(al, a, 7);
    initCycleDoubleHead(bl, b, 7);
//    printCycleDoubleList(l);
    printf("ab是否对称:%d", isSymmetry(al, bl));
}