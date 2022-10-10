

#ifndef DATA_STRUCT_COMMON_H
#define DATA_STRUCT_COMMON_H

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


void printLinkList(LinkList l) {
    LinkList p = l;
    printf("\n");
    while (p != NULL) {
        printf("%d", p->data);
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


#endif //DATA_STRUCT_COMMON_H
