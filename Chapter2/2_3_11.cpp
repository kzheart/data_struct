//
// Created by kzheart on 2022/10/11.
//
#include "common.h"

void spilt(LinkList hc, LinkList &a, LinkList &b) {
    int count = 1;
    LinkNode *p = hc->next;
    LinkNode *aHead = (LinkNode *) malloc(sizeof(LinkNode));
    LinkNode *bHead = (LinkNode *) malloc(sizeof(LinkNode));
    LinkNode *aRear = aHead;
    while (p != NULL) {
        LinkNode *next = p->next;//头插法会对p next操作 提前记录
        if (count % 2 == 1) {
            //尾插法插入到a中
            aRear->next = p;
            aRear = p;
            p->next = NULL;//尾部置空
        } else {
            //头插法插入到b中
            p->next = bHead->next;
            bHead->next = p;
        }
        count++;
        p = next;
    }
    a = aHead;
    b = bHead;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkList hc;
    endBuildLinkListHead(hc, a, 10);
    LinkList al;
    LinkList bl;
    printf("分裂前:");
    printLinkList(hc);
    spilt(hc, al, bl);
    printf("分裂后a:");
    printLinkList(al);
    printf("分裂后b:");
    printLinkList(bl);
}


