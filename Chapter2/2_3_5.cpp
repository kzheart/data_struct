//
// Created by kzheart on 2022/10/11.
//
#include "common.h"

/**
 * 就地逆置
 * 算法思想：直接将遍历单链表头插法将后边所有节点插入头部
 * @param list
 */
void reverse(LinkList list) {
    LinkNode *head = list;//头结点，所有结点插入该结点之后
    LinkNode *p = list->next;
    head->next = NULL;
    while (p != NULL) {
        LinkNode *next = p->next;//临时保存下一个结点用于遍历
        p->next = head->next;//将该结点头插入到头节点后
        head->next = p;//让头节点连接该结点
        p = next;//遍历下一个结点
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    LinkList l;
    endBuildLinkListHead(l, a, 6);
    printf("逆置前");
    printLinkList(l);
    printf("逆置后");
    reverse(l);
    printLinkList(l);
}