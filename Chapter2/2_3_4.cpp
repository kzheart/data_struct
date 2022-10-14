//
// Created by kzheart on 2022/10/11.
//
#include "list.h"

void delMinNode(LinkList l) {
    LinkNode *pre = l;//记录最小节点的前驱
    LinkNode *minPre = pre;
    LinkNode *p = l->next;
    int min = 0x7fffffff;
    while (p != NULL) {
        if (p->data < min) {
            min = p->data;
            minPre = pre;
        }
        pre = p;
        p = p->next;
    }
    p = minPre->next;//最小节点
    minPre->next = p->next;//跳过最小节点 连接到下一结点
    free(p);
}

int main() {
    int a[] = {2, 4, 12, 1, 6523, 324, 45, 123, 4, 564, 65};
    LinkList list;
    endBuildLinkListHead(list, a, 11);
    printf("删除前");
    printLinkList(list);
    printf("删除后");
    delMinNode(list);
    printLinkList(list);
}