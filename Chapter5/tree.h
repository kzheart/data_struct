//
// Created by kzheart on 2022/10/17.
//

#ifndef DATA_STRUCT_TREE_H
#define DATA_STRUCT_TREE_H
#define MAX_TREE_QUEUE 50
#define MAX_TREE_STACK 50


#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef struct BiNode {
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode, *BiTree;
typedef struct BiTreeSqQueue {
    int front = 0;
    int rear = 0;
    BiNode *data[MAX_TREE_QUEUE];
};

bool isFull(BiTreeSqQueue queue) {
    return (queue.rear + 1 % MAX_TREE_QUEUE) == queue.front;
}

bool isEmpty(BiTreeSqQueue queue) {
    return queue.front == queue.rear;
}


bool EnQueue(BiTreeSqQueue &queue, BiNode *x) {
    if (isFull(queue))
        return false;
    queue.data[queue.rear] = x;
    queue.rear = (queue.rear + 1) % MAX_TREE_QUEUE;
    return true;
}

bool DeQueue(BiTreeSqQueue &queue, BiNode *&x) {
    if (isEmpty(queue))
        return false;
    x = queue.data[queue.front];
    queue.front = (queue.front + 1) % MAX_TREE_QUEUE;
    return true;
}


typedef struct {
    int top = -1;
    BiNode *data[MAX_TREE_QUEUE];
} BiTreeSqStack;

bool isEmpty(BiTreeSqStack s) {
    return s.top <= -1;
}

bool isFull(BiTreeSqStack s) {
    return s.top >= MAX_TREE_STACK - 1;
}

bool push(BiTreeSqStack &s, BiNode *x) {
    if (s.top < MAX_TREE_STACK - 1) {
        s.data[++s.top] = x;
        return true;
    } else
        return false;
}

bool pop(BiTreeSqStack &s, BiNode *&x) {
    if (s.top <= -1)
        return false;
    else {
        x = s.data[s.top--];
        return true;
    }
}

bool getTop(BiTreeSqStack s, BiNode *&x) {
    if (s.top <= -1)
        return false;
    else {
        x = s.data[s.top];
        return true;
    }
}


/**
 * 层次建立一个二叉树
 */
void buildTree(BiTree &biTree, int a[], int length) {
    int n = 0;
    BiTreeSqQueue queue;
    biTree = (BiTree) malloc(sizeof(BiNode));
    biTree->data = a[n++];
    EnQueue(queue, biTree);
    while (n != length) {
        BiNode *p;
        DeQueue(queue, p);
        p->lchild = (BiNode *) malloc(sizeof(BiNode));
        p->lchild->data = a[n];
        EnQueue(queue, p->lchild);
        if (n == length - 1)
            break;
        n++;
        p->rchild = (BiNode *) malloc(sizeof(BiNode));
        p->rchild->data = a[n];
        EnQueue(queue, p->rchild);
        n++;
    }
}

/**
 * 后序遍历
 */
void postVisit(BiTree biTree, void(*visit)(BiNode *)) {
    if (biTree != NULL) {
        postVisit(biTree->lchild, visit);
        postVisit(biTree->rchild, visit);
        visit(biTree);
    }
}

/**
 * 前序遍历
 */
void preVisit(BiTree biTree, void(*visit)(BiNode *)) {
    if (biTree != NULL) {
        visit(biTree);
        postVisit(biTree->lchild, visit);
        postVisit(biTree->rchild, visit);
    }
}

/**
 * 中序遍历
 */
void midVisit(BiTree biTree, void(*visit)(BiNode *)) {
    if (biTree != NULL) {
        postVisit(biTree->lchild, visit);
        visit(biTree);
        postVisit(biTree->rchild, visit);
    }
}

/**
 * 层次遍历
 */
void levelVisit(BiTree biTree, void(*visit)(BiNode *)) {
    BiTreeSqQueue q;
    BiNode *p = biTree;
    EnQueue(q, p);
    while (!isEmpty(q)) {
        DeQueue(q, p);
        if (p->lchild != NULL) {
            EnQueue(q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(q, p->rchild);
        }
        visit(p);
    }
}

//输出二叉树的树型图(逆时针旋转90度)
void printBiTree(BiTree T, int n) {
    int i;
    char ch = ' ';
    if (T) {
        printBiTree(T->rchild, n + 1);
        for (i = 1; i <= n; i++) printf("%5c", ch);
        std::cout << T->data << std::endl;
        printBiTree(T->lchild, n + 1);
    }
}// PrintBiTree

#endif //DATA_STRUCT_TREE_H
