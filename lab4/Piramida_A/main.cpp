#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    n--;
    for (int i = 0; i <= n/2 - 1; i++) {
        if (a[i] > a[2 * i + 1]) {
            cout << "NO";
            exit(0);
        }
        if (a[i] > a[2 * i + 2]) {
            cout << "NO";
            exit(0);
        }

    }
    cout << "YES";
    return 0;
}