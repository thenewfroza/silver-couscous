#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> dArr ;
    dArr.resize(m);
    for (int i = 0; i < m; i++){
        dArr[i] = 0;
    }
    int max = 0;
    int ix = 0, jx = 0;
    std::vector<int> current;
    current.resize(m);
    std::vector<int> dPrevious;
    dPrevious.resize(m);
    for (int i = 0; i < m ; i++){
        dPrevious[i] = 0;
    }
    for (int i = 0 ; i < n ; i++){
        std::string x;
        std::cin >> x;
        for(int j = 0; j < m; j++) {
            current[j] = x[j] - '0';
            if (current[j] == 5){
                if ((j - 1) >= 0) {
                    dArr[j] = std::min(std::min(dPrevious[j - 1], dPrevious[j]), dArr[j - 1]) + 1;
                    if (dArr[j] >= max) {
                        ix = i;
                        jx = j;
                    }
                    max = std::max(max, dArr[j]);
                }
                else
                    dArr[j] = 1;
                if (dArr[j] >= max) {
                    ix = i;
                    jx = j;
                }
                max = std::max(max, dArr[j]);
            }
            else {
                dArr[j] = 0;
            }
//            std::cout << dArr[j];
        }
        for (int k = 0; k < m; k++){
            dPrevious[k] = dArr[k];
        }
        for (int k = 0; k < m; k++){
            dArr[k] = 0;
        }
//        std::cout << '\n';
    }

    std::cout << max << ' ' << ix - max + 2 << ' ' << jx - max + 2;
    return 0;
}