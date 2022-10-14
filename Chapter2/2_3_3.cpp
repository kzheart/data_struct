//
// Created by kzheart on 2022/10/10.
//
#include "list.h"

/**
 * 逆向输出可以想到栈，而递归就是系统自动实现的栈 无需自己定义栈结构
 */
void reversePrint(LinkList l) {
    if (l != NULL) {
        reversePrint(l->next);
        printf("%d", l->data);
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    LinkList list;
    endBuildLinkListHead(list, a, 5);
    reversePrint(list);
}