//
// Created by kzheart on 2022/10/11.
//
#include "list.h"

void freeP(LinkNode *pre) {
    LinkNode *p = pre->next;
    if (p != NULL) {
        printf("%d ", p->data);
        pre->next = p->next;
        free(p);
    }
}

void dePrint(LinkList l) {
    LinkNode *pre = l;
    LinkNode *p = l->next;

    while (p != NULL) {
        LinkNode *maxPre = pre;//记录最大结点的前驱结点
        int max = -10000000;
        while (p != NULL) {
            if (p->data > max) {
                maxPre = pre;
                max = p->data;
            }
            pre = p;
            p = p->next;
        }
        freeP(maxPre);
        p = l->next;
        pre = l;
    }
}

int main() {
    int a[] = {1, 2, 32, 312, 21343, 5, 34, 23, 3422, 34, 124};
    LinkList l;
    endBuildLinkListHead(l, a, 11);
    dePrint(l);
}

