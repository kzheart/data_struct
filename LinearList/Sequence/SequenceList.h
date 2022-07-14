//
//顺序表

#ifndef SequenceTable_h
#define SequenceTable_h
#define MAX_LENGTH 100
#define INIT_SIZE 100

#include <stdio.h>

typedef struct SequenceList{
    int data[MAX_LENGTH];
    int length;
}SequcenList;
//初始化顺序表
void InitList(SequenceList &list);
//获取顺序表长度
int Length(SequenceList list);
//获取某个元素的位置 若不存在返回-1
int LocateElem(SequenceList list,int taget);
//获取某个位置的元素 不存在会返回NULL
int GetElem(SequenceList list,int index);
//在某个位置插入一个元素
bool ListInsert(SequenceList &list,int index,int value);
//删除某个元素
bool ListDelete(SequenceList &list,int index,int &result);
//打印所有元素
void PrintList(SequenceList list);
//判断是否为空
bool Empty(SequenceList list);
//释放整个顺序表
void DestoryList(SequenceList list);


#endif
