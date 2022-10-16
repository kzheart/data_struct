//
// Created by kzheart on 2022/10/15.
//
#define MAX_STACK 20

#include <cstdlib>
#include <cstdio>

typedef struct CycleQueue {
    int data[20];
    int front = 0;
    int rear = 0;
    int tag = 0;//0代表空，1代表满
};

/**
 * 入队
 */
bool EnQueue(CycleQueue &q, int x) {
    if (q.front == q.rear && q.tag) {
        printf("队满不能入队");
        return false;
    }
    q.data[q.rear] = x;
    q.rear = (q.rear + 1) % MAX_STACK;
    if (q.rear == q.front) {
        q.tag = 1;
    }
    return true;
}

/**
 * 出队
 */
bool DeQueue(CycleQueue &q, int &x) {
    if (q.front == q.rear && !q.tag) {
        printf("队空不能出队");
        return false;
    }
    x = q.data[q.front];
    q.front = (q.front + 1) % MAX_STACK;
    if (q.rear == q.front) {
        q.tag = 0;
    }
    return true;
}

int main() {
    CycleQueue q;
    for (int i = 0; i < MAX_STACK + 1; i++) {
        EnQueue(q, i);
    }
    for (int i = 0; i < MAX_STACK + 1; i++) {
        int x = 0;
        DeQueue(q, x);
        printf(" %d ", x);
    }

}