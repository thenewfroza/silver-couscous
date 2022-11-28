#include<iostream>
#include<vector>

struct node {
    int value, left, right;
};

std::vector <node> tree;

void isTree(int top, int min, int max) {
    if (tree[top].value < max && tree[top].value > min) {
        if(tree[top].left != -1){
            isTree(tree[top].left, min, tree[top].value);
        }
        if (tree[top].right != -1) {
            isTree(tree[top].right, tree[top].value, max);
        }
    }
    else {
        std::cout << "NO";
        exit(0);
    }
}
int main() {
    int n;
    std::cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tree[i].value >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
    }
    if (n != 0)
        isTree(0,INT32_MIN,INT32_MAX);
    std::cout << "YES";
    return 0;
}