
//带头节点的单链表

#include "SingleList.h"
#include <stdlib.h>

void InitList(SingleList &list) {
    list = (SingleList) malloc(sizeof(SingleList));
}

int Length(SingleList list) {
    int length = -1;
    while (list != NULL) {
        list = list->next;
        length++;
    }
    return length;
}

int LocateElem(SingleList list, int target) {
    int i = 0;
    while (list->next != NULL) {
        //进入循环后直接跳过了头节点 从第一个头节点后的第一个节点开始遍历
        list = list->next;
        if (list->data == target) {
            return i;
        }
        i++;
    }
    return -1;
}


SingleNode *GetElem(SingleList list, int index) {
    if (index < 0) {
        return NULL;
    }
    int i = 0;
    while (list != NULL) {
        if (i == index) {
            return list;
        }
        list = list->next;
        i++;
    }
    return NULL;
}


void ListInsert(SingleList list, int index, int value) {
    int i = 0;
    while (list->next != NULL) {
        list = list->next;
        //先找到要插入的节点
        if (i == index) {
            SingleNode *singleNode = (SingleNode *) malloc(sizeof(SingleNode));
            //先让新节点连接到list后面那个
            singleNode->next = list->next;
            //再让list连接新节点
            list->next = singleNode;
            list->data = value;
            return;
        }
        i++;
    }
    printf("插入 %d 失败", index);
}





