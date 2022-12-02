#include<iostream>
#include<string>
#include <vector>

struct node {
    std::string value;
    node *left, *right, *parent;
};

class bst {
public:
    node * root;
    bst() :root(nullptr) {}

    void insert(std::string x) {
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

    node* exist(std::string x) const {
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


};

int main() {
    std::string str;
    bst a;
    bst b;
    bst c;
    int n;
    int ballOfFirst = 0;
    int ballOfSecond = 0;
    int ballOfThird = 0;
    std::vector<std::string> first;
    std::vector<std::string> second;
    std::vector<std::string> third;
    std::string toInsert;
    std::string toFind;
    std::cin >> n;
    first.resize(n);
    second.resize(n);
    third.resize(n);
    for (int i = 0; i < n; i++){
        std::cin >> first[i];
        toInsert = first[i];
        a.insert(toInsert);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> toInsert;
        second[i] = toInsert;
        b.insert(toInsert);
    }
    for (int i = 0; i < n; i++){
        std::cin >> toInsert;
        third[i] = toInsert;
        c.insert(toInsert);
    }
    for (int i = 0; i < n; i++){
        toFind = first[i];
        node *temp = b.exist(toFind);
        node *temp1 = c.exist(toFind);
        if (temp != nullptr && temp1 != nullptr) {
            ballOfFirst += 0;
            continue ;
        }
        if (temp != nullptr || temp1 != nullptr) {
            ballOfFirst += 1;
            continue ;
        }
        if (temp == nullptr && temp1 == nullptr) {
            ballOfFirst += 3;
            continue ;
        }
    }
    for (int i = 0; i < n; i++){
        toFind = second[i];
        node *temp = a.exist(toFind);
        node *temp1 = c.exist(toFind);
        if (temp != nullptr && temp1 != nullptr) {
            ballOfSecond += 0;
            continue ;
        }
        if (temp != nullptr || temp1 != nullptr) {
            ballOfSecond += 1;
            continue ;
        }
        if (temp == nullptr && temp1 == nullptr) {
            ballOfSecond += 3;
            continue ;
        }
    }
    for (int i = 0; i < n; i++){
        toFind = third[i];
        node *temp = b.exist(toFind);
        node *temp1 = a.exist(toFind);
        if (temp != nullptr && temp1 != nullptr) {
            ballOfThird += 0;
            continue ;
        }
        if (temp != nullptr || temp1 != nullptr) {
            ballOfThird += 1;
            continue ;
        }
        if (temp == nullptr && temp1 == nullptr) {
            ballOfThird += 3;
            continue ;
        }
    }
    std::cout << ballOfFirst << ' ' << ballOfSecond << ' ' << ballOfThird;
    return 0;
}