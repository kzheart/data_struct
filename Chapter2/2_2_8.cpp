//
// Created by kzheart on 2022/10/9.
//
#include "common.h"

void singleReverse(int a[], int start, int end) {
    for (int i = start; i < (end + start + 1) / 2; i++) {
        int temp = a[i];
        a[i] = a[start + end - i];
        a[start + end - i] = temp;

    }
}

void reverse(int a[], int m, int n) {
    singleReverse(a, 0, m - 1);//逆置前半部分
    singleReverse(a, m, m + n - 1);//逆置后半部分
    singleReverse(a, 0, m + n - 1);//逆置整体
}

void reverse(SqList &l, int m, int n) {
    reverse(l.data, m, n);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    SqList s;
    initSqList(s, a, 7);
    reverse(s, 3, 4);
    printf("逆置后");
    printSqList(s);
}
