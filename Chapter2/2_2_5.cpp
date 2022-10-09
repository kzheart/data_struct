//
// Created by kzheart on 2022/10/9.
//
#include "common.h"

bool DeleteInST(SqList &l, int s, int t) {
    if (s >= t)
        return false;
    int k = 0;
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] >= s && l.data[i] <= t)
            k++;
        else
            l.data[i - k] = l.data[i];
    }
    l.length -= k;
    return true;
}

int main() {
    int a[] = {4, 1, 2, 5, 0, 0, 3};
    SqList s;
    initSqList(s, a, 7);
    printf("删除前");
    printSqList(s);
    DeleteInST(s, 1, 3);
    printf("删除后");
    printSqList(s);

}