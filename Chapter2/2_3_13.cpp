//
// Created by kzheart on 2022/10/12.
//
#include "common.h"

/**
 * 算法思想： 两个单链表整序 合并逆序 二路归并 头插法实现
 * 默认为带头结点单链表
 */
void mergeDe(LinkList a, LinkList b) {
    LinkNode *pa = a->next;
    LinkNode *pb = b->next;
    a->next = NULL;//置空待会头插法要用
    while (pa != NULL && pb != NULL) {
        LinkNode *aNext = pa->next;
        LinkNode *bNext = pb->next;
        if (pa->data <= pb->data) {
            //a的数值小于b 头插法插入a  a为最终要用的那个结点
            pa->next = a->next;//当前结点连接头节点的下一个结点
            a->next = pa;
            pa = aNext;
        } else {
            //b的数值小 头插法将其插入a
            pb->next = a->next;
            a->next = pb;
            pb = bNext;
        }
    }
    //如果a还有剩余结点 继续头插法
    while (pa != NULL) {
        LinkNode *next = pa->next;
        pa->next = a->next;
        a->next = pa;
        pa = next;
    }
    //如果b还有剩余结点
    while (pb != NULL) {
        LinkNode *next = pb->next;
        pb->next = a->next;
        a->next = pb;
        pb = next;
    }
}


int main() {
    int a[] = {1, 5, 6, 7, 10, 14, 43, 45, 66, 79};
    int b[] = {1, 2, 2, 4, 5, 12, 45, 78, 90, 120};
    LinkList al;
    LinkList bl;
    endBuildLinkListHead(al, a, 10);
    endBuildLinkListHead(bl, b, 10);
    printf("合并前a:");
    printLinkList(al);
    printf("合并前b:");
    printLinkList(bl);
    mergeDe(al, bl);
    printf("合并后a:");
    printLinkList(al);


}