//
//  SingleList.h
//  linear-table
//  单链表
//
//  Created by kzheart on 2022/7/13.
//

#ifndef SingleList_h
#define SingleList_h

#include <stdio.h>

typedef struct SingleNode {
    int data;
    struct SingleNode *next;
} SingleNode, *SingleList;

void InitList(SingleList &list);

int Length(SingleList list);

/**
 *
 * @param list
 * @param index
 * @return 返回对应元素位置的索引
 */
int LocateElem(SingleList list, int target);

/**
 *
 * @param list
 * @param index
 * @return 获取某个位置的元素
 *
 */

SingleNode *GetElem(SingleList list, int index);

/**
 * 向某个位置插入一个节点
 * @param list
 * @param index
 * @param value
 */

void ListInsert(SingleList list, int index, int value);

void ListDelete(SingleList list, int index, int result);

void PrintList(SingleList list);

void Empty(SingleList list);

void DestoryList(SingleList list);

#endif /* SingleList_h */
