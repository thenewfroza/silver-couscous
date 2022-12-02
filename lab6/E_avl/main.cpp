#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int value, height;
    node *left, *right, *parent;
};

class avlTree {
public:
    node * root;
    avlTree() :root(nullptr) {};

    void insert(int x) {
        node *ins = root, *prev = nullptr;
        while (ins != nullptr) {
            if (ins->value == x)
                return;
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

        if (prev == nullptr) {
            ins->parent = nullptr;
            root = ins;
        }
        else {
            ins->parent = prev;
            x > prev->value ? prev->right = ins : prev->left = ins;
        }
        balanceTree(ins);
    }

    node* exist(int x) const {
        node *t = root;
        while (t != nullptr) {
            if (x == t->value) {
                return t;
            }
            if (x > t->value)
                t = t->right;
            else
                t = t->left;
        }
        return nullptr;
    }

    void del(int x) {
        node *t = exist(x), *res = nullptr;
        if (t == nullptr)
            return;

        if (t->left == nullptr && t->right == nullptr) {
            if (t->parent == nullptr) {
                root = nullptr;
                delete t;
                return;
            }
            if (t->parent->left == t) {
                res = t->parent;
                t->parent->left = nullptr;
            }
            if (t->parent->right == t) {
                res = t->parent;
                t->parent->right = nullptr;
            }
            delete t;
            balanceTree(res);
            return;
        }

        if (t->left == nullptr || t->right == nullptr) {
            if (t->left == nullptr) {
                res = t->right;
                if (t->parent == nullptr) {
                    t->right->parent = nullptr;
                    root = t->right;
                    delete t;
                    balanceTree(res);
                    return;
                }
                if (t->parent->left == t)
                    t->parent->left = t->right;
                else
                    t->parent->right = t->right;
                t->right->parent = t->parent;
                delete t;
                balanceTree(res);
                return;
            }
            if (t->right == nullptr) {
                res = t->left;
                if (t->parent == nullptr) {
                    t->left->parent = nullptr;
                    root = t->left;
                    delete t;
                    balanceTree(res);
                    return;
                }
                if (t->parent->left == t)
                    t->parent->left = t->left;
                else
                    t->parent->right = t->left;
                t->left->parent = t->parent;
                delete t;
                balanceTree(res);
                return;
            }
        }

        node *prevElem = prev(t);
        prevElem->left ? res = prevElem->left : res = prevElem->parent;
        t->value = prevElem->value;
        if (prevElem->parent->right == prevElem) {
            prevElem->parent->right = prevElem->left;
            if (prevElem->left != nullptr)
                prevElem->left->parent = prevElem->parent;
        }
        else {
            prevElem->parent->left = prevElem->left;
            if (prevElem->left != nullptr)
                prevElem->left->parent = prevElem->parent;
        }
        delete prevElem;
        balanceTree(res);
        return;
   }

    static int bFactor(node* root) {
        if (root == nullptr)
            return 0;
        int hl, hr;
        root->left != nullptr ? hl =  root->left->height : hl = 0;
        root->right != nullptr ? hr = root->right->height : hr = 0;
        return (hr - hl);
    }
private:
    static int fixHeight(node *root) {
        int hl, hr;
        root->left != nullptr ? hl = root->left->height : hl = 0;
        root->right != nullptr ? hr = root->right->height : hr = 0;
        root->height = max(hl, hr) + 1;
        return root->height;
    }

    node *smallLeft(node* q) {
        node* p = q->right;
        q->right = p->left;
        p->left = q;
        p->parent = q->parent;
        q->parent = p;
        if (p->parent)
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
        if (q->parent)
            q->parent->right == p ? q->parent->right = q : q->parent->left = q;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    static node *prev(node *t) {
        t = t->left;
        while (t->right != nullptr)
            t = t->right;
        return t;
    }

    node *balance(node *p) {
        fixHeight(p);
        if (bFactor(p) == 2) {
            if (bFactor(p->right) < 0)
                p->right = smallRight(p->right);
            return smallLeft(p);
        }
        if (bFactor(p) == -2) {
            if (bFactor(p->left) > 0)
                p->left = smallLeft(p->left);
            return smallRight(p);
        }
        return p;
    }

    void balanceTree(node *k){
        while (k != nullptr) {
            k = balance(k);
            root = k;
            k = k->parent;
        }
    }
};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    avlTree a;
    int n;
    char command;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> command >> x;
        if (command == 'A') {
            a.insert(x);
            std::cout << avlTree::bFactor(a.root) << '\n';
        }
        if (command == 'D') {
            a.del(x);
            std::cout << avlTree::bFactor(a.root) << '\n';
        }
        if (command == 'C') {
            a.exist(x) ? std::cout << "Y\n" : std::cout << "N\n";
        }
    }
    return 0;
}
