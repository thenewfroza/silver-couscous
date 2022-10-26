#include <iostream>
using namespace std;

struct StackNode {
    char data;
    StackNode* link;
};

StackNode* top(char data) {
    StackNode* stackNode = new StackNode;
    stackNode->data = data;
    stackNode->link = NULL;
    return stackNode;
}

void push(StackNode** root, char new_data) {
    StackNode* stackNode = top(new_data);
    stackNode->link = *root;
    *root = stackNode;
}


char pop(StackNode** root) {
    StackNode* temp = *root;
    *root = (*root)->link;
    char popped = temp->data;
    delete(temp);
    return popped;
}

int isEmpty(StackNode *root) {
    return !root;
}

char peek(StackNode* root)
{
    if (isEmpty(root))
        return -1;
    return root->data;
}

int main() {
    StackNode* root = NULL;
    string str;
    while(cin >> str) {
        bool F=0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ')' && peek(root) == '(' || str[i] == ']' && peek(root) == '[') {
                pop(&root);
            } else if (str[i] == ')' || str[i] == ']') {
                if (F != 1) {
                    cout << "NO" << '\n';
                }
                F = 1;
                continue ;
            } else
                push(&root, str[i]);
        }
        if (F != 1) {
            if (isEmpty(root))
                cout << "YES" << '\n';
        }
        if (F != 1) {
            if (!isEmpty(root))
                cout << "NO" << '\n';
        }
        while(!isEmpty(root))
            pop(&root);
    }
    return 0;
}