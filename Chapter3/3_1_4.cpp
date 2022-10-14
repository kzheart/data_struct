//
// Created by kzheart on 2022/10/14.
//
#include "../Chapter2/list.h"
#include "stack.h"

bool isSymmetry(LinkList a) {
    LinkNode *p = a->next;
    SqStack s;
    while (p != NULL) {
        push(s, p->data);
        p = p->next;
    }
    p = a->next;
    while (p != NULL) {
        int x;
        pop(s, x);
        if (p->data != x)
            return false;
        p = p->next;
    }
    return true;
}

int main() {
    int a[] = {1, 2, 2};
    int b[] = {1, 2, 2, 1};

    LinkList al;
    LinkList bl;

    endBuildLinkListHead(al, a, 3);
    endBuildLinkListHead(bl, b, 4);
    printLinkList(al);
    printf("是否对称 %d", isSymmetry(al));
    printLinkList(bl);
    printf("是否对称 %d", isSymmetry(bl));


}
