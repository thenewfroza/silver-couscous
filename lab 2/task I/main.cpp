#include <iostream>
#include <vector>
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    for (int j=l;j<=r-1;j++){
        if (arr[j]<pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[i + 1],arr[r]);
    return (i + 1);
}
void quickSort( int arr[], int l, int r)
{
    if (l<r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi + 1, r);
    }
}
int main() {
    int n;
    std::cin >> n;
    int arr[100000];
    for(int i=0;i<n;i++) {
        std::cin >> arr[i];
    }
    for (int i;i<n;i++){
        std::cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for (int i;i<n;i++){
        std::cout << arr[i] << ' ';
    }
    return 0;
}
