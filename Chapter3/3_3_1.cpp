//
// Created by kzheart on 2022/10/16.
//

#include "stack.h"
#include <cstring>

bool isMatch(char a[]) {
    int length = strlen(a);
    SqStack s = initSqStack(a, length);
    for (int i = 0; i < length; i++) {
        if (a[i] == '{' || a[i] == '[' || a[i] == '(') {
            push(s, a[i]);
        } else {
            int x;
            pop(s, x);
            if ((x == '(' && a[i] != ')') || (x == '{' && a[i] != '}') || (x == '[' && a[i] != ']'))
                return false;
        }
    }
    return true;
}


int main() {
    printf("(()) %d \n", isMatch("(())"));
    printf("{([])} %d \n", isMatch("{([])}"));
    printf("{(]} %d \n", isMatch("{(]}"));
    printf("([]){}{()}[] %d \n", isMatch("([]){}{()}[]"));
}