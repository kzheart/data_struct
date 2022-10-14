//
// Created by kzheart on 2022/10/13.
//

#include "list.h"

void merge(LinkList h1, LinkList h2) {
    if (h2->next == h2)
        return;//如果h2没有结点直接返回
    LinkNode *p = h1;
    LinkNode *q = h2;
    while (p->next != h1) {
        p = p->next;
    }
    //找到h1的最后一个节点

    while (q->next != h2) {
        q = q->next;
    }
    //找到h2的最后一个节点
    //然后就将h2的第一个结点连接到h1的尾部
    p->next = h2->next;
    //然后再将h2的最后一个结点连接到h1的头部
    q->next = h1;
}


int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[] = {8, 9, 10, 11, 12, 13};
    LinkList al;
    LinkList bl;
    initCycleSingleHead(al, a, 7);
    initCycleSingleHead(bl, b, 6);
    printf("合并前a:");
    printCycleLinkList(al);
    printf("合并前b:");
    printCycleLinkList(bl);
    merge(al, bl);
    printf("合并后a:");
    printCycleLinkList(al);
}