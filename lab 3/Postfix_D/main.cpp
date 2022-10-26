#include <iostream>
using namespace std;

struct StackNode {
    int data;
    StackNode* link;
};

StackNode* top(int data) {
    StackNode* stackNode = new StackNode;
    stackNode->data = data;
    stackNode->link = NULL;
    return stackNode;
}

void push(StackNode** root, int new_data) {
    StackNode* stackNode = top(new_data);
    stackNode->link = *root;
    *root = stackNode;
}

int pop(StackNode** root) {
    StackNode* temp = *root;
    *root = (*root)->link;
    int popped = temp->data;
    delete(temp);
    return popped;
}

int isEmpty(StackNode *root) {
    return !root;
}

int peek(StackNode* root)
{
    if (isEmpty(root))
        return -1;
    return root->data;
}
int main() {
    StackNode* root = nullptr;
    string string1;
    getline(cin,string1);
    for (int i = 0; i < string1.size(); i++) {
        if (isdigit(string1[i])) {
            push(&root,string1[i]-'0');
        }
        else{
            if (string1[i] == '*') {
                int a = pop(&root);
                int b = pop(&root);
                push(&root, (a * b));
            }
            if (string1[i] == '+') {
                int b = pop(&root);
                int a = pop(&root);
                push(&root, (a + b));
            }
            if (string1[i] == '-') {
                int b = pop(&root);
                int a = pop(&root);
                push(&root, (a - b));
            }
        }
    }
    cout << peek(root);
    return 0;
}

