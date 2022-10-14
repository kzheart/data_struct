//
// Created by kzheart on 2022/10/9.
//
#include "list.h"

bool DeleteSame(SqList &s) {
    if (s.length <= 0)
        return false;
    int last = s.data[0];//记录上次扫描到的数值
    int k = 0;
    for (int i = 1; i < s.length; i++) {
        if (s.data[i] != last) {
            last = s.data[i];
            s.data[i - k] = s.data[i];
        } else {
            k++;
        }
    }
    s.length -= k;
    return true;

}

int main() {
    SqList l;
    int a[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 8};
    initSqList(l, a, 15);
    printf("删除前");
    printSqList(l);
    DeleteSame(l);
    printf("删除后");
    printSqList(l);
}