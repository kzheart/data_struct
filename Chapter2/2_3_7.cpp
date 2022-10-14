//
// Created by kzheart on 2022/10/11.
//
#include "list.h"

void delInRange(LinkList l, int a, int b) {
    LinkNode *p = l->next;
    LinkNode *pre = l;
    while (p != NULL) {
        LinkNode *next = p->next;//提前记录以下个节点以免待会将该节点删除
        if (p->data >= a && p->data <= b) {
            pre->next = p->next;//将当前节点的连接断开
            free(p);
        } else {
            pre = p;//如果不用删则一直更新pre 需要删的话pre不用变
        }
        p = next;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList l;
    endBuildLinkListHead(l, a, 9);
    printf("删除前");
    printLinkList(l);
    printf("删除后");
    delInRange(l, 2, 6);
    printLinkList(l);
}