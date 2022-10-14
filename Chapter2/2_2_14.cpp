//
// Created by kzheart on 2022/10/10.
//

#include "list.h"

int abss(int a) { return a >= 0 ? a : -a; }

int calcDistance(int a, int b, int c) {
    return abss(a - b) + abss(a - c) + abss(b - c);
}

/**
*  我是fw 这题我只会暴力解
*/
int findMinDistance(SqList a, SqList b, SqList c) {
    int min = 0x7ffffff;
    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a.length; j++) {
            for (int k = 0; k < a.length; k++) {
                int distance = calcDistance(a.data[i], b.data[j], c.data[k]);
                min = min < distance ? min : distance;
            }
        }
    }
    return min;
}

int main() {
    int a1[] = {-1, 0, 9};
    int l1 = 3;
    int a2[] = {-25, -10, 10, 11};
    int l2 = 4;
    int a3[] = {2, 9, 17, 30, 41};
    int l3 = 5;
    SqList a;
    SqList b;
    SqList c;
    initSqList(a, a1, l1);
    initSqList(b, a2, l2);
    initSqList(c, a3, l3);
    printf("最小距离为:%d", findMinDistance(a, b, c));
}