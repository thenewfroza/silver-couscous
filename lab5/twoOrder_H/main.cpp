#include<iostream>
#include<string>
#include <vector>


void reverePostOrder(std::vector<int> &arr, int &iter, int min, int max){
    if (!(arr[iter] < min) && !(arr[iter] > max) and iter != arr.size()){
        int temp = arr[iter++];
        reverePostOrder(arr, iter, min, temp);
        reverePostOrder(arr, iter, temp, max);
        std::cout << temp << ' ';
    }
}

int main() {
    std::vector<int> arr;
    int n;
    std::cin >> n;
    arr.resize(n);
    for (int i = 0;i < n; i++){
        std::cin >> arr[i];
    }
    int iter = 0;
    reverePostOrder(arr,iter, INT32_MIN, INT32_MAX);
    return 0;
}