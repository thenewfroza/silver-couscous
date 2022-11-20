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

int peek(StackNode* root)
{
  return root->data;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  StackNode* root = NULL;
  int n;
  cin >> n;
  char sign;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> sign;
    if (sign == '+') {
      cin >> x;
      push(&root,x);
    }
    else {
     cout << pop(&root) << "\n";
    }
  }
  cout << peek(root);
  return 0;
}