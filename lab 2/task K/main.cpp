#include <iostream>
#include <vector>

void quicksort(std::vector<int>& arr, int left, int right, int k) {
  if (left <= right) {
    int i = left;
    int j = right;
    int pivot = arr[k];

    do {
      while (arr[i] < pivot) {
        i++;
      }
      while (arr[j] > pivot) {
        j--;
      }

      if (i <= j) {
        std::swap(arr[i], arr[j]);
        i++;
        j--;
      }
    } while (i <= j);

    if (k <= j) {
      quicksort(arr, left, j, k);
    }
    if (k >= i) {
      quicksort(arr, i, right, k);
    }
  }
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> arr(n);
  int A, B, C;
  std::cin >> A >> B >> C >> arr[0] >> arr[1];

  for (int i = 2; i < n; i++) {
    arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
  }

  quicksort(arr, 0, n-1, k);
  std::cout << arr[k-1];
  return 0;
}