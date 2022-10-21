//
// Created by kzheart on 2022/10/17.
//
#include "tree.h"

void visit(BiNode *biNode) {
    printf(" %d ", biNode->data);
}

/**
 * 非递归后序遍历
 * 算法思想(照抄王道):沿着根的左孩子，依次入栈,直到左子树为空，读取栈顶元素， 若右孩子不空且未被访问过，将右子树接着按上述步骤入栈左子树，否则栈顶元素出栈并且访问
 */
void traverse(BiTree biTree) {
    BiTreeSqStack s;
    BiNode *p = biTree;
    BiNode *r = NULL;
    while (p || !isEmpty(s)) {
        //左孩子一直有结点 一直遍历左孩子
        if (p) {
            push(s, p);
            p = p->lchild;
        } else {
            //没有左孩子了，此时获取栈顶元素
            getTop(s, p);
            //判断栈顶元素是否有右孩子 有的话转方向
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
                //没有左孩子就可以此时弹出访问
            } else {
                pop(s, p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }

}


int main() {
    BiTree biTree;
    int a[] = {1, 2, 3, 4, 5, 6};
    buildTree(biTree, a, 6);
    printf("非递归后序遍历:");
    traverse(biTree);
    printf("\n");
    printf("递归后序遍历:");
    postVisit(biTree, visit);
}