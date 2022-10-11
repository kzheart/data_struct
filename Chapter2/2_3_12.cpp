//
// Created by kzheart on 2022/10/11.
//
#include "common.h"

void freeP(LinkNode *pre) {
    LinkNode *p = pre->next;
    if (p != NULL) {
        pre->next = p->next;
        free(p);
    }
}

void delSame(LinkList l) {
    LinkNode *p = l->next;
    LinkNode *pre = l;
    bool flag = false;
    while (p != NULL) {
        LinkNode *next = p->next;
        if (flag && p->data == pre->data) {
            //如果当前结点与上一个结点重复了则可以删除当前结点
            freeP(pre);//这个操作会将当前结点删除 并将pre连接到下一个结点
        } else {
            pre = p;
        }
        p = next;
        flag = true;//跳过第一次与头节点的比较 头结点默认为0 如果第一个结点为0也会被去掉
    }
}

int main() {
    int a[] = {0, 7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    LinkList list;
    endBuildLinkListHead(list, a, 11);
    printf("去重前:");
    printLinkList(list);
    delSame(list);
    printf("去重后:");
    printLinkList(list);
}