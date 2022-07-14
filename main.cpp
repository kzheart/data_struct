#include <iostream>

bool equal(int a, int b) {
    return a == b;
}

bool gh(int a, int b) {
    return a > b;
}

bool less(int a, int b) {
    return a < b;
}

bool test(int a, int b, bool (*fcptr)(int, int)) {
    return fcptr(a, b);
}

int main() {
    std::cout << test(1, 2, &equal) << std::endl;
    return 0;
}

