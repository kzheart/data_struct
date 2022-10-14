//
// Created by kzheart on 2022/10/14.
//
#include "list.h"

int find(LinkList l, int pos) {
    if (pos <= 0)
        return 0;
    LinkNode *p = l->next;
    LinkNode *q = l->next;
    int count = 0;
    bool flag = false;//标记q是否可以开始走
    while (p != NULL) {
        if (count == pos) {
            flag = true;
        }
        if (flag)
            q = q->next;
        p = p->next;
        count++;
    }
    if (pos > count)//倒数的数量超出了长度
        return 0;
    if (q != NULL) {
        printf("倒数第%d个节点数据是%d", pos, q->data);
        return 1;
    } else
        return 0;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkList l;
    endBuildLinkListHead(l, a, 8);
    find(l, 9);
}