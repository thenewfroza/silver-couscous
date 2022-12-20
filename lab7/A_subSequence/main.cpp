#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr;
    arr.resize(N);
    for (int i = 0; i < arr.size(); i++){
        std::cin >> arr[i];
    }
    int n = arr.size();
    int d[n];
    int prev[n];

    for (int i = 0; i < n; i++) {
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] < arr[i] and d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }
    int pos = 0;
    int length = d[0];
    for (int i = 0; i < n; i++){
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }
    int counter = 0;
    std::vector<int> answer;
    while (pos != -1){
        answer.push_back(arr[pos]);
        pos = prev[pos];
        counter++;
    }
    std::cout << counter << '\n';
    for (int i = counter - 1; i >= 0 ; i--){
        std::cout << answer[i] << ' ';
    }
    return 0;
}
