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
typedef struct SingleNode{
    int data;
    struct SingleNode* next;
}SingleNode,*SingleList;

void InitList(SingleList &list);
int Length(SingleList list);
int LocateElem(SingleList list);
int GetElem(SingleList list);
void ListInsert(SingleList list,int index,int value);
void ListDelete(SingleList list,int index,int result);
void PrintList(SingleList list);
void Empty(SingleList list);
void DestoryList(SingleList list);
#endif /* SingleList_h */
