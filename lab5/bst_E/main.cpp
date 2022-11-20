#include<iostream>
#include<string>

struct node {
    int value;
    node *left, *right, *parent;
};

class bst {
public:
    node * root;
    bst() :root(nullptr) {}

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

    node *next(int x) const {
        node *t = nullptr, *ins = root;
        while (ins != nullptr && ins->value != x) {
            if (x >= ins->value) {
                t = ins;
                ins = ins->right;
            }
            else {
                t = ins;
                ins = ins->left;
            }
        }
        if (ins == nullptr) {
            ins = new node;
            ins->parent = t;
            ins->value = x;
            ins->left = nullptr;
            ins->right = nullptr;
            t = ins;
        }
        else
            t = ins;

        if (t->right != nullptr) {
            t = t->right;
            while (t->left != nullptr)
                t = t->left;
            return t;
        }
        else {
            while (t->parent != nullptr) {
                t = t->parent;
                if (t->value > x) {
                    return t;
                }
            }
            return nullptr;
        }
    }

    void prev(int x) const {
        node *t = nullptr, *ins = root;
        while (ins != nullptr && ins->value != x) {
            if (x >= ins->value) {
                t = ins;
                ins = ins->right;
            }
            else {
                t = ins;
                ins = ins->left;
            }
        }
        if (ins == nullptr) {
            ins = new node;
            ins->parent = t;
            ins->value = x;
            ins->left = nullptr;
            ins->right = nullptr;
            t = ins;
        }
        else
            t = ins;

        if (t->left != nullptr) {
            t = t->left;
            while (t->right != nullptr) {
                t = t->right;
            }
            std::cout << t->value << '\n';
            return;
        }
        else {
            while (t->parent != nullptr) {
                t = t->parent;
                if (t->value < x) {
                    std::cout << t->value << '\n';
                    return;
                }
            }
            std::cout << "none\n";
        }
    }

    void del(int x) {
        node *t = exist(x);
        if (t == nullptr)
            return;

        if (t->left == nullptr && t->right == nullptr) {
            if (t->parent == nullptr) {
                root = nullptr;
                delete t;
                return;
            }
            if (t->parent->left == t) {
                t->parent->left = nullptr;
                delete t;
            }
            if (t->parent->right == t) {
                t->parent->right = nullptr;
                delete t;
            }
            return;
        }

        if (t->left == nullptr || t->right == nullptr) {
            if (t->left == nullptr) {
                if (t->parent == nullptr) {
                    t->right->parent = nullptr;
                    root = t->right;
                    delete t;
                    return;
                }
                if (t->parent->left == t)
                    t->parent->left = t->right;
                else
                    t->parent->right = t->right;
                t->right->parent = t->parent;
                delete t;
                return;
            }
            if (t->right == nullptr) {
                if (t->parent == nullptr) {
                    t->left->parent = nullptr;
                    root = t->left;
                    delete t;
                    return;
                }
                if (t->parent->left == t)
                    t->parent->left = t->left;
                else
                    t->parent->right = t->left;
                t->left->parent = t->parent;
                delete t;
                return;
            }
        }

        node *nextElem = next(x);
        t->value = nextElem->value;
        if (nextElem->parent->left == nextElem) {
            nextElem->parent->left = nextElem->right;
            if (nextElem->right != nullptr)
                nextElem->right->parent = nextElem->parent;
        }
        else {
            nextElem->parent->right = nextElem->right;
            if (nextElem->right != nullptr)
                nextElem->right->parent = nextElem->parent;
        }
        delete nextElem;
    }
};

int main() {
    std::string str;
    bst a;
    while (std::cin >> str) {
        int x;
        std::cin >> x;
        if (str == "insert") {
            a.insert(x);
            continue;
        }
        if (str == "delete") {
            a.del(x);
            continue;
        }
        if (str == "exists") {
            node *temp = a.exist(x);
            if (temp != nullptr)
                std::cout << "true\n";
            else
                std::cout << "false\n";
            continue;
        }
        if (str == "next") {
            node *temp = a.next(x);
            if (temp != nullptr)
                std::cout << temp->value << '\n';
            else
                std::cout << "none\n";
        }
        if (str == "prev") {
            a.prev(x);
        }
    }
    return 0;
}