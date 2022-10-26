#include <iostream>

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int mass[n];
    int x, idx, result;
    for (int i=0;i<n;++i){
        scanf("%d", &mass[i]);
    }
    cin >> x;
    idx=mass[0];
    result= abs(x-mass[0]);
    for (int i=1;i<n;++i){
        if (abs(x-mass[i])<result){
            result= abs(x-mass[i]);
            idx=mass[i];
        }
    }
    printf("%d", idx);
    return 0;
}
