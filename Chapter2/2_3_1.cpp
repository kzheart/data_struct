//
// Created by kzheart on 2022/10/10.
//

#include "list.h"

void delX(LinkList &l, int x) {
    if (l != NULL) {
        delX(l->next, x);
        if (l->data == x) {
            LinkList p = l;
            l = l->next;
            free(p);
        }
    } else
        return;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    LinkList list;
    endBuildLinkListNoHead(list, a, 5);
    printf("删除前");
    printLinkList(list);
    delX(list, 5);
    printf("删除后");
    printLinkList(list);
}