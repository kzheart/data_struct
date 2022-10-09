//
// Created by kzheart on 2022/7/25.
//
#include <stdio.h>

int search(int a[], int target, int length);

int recursionSearch(int a[], int target, int low, int length);

int main() {
    int a[11] = {7, 10, 13, 16, 19, 29, 32, 33, 37, 41, 43};
    printf("target index:%d", recursionSearch(a, 10, 0, 11));

}

int search(int a[], int target, int length) {
    for (int low = 0, high = length - 1; low <= high;) {
        int mid = (low + high) / 2;
        if (a[mid] == target)
            return mid;
        //此时说明目标元素在左边
        if (a[mid] > target)
            high = mid - 1;
        //此时说明目标元素在右边
        if (a[mid] < target)
            low = mid + 1;
    }
    return -1;
}

int recursionSearch(int a[], int target, int low, int length) {
    int mid = (low + length) / 2;
    if (low > length)
        return -1;
    if (a[mid] == target)
        return mid;
    if (a[mid] > target) {
        return recursionSearch(a, target, low, --mid);
    }
    if (a[mid] < target) {
        return recursionSearch(a, target, ++low, length);
    }
}