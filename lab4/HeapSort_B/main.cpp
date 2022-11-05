#include<iostream>
#include<vector>
using namespace std;
void siftDown(vector<int> &arr, int i, int heapSize) {
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = left;
        if (right < heapSize && arr[right] > arr[left]) {
            max = right;
        }
        if (arr[i] >= arr[max])
            break;
        else {
            swap(arr[i], arr[max]);
            i = max;
        }
    }
}
void buildHeap(vector<int> &a) {
    for (int i = (a.size() - 1) / 2; i >= 0; i--)
        siftDown(a, i, a.size());
}
int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    buildHeap(arr);
    for (int i = 0; i < n - 1; i++) {
        swap(arr[0], arr[n - 1 - i]);
        siftDown(arr, 0, n - 1 - i);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}