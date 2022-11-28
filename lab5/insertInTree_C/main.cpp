#include<iostream>
#include<vector>

struct node {
    int value, left, right;
};

std::vector <node> tree;
int k = 1;

void enter(int top) {
   if (tree[top].left != -1) {
       enter(tree[top].left);
   }
   if (tree[top].left == -1){
       if (tree[top].right == -1){
           if (tree[top].value == 0){

           }
       }
       tree[top].value = k;
       k++;
   } else {
       if (tree[top].value == 0){
           tree[top].value = k;
           k++;
       }
   }
   if (tree[top].right != -1) {
       enter(tree[top].right);
   }
}

int main() {
    int n;
    std::cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
    }
    enter(0);
    for (int i = 0; i < n; i++){
        std::cout << tree[i].value << ' ';
    }

    return 0;
}