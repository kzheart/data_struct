//
// Created by kzheart on 2022/10/13.
//
#include "list.h"

/**
 * a: 1 2 3 4 5 6
 * b: 4 5 6 7
 * 算法思想： 两个指针不断后移，b的数字只能大于等于a 若b的数字比a的要小则说明不符
 */
bool isCommonSequence(LinkList a, LinkList b) {
    LinkNode *pa = a->next;
    LinkNode *pb = b->next;
    bool flag = false;//标记是否开始连续扫描，只要遇到第一个相同的就说明要开始连续扫描后面是否都相同 有一个不相同则不是连续子序列
    while (pb != NULL && pa != NULL) {
        if (pa->data < pb->data) {
            if (!flag) {
                pa = pa->next;//此时还没有遇到第一个相同元素
            } else {
                //此时已经开始连续扫描  扫描到不同的元素直接返回false
                return false;
            }
        } else if (pa->data == pb->data) {
            flag = true;//遇到相同说明开始连续扫描
            pa = pa->next;//不断后置
            pb = pb->next;
        } else
            return false;
    }
    if (pa == NULL && pb != NULL) {
        //此时pa都搜索完了 pb还没有结束 pb比pa还要长
        return false;
    }
    return true;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 2, 3, 4, 5};
    LinkList al;
    LinkList bl;
    endBuildLinkListHead(al, a, 6);
    endBuildLinkListHead(bl, b, 6);
    printf("al:");
    printLinkList(al);
    printf("bl:");
    printLinkList(bl);
    printf("是否是连续子序列:%d", isCommonSequence(al, bl));
}