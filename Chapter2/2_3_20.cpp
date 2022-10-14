//
// Created by kzheart on 2022/10/13.
//
#include "list.h"

/**
 * 带访问频度的头指针双向链表
 */
typedef struct DoubleLinkNodeFreq {
    int data;
    struct DoubleLinkNodeFreq *next;
    struct DoubleLinkNodeFreq *pre;
    int prep = 0;
} DoubleLinkNodeFreq, *DoubleLinkListFreq;

/**
 * 打印循环双链表 直接复制common中的
 */
void printCycleDoubleList(DoubleLinkListFreq l) {
    DoubleLinkNodeFreq *p = l->next;
    printf("\n");
    while (p != l) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 循环双链表初始化 带头结点
 * @param l
 * @param a
 */
void initCycleDoubleHead(DoubleLinkListFreq &l, int a[], int length) {
    l = (DoubleLinkListFreq) malloc(sizeof(DoubleLinkNodeFreq));
    l->next = l;
    l->pre = l;
    DoubleLinkNodeFreq *rear = l;
    for (int i = 0; i < length; i++) {
        DoubleLinkNodeFreq *p = (DoubleLinkNodeFreq *) malloc(sizeof(DoubleLinkNodeFreq));
        p->data = a[i];
        rear->next = p;//尾结点连接至当前结点
        p->pre = rear;
        p->next = l;
        l->pre = p;
        rear = p;
    }
}

/**
 * 算法思想 每次找到对应元素将其访问频度加1 然后从表头开始找到第一个比他频度要大的，没有则在表头，然后插到后面
 */
DoubleLinkNodeFreq *Locate(DoubleLinkListFreq l, int x) {
    DoubleLinkNodeFreq *p = l->next;
    while (p != l) {
        if (p->data == x) {
            p->prep++;
            p->pre->next = p->next;//p的前面的连接到其后面
            p->next->pre = p->pre;//p后面的连接到其前面
            DoubleLinkNodeFreq *pp = l;
            //如果当前频度比第一个小就一直往后找 比如第一个频度是3 但是当前频度只有2 则找到最后一个3后边插到他后边
            while (p->prep < pp->next->prep) {
                pp = pp->next;
            }
            p->next = pp->next;//让p连接pp后面那个
            pp->next->pre = p;//pp后面那个连接到p
            pp->next = p;//再让pp连接p
            p->pre = pp;
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/**
 * Locate几次某个数值
 */
void repeat(int count, int x, DoubleLinkListFreq l) {
    for (int i = 0; i < count; i++) {
        DoubleLinkNodeFreq *p = Locate(l, x);
        printf("\n");
        printf("正在访问%d 当前频度%d", p->data, p->prep);
    }
}

int main() {
    DoubleLinkListFreq l;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    initCycleDoubleHead(l, a, 9);
    printf("访问前");
    printCycleDoubleList(l);
    repeat(3, 9, l);
    repeat(2, 4, l);
//    repeat(3, 4, l);
    printf("\n访问后");
    printCycleDoubleList(l);
}