//
// Created by kzheart on 2022/10/11.
//
#include "common.h"

/**
 * 我TM直接选择排序
 */
void sortList(LinkList list) {
    LinkNode *minP = list;//用于记录每一轮选出来的最小的节点
    while (minP->next != NULL) {
        LinkNode *head = minP;//每一轮循环的头节点
        LinkNode *p = head->next;
        LinkNode *pre = head;
        LinkNode *minPre = head;//最小值的前驱
        int min = 0x7fffffff;
        while (p != NULL) {
            if (p->data < min) {
                minP = p;
                min = p->data;
                minPre = pre;
            }
            pre = p;
            p = p->next;
        }
        minPre->next = minPre->next->next;//断开与最小值的连接
        minP->next = head->next;//最小值连接头节点后的一个节点
        head->next = minP;//头节点连接最小值节点
    }
}

int main() {
    int a[] = {4, 3, 2, 1,5,1,423,541,545,12,65,23};
    LinkList l;
    endBuildLinkListHead(l, a, 12);
    printf("排序前");
    printLinkList(l);
    printf("排序后");
    sortList(l);
    printLinkList(l);
    printf("排序后");

}