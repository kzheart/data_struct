//
// Created by kzheart on 2022/10/15.
//
#define MAX 100
typedef struct {
    int data[MAX];
    int top1 = -1;//第一个栈栈顶
    int top2 = MAX;//第二栈栈顶
} ShareStack;
enum class StackId {
    S1, S2
};


bool push(ShareStack &stack, int x, StackId id) {
    if (stack.top1 + 1 != stack.top2) {
        if (id == StackId::S1) {
            stack.data[++stack.top1] = x;
        } else {
            stack.data[--stack.top2] = x;
        }
        return true;
    } else {
        return false;
    }
}


bool pop(ShareStack &stack, int &x, StackId id) {
    if (id == StackId::S1 && stack.top1 > -1) {
        x = stack.data[stack.top1--];
        return true;
    }
    if (id == StackId::S2 && stack.top2 < 100) {
        x = stack.data[stack.top2++];
        return true;
    }
    return false;
}

//懒得测试了
int main() {
    //skip
}