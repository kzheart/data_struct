//
// Created by kzheart on 2022/10/10.
//

#include "list.h"

void reverse(int a[], int start, int end) {
    for (int i = start; i < (start + end + 1) / 2; i++) {
        int temp = a[i];
        a[i] = a[start + end - i];
        a[start + end - i] = temp;
    }
}

void leftMove(SqList &s, int p) {
    reverse(s.data, 0, p - 1);//逆置前半部分
    reverse(s.data, p, s.length - 1);//逆置后半部分
    reverse(s.data, 0, s.length - 1);//逆置整体
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    SqList s;
    initSqList(s, a, 6);
    printf("左移前");
    printSqList(s);
    leftMove(s, 5);
    printf("左移后");
    printSqList(s);
}