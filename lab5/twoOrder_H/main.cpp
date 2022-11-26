#include<iostream>
#include<string>



class bst {
    int value;
    bst *left, *right;

public:
    bst();
    bst(int);
    bst *insert(bst *, int);
    void printPostorder(bst*);
};
bst ::bst()
        : value(0)
        , left(nullptr)
        , right(nullptr)
{
}

bst ::bst(int data) {
        value = data;
        left = right = nullptr;
}
bst* bst::insert(bst* root,int data) {
        if (!root)
            return new bst(data);
        if (data > root->value)
            root->right = insert(root->right, data);
        else if (data < root->value)
            root->left = insert(root->left, data);
        return root;
    }

    void bst ::printPostorder(bst* root){
        if (!root){
            return ;
        }
        printPostorder(root->left);
        printPostorder(root->right);
        std::cout << root->value << " ";
    }


int main() {
    std::string str;
    bst a, *root = nullptr;
    int n;
    int x;
    std::cin >> n;
    std::cin >> x;
    root = a.insert(root,x);
    for (int i = 0;i < n; i++){
        std::cin >> x;
        a.insert(root, x);
    }
    a.printPostorder(root);
    return 0;
}