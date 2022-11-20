#include<iostream>
#include<vector>

int max = 0;
int res = 1;

struct node {
    int count, left, right;
};

std::vector <node> tree;

void height(int top) {
    if (res > max)
        max = res;
    if (top >= 0 && tree[top].left != -1) {
        res++;
        if (res > max)
            max = res;
        height(tree[top].left);
    }
    if (top >= 0 && tree[top].right != -1) {
        res++;
        if (res > max)
            max = res;
        height(tree[top].right);
    }
    res--;
}
int main() {

    int n;
    std::cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tree[i].count >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
    }
    if(n != 0)
        height(0);
    std::cout << max;
    return 0;
}