//
// Created by kzheart on 2022/4/26.
//

#include <cstdio>
#include "Stack.h"

int main() {
    int a;
    scanf("%d", &a);
    int b[a];
}

bool StackEmpty(SqStack stack) {
    return stack.top == -1;
}

void initStack(SqStack &stack) {
    stack.top = -1;
}

bool pop(SqStack &stack, int &x) {
    if (!StackEmpty(stack)) {
        x = stack.data[stack.top--];
        return true;
    } else
        return false;
}


bool push(SqStack &stack, int x) {
    if (!isFull(stack)) {
        stack.data[++stack.top] = x;
        return true;
    } else
        return false;
}

bool isFull(SqStack stack) {
    return stack.top == stack.max;
}

bool getTop(SqStack stack, int &x) {
    if (!StackEmpty(stack)) {
        x = stack.data[stack.top];
        return true;
    } else
        return false;
}


