//
// Created by kzheart on 2022/10/11.
//
#include "list.h"

/**
 * 两个循环暴力搜 默认为带头节点的链表
 */
LinkNode *findPublicNode(LinkList a, LinkList b) {
    LinkNode *pa = a->next;
    while (pa != NULL) {
        LinkNode *pb = b->next;
        while (pb != NULL) {
            if (pa == pb)
                return pa;
            pb = pb->next;
        }
        pa = pa->next;
    }
    return NULL;
}


int main() {
    LinkNode *publicNode = (LinkNode *) malloc(sizeof(LinkNode));
    publicNode->data = 9999;
    int a[] = {1, 2, 4, 5};
    int b[] = {4, 3, 2, 1};
    LinkList al;
    LinkList bl;
    endBuildLinkListHead(al, a, 4);
    endBuildLinkListHead(bl, b, 4);
    printf("插入前al:");
    printLinkList(al);
    printf("插入前bl:");
    printLinkList(bl);
    insertNodeHead(al, 4, publicNode);
    insertNodeHead(bl, 4, publicNode);
    printf("插入后al:");
    printLinkList(al);
    printf("插入后bl:");
    printLinkList(bl);
    printf("公共结点的数值为:%d", findPublicNode(al, bl)->data);

}