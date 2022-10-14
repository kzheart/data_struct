//
// Created by kzheart on 2022/10/13.
//
#include "list.h"

void cycleDelMin(LinkList &l) {
    //每一个轮循环都找到一个最小值然后删除
    while (l->next != l) {
        LinkNode *p = l->next;
        LinkNode *min = l->next;
        LinkNode *pre = l;
        LinkNode *minPre = l;
        while (p != l) {
            if (p->data < min->data) {
                minPre = pre;
                min = p;
            }
            pre = p;
            p = p->next;
        }
        //删除最小结点
        printf("打印最小结点%d, 同时删除 \n", min->data);
        minPre->next = min->next;
        free(min);
    }
    free(l);//释放掉头节点
    l = NULL;//置空避免野指针
}

int main() {
    int a[] = {312, 213, 32, 43, 64532, 4343, 234, 6456324, 423543654, 2332, 21134, 345};
    LinkList al;
    initCycleSingleHead(al, a, 12);
    cycleDelMin(al);
}