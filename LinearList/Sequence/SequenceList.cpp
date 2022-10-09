//
//  SequenceTable.cpp
//  linear-table
//
//  Created by kzheart on 2022/7/13.
//
#include "SequenceList.h"
#include <stdio.h>
#include <stdlib.h>

void initSequecen(SequenceList &list) {
    for (int i = 0; i < INIT_SIZE; i++) {
        list.data[i] = 0;
    }
}

int Length(SequenceList list) {
    return list.length;
}


int LocateElem(SequenceList list, int target) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == target) {
            return i;
        }
    }
    return -1;
}

int GetElem(SequenceList list, int index) {
    if (index < list.length) {
        return list.data[index];
    }
    printf("未找到索引为的 %d 的元素",index);

    return 9999;
}

bool ListInsert(SequenceList list, int index, int value) {
    //判断索引位置是否小于 0 索引位置是否大于list的长度 list长度是否满了
    if (index > list.length - 1 || index < 0 || list.length >= MAX_LENGTH) {
        return false;
    }
    //让索引后的所有元素后移
    for (int i = list.length - 1; i > index; i--) {
        list.data[i + 1] = list.data[i];
    }
    list.data[index] = value;
    list.length++;
    return true;
}

bool ListDelete(SequenceList &list, int index, int &result) {
    if (index < 0 || index >= list.length) {
        return false;
    }
    //直接将索引后边的元素全部前移并将长度减一即可
    for (int i = index; i > list.length - 1; i++) {
        list.data[index] = list.data[index + 1];
    }
    list.length--;
    return true;
}

void PrintList(SequenceList list) {
    for (int i = 0; i < list.length - 1; i++) {
        printf("index:%d value:%d \n", i, list.data[i]);
    }
}

bool Empty(SequenceList list) {
    return list.length == 0;
}

void DestoryList(SequenceList list) {
    free(list.data);
}
