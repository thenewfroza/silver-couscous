#include <iostream>
#include <string>
#include <algorithm>
int main(){
    int n, m;
    std::cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++){
        std::string x;
        std::cin >> x;
        for (int j = 0; j < m; j++){
            arr[i][j] = x[j] - '0';
        }
    }
    int dArr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            dArr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        if (arr[i][0] == 1)
            dArr[i][0] = 0;
        else
            dArr[i][0] = 1;

        if (arr[i][m-1] == 1)
            dArr[i][m-1] = 0;
        else
            dArr[i][m-1] = 1;
    }
    for (int i = 0; i < m; i++){
        if (arr[0][i] == 1)
            dArr[0][i] = 0;
        else
            dArr[0][i] = 1;

        if (arr[n-1][i] == 1)
            dArr[n-1][i] = 0;
        else
            dArr[n-1][i] = 1;
    }
    for (int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--) {
            if (arr[i][j] == 1) {
                dArr[i][j] = 0;
            } else {
                if (i < (n - 1) && j < (m - 1)) {
                    int min = std::min(dArr[i][j + 1], dArr[i + 1][j]);
                    min = std::min(dArr[i + 1][j + 1], min);
                    dArr[i][j] = (1 + min);
                } else
                    dArr[i][j] = 1;
            }
        }
    }
    int Max = 0;
    int ix, jx;
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            std::cout << arr[i][j] << ' ';
//        }
//        std::cout << '\n';
//    }
//    std::cout << '\n';
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            std::cout << dArr[i][j] << ' ';
//        }
//        std::cout << '\n';
//    }
//    std::cout << '\n';
    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--) {
                if (dArr[i][j] > Max){
                    Max = dArr[i][j];
                    ix = i;
                    jx = j;
                }
        }
    }
    std::cout << Max << ' ' << ix + 1 << ' ' <<  jx + 1;
    return 0;
}