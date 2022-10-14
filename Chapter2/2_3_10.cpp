//
// Created by kzheart on 2022/10/11.
//
#include "list.h"

void split(LinkList &a, LinkList &b) {
    LinkList aHead = (LinkNode *) malloc(sizeof(LinkNode));
    LinkList aRear = aHead;//a的尾部指针
    LinkList bHead = (LinkNode *) malloc(sizeof(LinkNode));
    LinkList bRear = bHead;//b的尾部指针
    LinkNode *p = a->next;
    int count = 1;//第一个元素为1
    while (p != NULL) {
        if (count % 2 == 1) {
            aRear->next = p;
            aRear = p;
        } else {
            bRear->next = p;
            bRear = p;
        }
        count++;
        p = p->next;
    }
    a = aHead;
    b = bHead;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkList al;
    LinkList bl;
    endBuildLinkListHead(al, a, 10);
    printf("分裂前al:");
    printLinkList(al);
    split(al, bl);
    printf("分裂后al:");
    printLinkList(al);
    printf("分裂后bl:");
    printLinkList(bl);

}
