//
// Created by kzheart on 2022/10/15.
//

#ifndef DATA_STRUCT_QUEUE_H
#define DATA_STRUCT_QUEUE_H
#define MAX_QUEUE 20

#include <cstdio>
#include <cstdlib>

typedef struct SqQueue {
    int front = 0;
    int rear = 0;
    int data[MAX_QUEUE];
};


bool isFull(SqQueue queue) {
    return (queue.rear + 1 % MAX_QUEUE) == queue.front;
}

bool isEmpty(SqQueue queue) {
    return queue.front == queue.rear;
}


bool EnQueue(SqQueue &queue, int x) {
    if (isFull(queue))
        return false;
    queue.data[queue.rear] = x;
    queue.rear = (queue.rear + 1) % MAX_QUEUE;
    return true;
}

bool DeQueue(SqQueue &queue, int &x) {
    if (isEmpty(queue))
        return false;
    x = queue.data[queue.front];
    queue.front = (queue.front + 1) % MAX_QUEUE;
    return true;
}

SqQueue initQueue(int a[], int length) {
    SqQueue sqQueue;
    for (int i = 0; i < length; i++) {
        EnQueue(sqQueue, a[i]);
    }
    return sqQueue;
}

void printQueue(SqQueue sqQueue) {
    printf("\n");
    while (sqQueue.front != sqQueue.rear) {
        printf(" %d ", sqQueue.data[sqQueue.front]);
        sqQueue.front = (sqQueue.front + 1) % MAX_QUEUE;
    }
    printf("\n");
}

#endif //DATA_STRUCT_QUEUE_H
