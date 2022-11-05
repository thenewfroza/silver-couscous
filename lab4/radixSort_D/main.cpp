#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];

    for (int i = 0; i < k; i++) {
        int c[26] = {0};

        for (int j = 0; j < n; j++)
            c[str[j][m - 1 - i] - 97]++;

        for (int j = 1; j < 26; j++)
            c[j] += c[j - 1];

        vector<string> ans(n);

        for (int j = n - 1; j >= 0; j--) {
            int d = str[j][m - 1 - i] - 97;
            ans[c[d] - 1] = str[j];
            c[d]--;
        }
        str = ans;
    }

    for (int i = 0; i < n; i++)
        cout << str[i] << endl;
    return 0;
}