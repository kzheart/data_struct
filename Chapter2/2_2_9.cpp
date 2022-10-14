//
// Created by kzheart on 2022/10/9.
//
#include "list.h"

//折半查找 找到则返回位置 找不到返回-1
int halfFind(int a[], int length, int x, int &end) {
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int half = (low + high) / 2;
        if (x < a[half])//要找的元素在左半部分
            high = half - 1;
        else if (x > a[half])//要找的元素右半部分
            low = half + 1;
        else
            return half;
    }
    end = low;
    return -1;
}

void find(SqList &l, int x) {
    int end;//若失败了记录最终停止的位置
    int index = halfFind(l.data, l.length, x, end);
    if (index != -1) {
        int temp = l.data[index];
        int backIndex = index == l.length - 1 ? 0 : index + 1;//获取后继 如果是最后一个元素则后继设置为第一个元素
        l.data[index] = l.data[backIndex];
        l.data[backIndex] = temp;
    } else {
        if (x > l.data[end]) {//此时x要插入到最终位置后面
            for (int i = l.length - 1; i > end; i--)
                //除了end位置所有元素后移
                l.data[i + 1] = l.data[i];

            l.data[end + 1] = x;
        } else {
            //x要插入到最终位置前面
            for (int i = l.length - 1; i >= end; i--)
                l.data[i + 1] = l.data[i];
            l.data[end] = x;
        }
        l.length++;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 7, 10};
    SqList s;
    initSqList(s, a, 7);
    printf("查找前");
    printSqList(s);
    find(s, 9);
    printf("查找后");
    printSqList(s);


}