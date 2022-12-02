#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
struct nodeMas {
    int value, left, right, height;

};
struct node {
    int value, height;
    node *left, *right, *parent;
};

std::vector<nodeMas> tree;

void heightNode(int top) {
    if (tree[top].left != -1)
        heightNode(tree[top].left);
    if (tree[top].right != -1)
        heightNode(tree[top].right);
    if (tree[top].left != -1 || tree[top].right != -1) {
        int l, r;
        tree[top].left == -1 ? l = 0 : l = tree[tree[top].left].height;
        tree[top].right == -1 ? r = 0 : r = tree[tree[top].right].height;
        tree[top].height = std::max(l, r) + 1;
    }
}

void createTree(node *root,int top) {
    root->value = tree[top].value;
    root->height = tree[top].height;
    if (tree[top].left != -1) {
        node *l = new node;
        root->left = l;
        l->parent = root;
        createTree(l, tree[top].left);
    }
    else
        root->left = nullptr;
    if (tree[top].right != -1) {
        node *r = new node;
        root->right = r;
        r->parent = root;
        createTree(r, tree[top].right);
    }
    else
        root->right = nullptr;
}

node *insert(int x, node *root) {
    node *ins = root, *prev = nullptr;
    while (ins != nullptr) {
        if (x > ins->value) {
            prev = ins;
            ins = ins->right;
        }
        else {
            prev = ins;
            ins = ins->left;
        }
    }
    ins = new node;
    ins->value = x;
    ins->left = nullptr;
    ins->right = nullptr;
    ins->height = 1;
    if (prev == nullptr) {
        ins->parent = nullptr;
        root = ins;
    }
    else {
        ins->parent = prev;
        x > prev->value ? prev->right = ins : prev->left = ins;
    }
    return ins;
}

int bFactor(node* root) {
    if (root == nullptr)
        return 0;
    int hl, hr;
    root->left != nullptr ? hl = root->left->height : hl = 0;
    root->right != nullptr ? hr = root->right->height : hr = 0;
    return hr - hl;
}

void fixHeight(node *root) {
    int hl, hr;
    root->left != nullptr ? hl = root->left->height : hl = 0;
    root->right != nullptr ? hr = root->right->height : hr = 0;
    root->height = std::max(hl, hr) + 1;
}

node *smallLeft(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    p->parent = q->parent;
    q->parent = p;
    if(p->parent != nullptr)
        p->parent->right == q ? p->parent->right = p : p->parent->left = p;
    fixHeight(q);
    fixHeight(p);
    return p;
}

node *smallRight(node *p) {
    node *q = p->left;
    p->left = q->right;
    q->right = p;
    q->parent = p->parent;
    p->parent = q;
    if(q->parent != nullptr)
        q->parent->right == p ? q->parent->right = q : q->parent->left = q;
    fixHeight(p);
    fixHeight(q);
    return q;
}

node *balance(node *p) {
    fixHeight(p);
    if (bFactor(p) == 2) {
        if (bFactor(p->right) == -1)
            p->right = smallRight(p->right);
        return smallLeft(p);
    }
    if (bFactor(p) == -2) {
        if (bFactor(p->left) == 1)
            p->left = smallLeft(p->left);
        return smallRight(p);
    }
    return p;
}

void wideTravel(node *root) {
    std::queue <node*> queue;
    int  i = 2, left, right;
    queue.push(root);
    while (!queue.empty()) {
        if (queue.front()->left != nullptr) {
            queue.push(queue.front()->left);
            left = i++;
        }
        else
            left = 0;
        if (queue.front()->right != nullptr) {
            queue.push(queue.front()->right);
            right = i++;
        }
        else
            right = 0;
        std::cout << queue.front()->value << ' ' << left << ' ' << right << '\n';
        queue.pop();
    }

}

int main() {
    int n, ins;
    std::cin >> n;
    if (n == 0) {
        int x;
        std::cin >> x;
        std::cout << 1 << '\n' << x << ' ' << 0 << ' ' << 0;
        exit(0);
    }
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tree[i].value >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
        tree[i].height = 1;
    }
    std::cin >> ins;
    heightNode(0);
    node *root = new node;
    root->parent = nullptr;
    createTree(root, 0);
    tree.clear();
    node *k = insert(ins, root);
    while (k != nullptr) {
        k = balance(k);
        root = k;
        k = k->parent;
    }
    std::cout << n + 1 << '\n';
    wideTravel(root);
    return 0;
}