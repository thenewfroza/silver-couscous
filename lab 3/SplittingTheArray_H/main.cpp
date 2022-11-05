#include <iostream>
#include <vector>
using namespace std;


bool check(int mid, int array[], int n, int K)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > mid)
            return false;
        sum += array[i];
        if (sum > mid) {
            count++;
            sum = array[i];
        }
    }
    count++;


    if (count <= K)
        return true;
    return false;
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
int solve(int arr[], int n, int K)
{
    int* max = max_element(arr, arr + n);
    int start = *max;
    int end = 0;

    for (int i = 0; i < n; i++) {
        end += arr[i];
    }
    int answer = 0;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (check(mid, arr, n, K)) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return answer;
}

void numberOfSeparations(int arr[], int n, int k)
{
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    int maxLen = solve(arr,n,k) - 1;
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
