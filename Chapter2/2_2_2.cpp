//
// Created by kzheart on 2022/10/8.
//
#include "list.h"

void reverse(SqList &l) {
    for (int i = 0; i < l.length / 2; i++) {
        int temp = l.data[i];
        l.data[i] = l.data[l.length - i - 1];
        l.data[l.length - i - 1] = temp;
    }
}

int main() {
    SqList l;
    int a[] = {1, 4, 6, 3, 2, 8, 7};
    initSqList(l, a, 7);
    printf("逆置前");
    printSqList(l);
    reverse(l);
    printf("逆置后");
    printSqList(l);
    return 0;
}