//
// Created by kzheart on 2022/10/17.
//
#include "stack.h"
#include "time.h"

/**
 * 递归实现
 * @return
 */
int recursion(int n, int x) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 2 * x;
    if (n >= 2)
        return (2 * x * recursion(n - 1, x)) - (2 * (n - 1) * recursion(n - 2, x));

}

/**
 * 非递归实现
 */
int calc(int n, int x) {
    int *a = NULL;
    SqStack stack = initSqStack(a, 0);
    if (n == 0)
        return 1;
    if (n == 1)
        return 2 * x;
    while (n > 1) {
        push(stack, n--);
    }
    int n_1 = 2 * x;//n-1变量
    int n_2 = 1;//n-2变量
    int result;

    while (!isEmpty(stack)) {
        int nn;
        pop(stack, nn);
        result = (2 * x * n_1) - (2 * (nn - 1) * n_2);
        n_2 = n_1;
        n_1 = result;
    }
    return result;
}

int main() {
    clock_t start1, stop1, start2, stop2;
    long duration1;
    long duration2;
    start1 = clock();

    printf("%d", calc(30, 1));
    stop1 = clock();
    duration1 = (long) ((stop1 - start1));
    printf("\n耗时:%ld", duration1);

    printf("\n");

    start2 = clock();
    printf("%d", recursion(30, 1));
    stop2 = clock();
    duration2 = (long) ((stop2 - start2));
    printf("\n耗时:%ld", duration2);


}