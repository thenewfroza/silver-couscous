#include <iostream>

int main() {
    int n=0;
    int a[1001];
    int i;
    int num;
    int please;
    std::cin >> n;
    for (i=0;i<n;i++){
        std::cin>>a[i];
    }
    std::cin>> num;
    std::cin>> please;
    for (i=n;i>=please;i--) {
       a[i]=a[i-1];
    }
    a[please-1]=num;
    for (i=0;i<n+1;i++){
        std::cout << a[i] << ' ';
    }
    return 0;
}
