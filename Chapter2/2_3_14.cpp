//
// Created by kzheart on 2022/10/12.
//
#include "list.h"

/**
 * 算法思想 两个链表两个指针 哪个小哪个往后移动 移动之后判断是否相等 相等则加回去
 */
void mergeToC(LinkList a, LinkList b, LinkList &c) {
    LinkNode *pa = a->next;
    LinkNode *pb = b->next;
    c = (LinkNode *) malloc(sizeof(LinkNode));
    LinkNode *cRear = c;//c的尾指针
    c->data = -9999;
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            //此时说明 a的数据小 a指针往后移动
            pa = pa->next;
        } else if (pa->data > pb->data) {
            pb = pb->next;
        } else {
            //此时相等可以加到c后面同时判断这个数值是否已经加到c中
            if (pa->data != cRear->data) {
                LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));//新的尾指针
                p->data = pa->data;
                cRear->next = p;
                cRear = p;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    c->data = 0;
}

int main() {
    int a[] = {2, 2, 4, 5, 8};
    int b[] = {2, 2, 4, 5, 7, 8};
    LinkList al;
    LinkList bl;
    endBuildLinkListHead(al, a, 5);
    endBuildLinkListHead(bl, b, 6);
    LinkList cl;
    printf("合并前al:");
    printLinkList(al);
    printf("合并前bl:");
    printLinkList(bl);
    mergeToC(al, bl, cl);
    printf("合并后al:");
    printLinkList(al);
    printf("合并后bl:");
    printLinkList(bl);
    printf("合并后cl:");
    printLinkList(cl);

}