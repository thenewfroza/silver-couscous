#include <iostream>

int main(){
    int n, m;
    std::cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            std::cin >> arr[i][j];
        }
    }
    int dArr[n][m];
    for (int i = 0; i < n; i++){
        if (arr[i][0] == 1)
            dArr[i][0] = 0;
        else
            dArr[i][0] = 1;

        if (arr[i][m] == 1)
            dArr[i][m] = 0;
        else
            dArr[i][m] = 1;
    }
    for (int i = 0; i < m; i++){
        if (arr[0][i] == 1)
            dArr[0][i] = 0;
        else
            dArr[0][i] = 1;

        if (arr[n][i] == 1)
            dArr[n][i] = 0;
        else
            dArr[n][i] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            std::cout << dArr[i][j];
        }
    }
}