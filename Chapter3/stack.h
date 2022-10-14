//
// Created by kzheart on 2022/10/14.
//

#ifndef DATA_STRUCT_STACK_H
#define DATA_STRUCT_STACK_H

#include <cstdio>
#include <cstdlib>

#define MAX 50

typedef struct {
    int top = -1;
    int data[MAX];
} SqStack;

bool push(SqStack &s, int x) {
    if (s.top < MAX - 1) {
        s.data[++s.top] = x;
        return true;
    } else
        return false;
}

bool pop(SqStack &s, int &x) {
    if (s.top <= -1)
        return false;
    else {
        x = s.data[s.top--];
        return true;
    }
}

bool getTop(SqStack s, int &x) {
    if (s.top <= -1)
        return false;
    else {
        x = s.data[s.top];
        return true;
    }
}

SqStack initSqStack(int a[], int length) {
    SqStack s;
    for (int i = 0; i < length; i++) {
        push(s, a[i]);
    }
    return s;
}

#endif //DATA_STRUCT_STACK_H
