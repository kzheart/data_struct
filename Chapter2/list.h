

#ifndef DATA_STRUCT_LIST_H
#define DATA_STRUCT_LIST_H

#include <cstdio>
#include <cstdlib>

struct SqList {
    int data[50];
    int length;
};
/**
 * 单链表
 */
typedef struct LinkNode {
    int data{};
    struct LinkNode *next = NULL;
} LinkNode, *LinkList;
/**
 * 双链表
 */
typedef struct DoubleLinkNode {
    int data;
    struct DoubleLinkNode *pre = NULL;
    struct DoubleLinkNode *next = NULL;
} DoubleLinkNode, *DoubleLinkList;


/**
 * 循环双链表初始化 带头结点
 * @param l
 * @param a
 */
void initCycleDoubleHead(DoubleLinkList &l, int a[], int length) {
    l = (DoubleLinkList) malloc(sizeof(DoubleLinkNode));
    l->next = l;
    l->pre = l;
    DoubleLinkNode *rear = l;
    for (int i = 0; i < length; i++) {
        DoubleLinkNode *p = (DoubleLinkNode *) malloc(sizeof(DoubleLinkNode));
        p->data = a[i];
        rear->next = p;//尾结点连接至当前结点
        p->pre = rear;
        p->next = l;
        l->pre = p;
        rear = p;
    }
}

/**
 * 循环单链表初始化
 */
void initCycleSingleHead(LinkList &l, int a[], int length) {
    l = (LinkList) malloc(sizeof(LinkNode));
    l->next = l;
    LinkNode *rear = l;
    for (int i = 0; i < length; i++) {
        LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
        p->data = a[i];
        rear->next = p;
        p->next = l;
        rear = p;
    }
}


/**
 * 打印循环双链表
 */
void printCycleDoubleList(DoubleLinkList l) {
    DoubleLinkNode *p = l->next;
    printf("\n");
    while (p != l) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 打印顺序表
 */
void printSqList(SqList list) {
    printf("\n");
    for (int i = 0; i < list.length; i++) {
        printf("%d", list.data[i]);
    }
    printf("\n");
}

/**
 * 尾插法建立无头结点单链表
 */
void endBuildLinkListNoHead(LinkList &l, int a[], int length) {
    if (length <= 0)
        return;
    l = (LinkList) malloc(sizeof(LinkNode));
    l->data = a[0];
    LinkList r = l;//尾部指针
    for (int i = 1; i < length; i++) {
        r->next = (LinkList) malloc(sizeof(LinkNode));
        r->next->data = a[i];
        r = r->next;
    }
}


/**
 * 尾插法建立带头结点单链表
 */
void endBuildLinkListHead(LinkList &l, int a[], int length) {
    if (length <= 0)
        return;
    l = (LinkList) malloc(sizeof(LinkNode));
    LinkList r = l;//尾部指针
    for (int i = 0; i < length; i++) {
        r->next = (LinkList) malloc(sizeof(LinkNode));
        r->next->data = a[i];
        r = r->next;
    }
}

/**
 * 带头节点单链表插入节点
 * 0代表插入最前面
 */
void insertNodeHead(LinkList l, int index, LinkNode *node) {
    int count = 0;
    LinkNode *p = l->next;
    LinkNode *pre = l;
    while (p != NULL) {
        if (count == index) {
            node->next = p;
            pre->next = node;
            break;
        }
        count++;
        pre = p;
        p = p->next;
    }
    //插入到最后结点
    if (count == index) {
        node->next = p;
        pre->next = node;
    }
}

/**
 * 打印非循环单链表
 */
void printLinkList(LinkList l) {
    LinkList p = l->next;
    printf("\n");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

}

/**
 * 打印循环单链表
 */
void printCycleLinkList(LinkList l) {
    LinkNode *p = l->next;
    printf("\n");
    while (p != l) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void initSqList(SqList &list, int a[], int length) {
    list.length = length;
    for (int i = 0; i < length; i++) {
        list.data[i] = a[i];
    }
}

void printArray(int a[], int length) {
    printf("\n");
    for (int i = 0; i < length; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}


#endif //DATA_STRUCT_LIST_H
