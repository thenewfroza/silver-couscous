#include <iostream>
using namespace std;

struct element {
  int x;
  element* next;

  element(int x) : x(x), next(nullptr) {}
};

struct Stack {
  element* first;
  element* top;

  Stack() : first(nullptr), top(nullptr) {}

  bool is_empty() {
    return first == nullptr;
  }

  int pick(){
    return first->x;
  }

  void push(int x) {
    element* p = new element(x);
    if (is_empty()) {
      first = p;
      top = p;
      return;
    }
    top->next = p;
    top = p;
  }
  int pop() {
    element* p = first;
    while (p->next != top) p = p->next;
    int popped = p->x;
    p->next = nullptr;
    delete top;
    top = p;
    return popped;
  }
  void print() {
    if (is_empty()) return;
    element* p = first;
    while (p) {
      cout << p->x << " ";
      p = p->next;
    }
    cout << endl;
  }
};
int main(){

  Stack oo;
  oo.push(10);
  oo.push(100);
  oo.push(101);
  oo.push(19);
  oo.pop
//  int n;
//  cin >> n;
//  char sign;
//  for (int i = 0; i < n; i++){
//    cin >> sign;
//    if (sign == '+'){
//      int x;
//      cin >> x;
//      oo.push(x);
//    }else {
//      cout << oo.pop();
//    }
//  }

  return 0;
}