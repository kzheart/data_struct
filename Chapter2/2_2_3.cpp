//
// Created by kzheart on 2022/10/8.
//
#include "list.h"

void DeleteX(SqList &l, int x) {
    int k = 0;
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] == x) {
            k++;
        } else {
            l.data[i - k] = l.data[i];
        }
    }
    l.length -= k;
}

int main() {
    int a[] = {5, 2, 0, 1, 3, 1, 4, 1, 1, 4};
    SqList sq;
    initSqList(sq, a, 10);
    printf("删除前");
    printSqList(sq);
    DeleteX(sq, 1);
    printf("删除后");
    printSqList(sq);
}