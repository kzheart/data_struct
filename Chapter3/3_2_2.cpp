//
// Created by kzheart on 2022/10/16.
//
#include "queue.h"
#include "stack.h"

void reverse(SqQueue &q, SqStack &s) {
    while (!isEmpty(q)) {
        int x;
        DeQueue(q, x);
        push(s, x);
    }
    while (!isEmpty(s)) {
        int x;
        pop(s, x);
        EnQueue(q, x);
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    SqQueue q = initQueue(a, 6);
    printf("逆置前:");
    printQueue(q);
    SqStack s = initSqStack(NULL, 0);
    reverse(q, s);
    printf("逆置后:");
    printQueue(q);
}