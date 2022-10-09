//
// Created by kzheart on 2022/8/1.
//


#include <stdio.h>
#include "Common.h"
#include <time.h>

int partition(int a[], int low, int high);

void insert_sort(int a[], int length);

void bubble_sort(int a[], int length);

void quick_sort(int a[], int low, int high);


void BuildMaxHeap(int a[], int length);

void HeadAdjust(int a[], int k, int length);

void HeapSort(int a[], int length);


void merge(int a[], int low, int mid, int high);

int main() {
//    int a[11] = {0, 38, 65, 97, 76, 13, 27, 49};
//    quick_sort(a, 0, 7);
//    print_array(a, 8);
    int a = 1;
    int b = 2;
    int c = 3;
    if(a==b==c){
            
    }

}


void insert_sort(int a[], int length) {
    int begin = clock();
    for (int i = 0; i < length; ++i) {
        int j = i;//作为循环变量
        int temp = a[i];//临时存储变量
        while (temp < a[j - 1]) {//判断当前元素是否比前一个元素要大
            a[j] = a[j - 1];//大的话则将前面元素移动到后面
            j--;//循环检查变量
        }
        a[j] = temp;//将最后停止位置放入到插入位置
    }
    int end = clock();

    printf("插入排序用时:%d ms \n", end - begin);

}

void bubble_sort(int a[], int length) {
    for (int i = length - 1, count = 0; i > 0; i--, count++) {
        bool flag = false;//记录是否发生交换
        for (int j = length - 1; j > count; j--) {
            if (a[j - 1] > a[j]) {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                flag = true;
            }
        }
        printf("第 %d 轮结束\n", count);
        print_array(a, length);
        if (!flag) {
            break;
        }
    }

}

void quick_sort(int a[], const int low, const int high) {
    if (low < high) {
        int position = partition(a, low, high);
        quick_sort(a, position + 1, high);
        quick_sort(a, low, position - 1);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];//暂存枢轴元素
    while (low < high) {
        while (low < high && a[high] > pivot) high--;//从后面找到小于枢轴的元素
        a[low] = a[high];//将其放到枢轴左边
        while (low < high && a[low] < pivot) low++;//从前面找到大于枢轴的元素
        a[high] = a[low];//将其放到枢轴右边
    }
    a[low] = pivot;//此时low=high 将枢轴元素放置到中间 完成一次划分
    return low;
}


void HeadAdjust(int a[], int k, int length) {
    a[0] = a[k];
    for (int i = k * 2; i <= length; i *= 2) {
        //判断当前结点的左右孩子 如果右孩子更大 则让指针指向右孩子
        if (i < length && a[i + 1] > a[i])
            i++;
        //当该元素比左右元素都大的时候就不用调整 直接退出
        if (a[0] > a[i]) break;
        else {
            a[k] = a[i]; //孩子结点更大，将孩子结点的元素换到父结点
            k = i;//将k置于被交换的孩子结点 继续向下继续筛选
        }
    }
    a[k] = a[0];
}


void BuildMaxHeap(int a[], int length) {
    for (int i = length / 2; i > 0; i--) {
        HeadAdjust(a, i, length);
    }
}

void HeapSort(int a[], int length) {
    BuildMaxHeap(a, length);
    for (int i = length; i > 0; i--) {
        int t = a[i];
        a[i] = a[1];
        a[1] = t;
        a[length] = a[1];
        HeadAdjust(a, 1, i - 1);
    }
}

void merge(int a[], int low, int mid, int high) {
    int b[100];
    int i, j, k;//设置三个指向索引 i用于指向b的前半部分，j用于指向b的后半部分，k的用于向原数组中赋值
    for (k = low; k <= high; k++) {
        b[k] = a[k];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {//当i超出它的mid范围或者k超出high范围 也就是超出他们的数组的时候 循环结束
        if (b[i] <= b[j]) {//前半部分的数值要小于后半部分
            a[k] = b[i++];
        } else {//后半部分要小
            a[k] = b[j++];
        }
    }
    while (i <= mid)a[k++] = b[i++];//此时前半部分有剩余 全部赋给原数组
    while (j <= high)a[k++] = b[j++];//此时后半部分有剩余
}


