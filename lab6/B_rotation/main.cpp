#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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
void smallLeft(int top) {
    node q = tree[top], p = tree[q.right];
    int c = q.right;
    q.right = p.left;
    p.left = top;
    tree[top] = q;
    tree[c] = p;
    std::swap(tree[top], tree[c]);
    tree[top].left = c;
}
void smallRight(int top) {
    node q = tree[top], p = tree[q.left];
    int c = q.left;
    tree[0].right = q.left;
    q.left = p.right;
    p.right = top;
    tree[top] = q;
    tree[c] = p;
    tree[0].right = c;
}
void wideTravel() {
    std::queue <node> queue;
    int root = 0, i = 2;
    queue.push(tree[root]);
    while (!queue.empty()) {
        if (queue.front().left != -1) {
            queue.push(tree[queue.front().left]);
            queue.front().left = i++;
        }
        else
            queue.front().left = 0;
        if (queue.front().right != -1) {
            queue.push(tree[queue.front().right]);
            queue.front().right = i++;
        }
        else
            queue.front().right = 0;
        std::cout << queue.front().value << ' ' << queue.front().left << ' ' << queue.front().right << '\n';
        queue.pop();
    }

}
int main() {
    int n;
    std::cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tree[i].value >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
        tree[i].height = 1;
    }
    heightNode(0);
    node b = tree[tree[0].right];
    if (b.balance == -1)
        smallRight(tree[0].right);
    smallLeft(0);
    std::cout << n << '\n';
    wideTravel();
    return 0;
}