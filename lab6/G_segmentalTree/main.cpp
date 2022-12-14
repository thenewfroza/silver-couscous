#include <iostream>
#include <cmath>
#include <vector>

struct node {
    int value;
    int left;
    int right;
};
std::vector<node> arr;
void buildSegmentalTree(int N, int n){
    for (int i = 0; i < N; i++){
        arr[n - N + i].value = 0;
        arr[n - N + i].right = i;
        arr[n - N + i].left = i;
    }
    for (int i = n - N - 1; i >= 0; i--){
        arr[i].left = arr [2 * i + 1].left;
        arr[i].right = arr[2 * i + 2].right;
    }
}
void update(int v, int newValue, int l, int r, int index){
  if (l == r){
      arr[v].value += newValue;
      if (arr[v].value <= 0){
          arr[v].value = 0;
      }
  }
  else{
      int mid = (l + r) / 2;
      if (index <= mid){
          update(2*v+1,newValue, l, mid, index);
      }
      else
          update(2*v+2, newValue, mid + 1, r, index);
      arr[v].value = arr[2*v+1].value + arr[2 * v + 2].value;
  }
}

int sum(int v, int left, int right, int l, int r){
    if (l > r)
        return 0;
    if (l == left && r == right){
        return arr[v].value;
    }
    int mid = (left + right) / 2;
    return sum(2*v + 1, left, mid, l, std::min(r,mid)) + sum(2*v+2, mid + 1, right, std::max(l, mid + 1), r);
}

int main() {
    int N, n;
    int Q;
    std::cin >> N >> Q;
    N = pow(2, ceil(log2(N)));
    n = N * 2 - 1;
    arr.resize(n);
    buildSegmentalTree(N,n);
    for (int i = 0; i < Q; i++){
        char x;

        std::cin >> x;
        if (x == '+'){
            int index;
            int newValue;
            std::cin >> index >> newValue;
            update(0,newValue, arr[0].left, arr[0].right, index);
        }
        if (x == '-'){
            int index;
            int newValue;
            std::cin >> index >> newValue;
            newValue = newValue * (-1);
            update(0,newValue, arr[0].left, arr[0].right, index);
        }
        if (x == '?'){
            int l, r;
            std::cin >> l >> r;
            std::cout << sum(0, arr[0].left, arr[0].right, l, r) << '\n';
        }
    }
    return 0;
}
