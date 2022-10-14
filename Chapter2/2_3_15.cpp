//
// Created by kzheart on 2022/10/12.
//
#include "list.h"

/**
 * 算法思想:同上一个题类似不过该题找到结点之后是将结点放回a中
 */
void findMixed(LinkList a, LinkList b) {
    LinkNode *pa = a->next;
    LinkNode *pb = b->next;
    LinkNode *aRear = a;
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            //pa数据小pa后移
            pa = pa->next;
        } else if (pa->data > pb->data) {
            //pb数据小pb后移
            pb = pb->next;
        } else {
            //此时相等可以加到后面 同时判断该节点是否已经加过了
            if (aRear->data != pa->data) {
                LinkNode *aNext = pa->next;
                aRear->next = pa;
                aRear = pa;
                pa->next = NULL;//当前这个结点已经加到a的尾部 所以作为最后一个结点next应该置空
                pa = aNext;
                pb = pb->next;
            } else {
                pa = pa->next;
                pb = pb->next;
            }
        }
    }

}

int main() {
    int a[] = {2, 2, 4, 5, 8, 9};
    int b[] = {2, 2, 4, 5, 7, 8, 9};
    LinkList al;
    LinkList bl;
    endBuildLinkListHead(al, a, 6);
    endBuildLinkListHead(bl, b, 7);
    printf("合并前al:");
    printLinkList(al);
    printf("合并前bl:");
    printLinkList(bl);
    findMixed(al, bl);
    printf("合并后al:");
    printLinkList(al);
    printf("合并后bl:");
    printLinkList(bl);
}