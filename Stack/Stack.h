//
// Created by kzheart on 2022/4/26.
//

#ifndef DATA_STRUCT_STACK_H
#define DATA_STRUCT_STACK_H
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int top;
    int max = MaxSize;
} SqStack;

void initStack(SqStack &stack);

bool StackEmpty(SqStack stack);


bool push(SqStack &stack, int x);

bool pop(SqStack &stack, int &x);

bool isFull(SqStack stack);

bool getTop(SqStack stack, int &x);

#endif //DATA_STRUCT_STACK_H
