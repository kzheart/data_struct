//
// Created by kzheart on 2022/10/10.
//

#include "common.h"

/**
 * 算法思想: 题中给出了内部元素的范围是0到n 即有n+1种数字 创建一个n+1大小的数组 分别记录每种数字出现的个数最后比较即可
 */
int major(SqList s) {
    int record[s.length + 1];
    for (int i = 0; i < s.length + 1; i++)
        record[i] = 0;//初始化
    for (int i = 0; i < s.length; i++) {
        if (++record[s.data[i]] > s.length / 2)
            return s.data[i];//记录每个数字出现的次数 同时判断一下次数
    }
    return -1;
}

int main() {
    int a[] = {0, 3, 3, 3, 4, 3, 5, 5};
    SqList s;
    initSqList(s, a, 8);
    printf("主元素为%d", major(s));
}

