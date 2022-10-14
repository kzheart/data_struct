//
// Created by kzheart on 2022/10/10.
//
#include "list.h"

void delX(LinkList l, int x) {
    LinkNode *pre = l;//前一个指针
    LinkNode *p = l->next;//遍历指针
    while (p != NULL) {
        if (p->data == x) {
            LinkNode *temp = p;
            pre->next = p->next;
            p = pre;//退回之后 下面的p=p->next会重新指向下一个节点 同时pre也不会改变
            free(temp);
        }
        pre = p;
        p = p->next;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    LinkList list;
    endBuildLinkListHead(list, a, 5);
    printf("删除前");
    printLinkList(list);
    printf("删除后");
    delX(list, 3);
    printLinkList(list);
}