

#ifndef DATA_STRUCT_COMMON_H
#define DATA_STRUCT_COMMON_H

#include <cstdio>

struct SqList {
    int data[50];
    int length;
};

void printSqList(SqList list) {
    printf("\n");
    for (int i = 0; i < list.length; i++) {
        printf("%d", list.data[i]);
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
