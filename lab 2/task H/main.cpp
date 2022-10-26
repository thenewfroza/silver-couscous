
#include<iostream>
#include<vector>
#include <algorithm>
struct student {
  int start;
  int end;
};
int partition(student arr[], int low, int high)
{
  int pivot = arr[low].start;
  int i = low - 1, j = high + 1;

  while (true) {

    do {
      i++;
    } while (arr[i].start < pivot);

    do {
      j--;
    } while (arr[j].start > pivot);

    if (i >= j)
      return j;

    std::swap(arr[i], arr[j]);
  }
}
int partition_r(student arr[], int low, int high)
{
  srand(time(nullptr));
  int random = low + rand() % (high - low);

  std::swap(arr[random], arr[low]);

  return partition(arr, low, high);
}
void quickSort(student arr[], int low, int high)
{
  if (low < high) {

    int pi = partition_r(arr, low, high);


    quickSort(arr, low, pi);
    quickSort(arr, pi + 1, high);
  }
}
int main() {
  int n;
  std::cin >> n;
  student  arr[n];
  for (int i=0;i<n;i++){
    std::cin >> arr[i].start >> arr[i].end;
  }
  quickSort(arr,0,n-1);
  //  for (int i=0;i<n;i++){
  //    std::cout << arr[i].start << " " << arr[i].end << "\n";
  //  }
  int l = arr[0].end;
  int sum=arr[0].end - arr[0].start + 1;
  for (int i=1; i < n;i++){
    if (arr[i].end < l);
    else{
      if (arr[i].start > l) {
        sum += arr[i].end - arr[i].start +1;
        l = arr[i].end;
      }
      else {
        sum += arr[i].end - l;
        l = arr[i].end;
      }
    }
  }
  std::cout << sum;
  return 0;
}