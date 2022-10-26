#include <iostream>

int main() {
    int n=0;
    int arr[1000];
    int key;
    std::cin >> n;
    int i;
    int flag;

    for (i=0;i<n;i++){
        std::cin >> arr[i];
    }
    for (int j=1; j<n; j++){
        key=arr[j];
        i=j-1;
        flag=0;
       while (i >= 0 and arr[i]> key)  { // тут >= тк на слайде индексация с 1 и если сделать i>0 не попаду в 0 элемент
           flag=1;
           arr[i+1]=arr[i];
           i=i-1;
           arr[i+1]=key;
           }
       }
        if (flag == 1){
             for (int i = 0; i < n; i++){
               std::cout << arr[i] << " ";
           }
    }

    for (i=0;i<n;i++){
        std::cout << arr[i] << ' ';
    }

    return 0;
}
