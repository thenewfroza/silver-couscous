#include<iostream>
#include<vector>
int main() {
    int l, r;
    bool f = false;
    int n, m;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> m;
    std::vector<int> arr1(m);
    for (int i = 0; i < m; i++) {
        std::cin >> arr1[i];
    }

    int mid;

    for (int i = 0; i < m; i++) {
        l = 0;
        r = n - 1;
        f = false;
        while (l <= r && f == false) {
            mid = (l + r) / 2;
            if (arr[mid] == arr1[i] && (mid == 0 || arr[mid - 1] < arr[mid]))
                f = true;
            else
                    if (arr[mid] >= arr1[i])
                r = mid -1;
            else
                l = mid + 1;
        }
        if (f == true)
            std::cout << mid + 1 << ' ';
        else {
            std::cout << -1 << ' ' << -1 << '\n';
            continue;
        }


        l = mid;
        r = n - 1;
        f = false;
        while (l <= r && f == false) {
            mid = (l + r) / 2;
            if (arr[mid] == arr1[i] && (mid == n-1 || arr[mid + 1] > arr[mid]))
                f = true;
            else
                    if (arr[mid] == arr1[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
        std::cout << mid + 1 << '\n';
    }
    return 0;
}