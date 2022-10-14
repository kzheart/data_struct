//
// Created by kzheart on 2022/10/8.
//
#include "list.h"

bool DeleteInST(SqList &l, int s, int t) {
    if (s >= t || l.length <= 0) {
        printf("非法");
        return false;
    }
    int start = -1;//记录起始位置
    int end = -1;//记录终止位置
    for (int i = 0; i < l.length; i++) {
        if (start == -1 && l.data[i] >= s && l.data[i] <= t)
            start = i;//此时说明已经进入范围内第一个
        if (start != -1 && end == -1 && l.data[i] > t) {
            end = i;//此时离开了探索范围
        }
        if (end != -1) {
            //此时所有的元素均为范围后的元素，全部前移
            l.data[i - (end - start)] = l.data[i];
        }
    }
    l.length -= end - start;
    return true;
}

int main() {
    SqList sq;
    int a[] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9};
    initSqList(sq, a, 12);
    printf("删除前");
    printSqList(sq);
    DeleteInST(sq, 3, 7);
    printf("删除后");
    printSqList(sq);


}