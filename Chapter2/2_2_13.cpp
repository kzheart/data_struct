//
// Created by kzheart on 2022/10/10.
//
#include "common.h"

/**
 * 算法思想:
 * 题可知最终结果的取值范围从1到n+1
 * 可以创建一个n+2的数组
 * 分别记录数据中出现过的数字
 * 例如 1 2 3 当1出现时将1 a[1] = 1 代表1出现过,a[2] = 1 a[3] = 1
 * 最后遍历1到n+1找到第一个没出现过的数字
 */
int findMin(SqList s) {
    int record[s.length + 2];
    for (int i = 1; i < s.length + 2; i++) {
        record[i] = 0;//初始化
    }
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] >= 1)
            record[s.data[i]] = 1;//记录每个数字出现的次数
    }
    int k;
    for (int i = 1;; i++) {
        if (record[i] == 0) {
            k = i;
            break;
        }
    }
    return k;
}

int main() {
    int a[] = {1, 2, 3};
    SqList s;
    initSqList(s, a, 3);
    printf("最小正整数为:%d", findMin(s));
}