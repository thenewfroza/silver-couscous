#include<iostream>
#include<vector>
#include<algorithm>

struct node {
    int value, left, right, height, balance;
};

std::vector<node> tree;

int heightNode(int top) {
    if (tree[top].left != -1)
        heightNode(tree[top].left);
    if (tree[top].right != -1)
        heightNode(tree[top].right);
    if (tree[top].left != -1 || tree[top].right != -1) {
        int l, r;
        tree[top].left == -1 ? l = 0 : l = tree[tree[top].left].height;
        tree[top].right == -1 ? r = 0 : r = tree[tree[top].right].height;
        tree[top].height = std::max(l, r) + 1;
        tree[top].balance = r - l;
    }
    return tree[top].balance;
}

int main() {
    int n;
    std::cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tree[i].value >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
        tree[i].height = 1;
    }
    heightNode(0);
    for (auto &arr: tree) {

        std::cout << arr.balance << '\n';
    }
    return 0;
}