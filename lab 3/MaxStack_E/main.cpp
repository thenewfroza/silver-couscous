#include <iostream>
using namespace std;

struct StackNode {
    int data;
    int currentMax = 0;
    StackNode* link;
    StackNode* prev;
};

StackNode* root = nullptr;
StackNode* start = nullptr;

int isEmpty() {
    return !root;
}

StackNode* top(int data) {
    StackNode* stackNode = new StackNode;
    stackNode->data = data;
    stackNode->prev = stackNode->link;
    stackNode->link = nullptr;
    return stackNode;
}

void push(int new_data) {

    StackNode* stackNode = top(new_data);
    if (isEmpty()){
        stackNode->currentMax = new_data;
        stackNode->prev = nullptr;
        stackNode->link = nullptr;
        start = stackNode;
        root = stackNode;
    }
    else{
        root->link = stackNode;
        stackNode->link = nullptr;
        stackNode->prev = root;
        if (stackNode->prev->currentMax < new_data){
            stackNode->currentMax = new_data;
        }
        else
            stackNode->currentMax = stackNode->prev->currentMax;
        root = stackNode;
    }
}

int MAX(){
    return root->currentMax;
};

void pop() {
    StackNode* temp = root;
    if (root == start) {
        root = nullptr;
        start = nullptr;
        delete(temp);
    }
    else {
        root->prev->link = nullptr;
        root = temp->prev;
        delete(temp);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string sign;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> sign;
        if (sign[0] == '+') {
            cin >> x;
            push(x);
        }
        else if (sign[0] == 'm') {
            cout << MAX() << '\n';
        }
        else if (sign[0] == '-') {
            pop();
        }
    }
    return 0;
}
