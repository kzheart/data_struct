//
// Created by kzheart on 2022/10/8.
//
#include "common.h"

bool DeleteMin(SqList &sqList, int &x) {
    if (sqList.length <= 0) {
        printf("数据长度错误");
        return false;
    }
    int min = sqList.data[0];//记录最小值
    int flag = 0;//记录最小值的位置
    for (int i = 1; i < sqList.length; i++) {
        if (sqList.data[i] < min) {
            min = sqList.data[i];
            flag = i;
        }
    }
    sqList.data[flag] = sqList.data[sqList.length - 1];
    sqList.length--;
    x = min;
    return true;
}

int main() {
    SqList l;
    int a[] = {2, 3, 4, 6, 7, 1, 8, 9};
    initSqList(l, a, 8);
    printf("删除前");
    int x;
    printSqList(l);
    DeleteMin(l, x);
    printf("删除后");
    printSqList(l);
    printf("%d", x);
    return 0;
}