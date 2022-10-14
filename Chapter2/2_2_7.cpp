//
// Created by kzheart on 2022/10/9.
//
#include "list.h"

SqList merge(SqList a, SqList b) {
    int i = 0;//指向a的指针
    int j = 0;//指向b的指针
    SqList s;
    int length = 0;
    while (i < a.length && j < b.length) {
        if (a.data[i] <= b.data[j])//此时a中的是较小元素
            s.data[length++] = a.data[i++];//将指针后移赋值给新顺序表
        else
            s.data[length++] = b.data[j++];
    }
    while (i < a.length)//判断是否还有未添加的内容
        s.data[length++] = a.data[i++];
    while (i < b.length)
        s.data[length++] = b.data[j++];
    s.length = length;
    return s;
}

int main() {
    int aa[] = {2, 3, 4, 6, 7};
    int ba[] = {3, 4, 4};
    SqList a;
    SqList b;
    initSqList(a, aa, 5);
    initSqList(b, ba, 3);
    printf("合并后");
    printSqList(merge(a, b));
}