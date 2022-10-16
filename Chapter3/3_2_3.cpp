//
// Created by kzheart on 2022/10/16.
//
#include "stack.h"

typedef struct VirtualQueue {
    SqStack s1;
    SqStack s2;
};

bool Enqueue(VirtualQueue &s, int x) {
    if (!isFull(s.s1)) {
        push(s.s1, x);
        return true;
    }
    //第一个满了 第二个不为空 队满
    if (isFull(s.s1) && !isEmpty(s.s2))
        return false;
    //第一个满了 第二个为空 将第一个所有移入二中 再入栈
    if (isFull(s.s1) && isEmpty(s.s2)) {
        while (!isEmpty(s.s1)) {
            int a;
            pop(s.s1, a);
            push(s.s2, a);
        }
    }
    push(s.s1, x);
    return true;
}


bool DeQueue(VirtualQueue &s, int &x) {
    if (!isEmpty(s.s2)) {
        pop(s.s2, x);
        return true;
    }
    if (isEmpty(s.s1) && isEmpty(s.s2))
        return false;
    //s2是空的 但是s1 不空 将s1的元素全部移入s2再出栈
    if (isEmpty(s.s2) && !isEmpty(s.s1)) {
        while (!isEmpty(s.s1)) {
            int a;
            pop(s.s1, a);
            push(s.s2, a);
        }
    }
    pop(s.s2, x);
    return true;
}

bool isEmpty(VirtualQueue s) {
    return isEmpty(s.s1) && isEmpty(s.s2);
}

int main() {
    VirtualQueue q;
    for (int i = 0; i < 50; i++) {
        Enqueue(q, i);
    }
    while (!isEmpty(q)) {
        int x;
        DeQueue(q, x);
        printf(" %d ", x);
    }
}
