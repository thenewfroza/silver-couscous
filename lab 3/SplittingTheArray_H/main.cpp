#include <iostream>
#include <vector>
using namespace std;
int max(const int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int sum(const int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}

int searchOfSeparations(const int arr[], int n, int maxLen)
{
    int total = 0, numPainters = 1;
    for (int i = 0; i < n; i++) {
        total += arr[i];
        if (total > maxLen) {

            total = arr[i];
            numPainters++;
        }
    }
    return numPainters;
}

int minMax(int arr[], int n, int k)
{
    int lo = max(arr, n);
    int hi = sum(arr, n);

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int requiredSeparations = searchOfSeparations(arr, n, mid);

        if (requiredSeparations <= k)
            hi = mid;

        else
            lo = mid + 1;
    }
    return lo;
}

int partitions(int lo, int maxLen, const int arr[])
{
    int i = 0;
    int total1 = 0, total2 = 0;
    int it1 = 0, it2 = 0;
    while (total2 < maxLen) {
        total1 = total2;
        it1 = it2;
        it2 = i;
        total2 += arr[lo + i];
        i++;
    }
    if (abs(total1 - maxLen) < abs(total2 - maxLen))
        return lo + it1;
    else
        return lo + it2;
}

void numberOfSeparations(int arr[], int n, int k)
{
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    int maxLen = minMax(arr,n,k) - 1;
    k--;
    int lo = 0;
    while (k > 0){
        k--;
        lo = partitions(lo,maxLen,arr) + 1;
        cout << lo << ' ';
    }
}

int main()
{
    int n ;
    int k ;
    cin >> n >> k;
    int arr[200001];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if (n == k){
        for (int i = 1;i < n; i++)
            cout << i << ' ';
    }
    else
        numberOfSeparations(arr, n, k);
    return 0;
}
