//
// Created by kzheart on 2022/10/10.
//
#include "list.h"

/**
 * 算法思想  计算两个数列长度计算出中位数所在的位置 然后 两个数列二路归并找到所在位置元素 (无需全部合并用变量记录当前合并了几个元素 合并到中位数即可)
 */
int findMid(SqList a, SqList b) {
    int mid = a.length + b.length % 2 == 0 ? (a.length + b.length) / 2 : (a.length + b.length) / 2 + 1;//向上取整
//    int mid = (a.length + b.length) / 2;
    int count = 1;//记录当前找的位置
    int i = 0;//指向a的指针
    int j = 0;//指向b的指针
    int k;//记录中位数
    while (i < a.length - 1 && j < a.length - 1 && count != mid) {
        if (a.data[i] < b.data[j]) {
            k = a.data[i++];
        } else {
            k = b.data[j++];
        }
        count++;
    }
    while (i < a.length - 1 && count != mid) {
        k = a.data[i++];
        count++;
    }
    while (j < a.length - 1 && count != mid) {
        k = b.data[j++];
        count++;
    }
    return k;
}


int main() {
    int aa[] = {2, 4, 6, 8, 10};
    int ba[] = {1, 3, 5, 7, 9};
    SqList a;
    SqList b;
    initSqList(a, aa, 5);
    initSqList(b, ba, 5);
    printf("中位数为");
    printf("%d", findMid(a, b));
}