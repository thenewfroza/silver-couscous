#include<iostream>
#include<string>
using namespace std;
void siftDown(pair <int, int> a[], int heapSize) {
    int i = 0;
    while (2 * i + 1 < heapSize) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min = l;
        if (r < heapSize && a[r].first < a[l].first)
            min = r;
        if (a[i].first <= a[min].first)
            break;
        else {
            swap(a[i], a[min]);
            i = min;
        }
    }

}
void siftUp(pair <int, int> a[], int x) {
    while (x > 0 && a[x].first < a[(x - 1) / 2].first) {
        swap(a[x], a[(x - 1) / 2]);
        x = (x - 1) / 2;
    }
}
int main() {
    pair <int, int> a[100000];
    string str;
    int heapSize = 0, i = 0;
    while (cin >> str) {
        i++;
        if (str == "push") {
            int x;
            cin >> x;
            a[heapSize].first = x;
            a[heapSize++].second = i;
            siftUp(a,heapSize - 1);
        }
        if (str == "extract-min") {
            if (heapSize == 0)
                cout << '*' << '\n';
            else {
                cout << a[0].first << '\n';
                swap(a[0], a[--heapSize]);
                siftDown(a, heapSize);
            }
        }
        if (str == "decrease-key") {
            int x, y , j;
            cin >> x >> y;
            for (j = 0; j < heapSize; j++) {
                if (a[j].second == x) {
                    a[j].first = y;
                    break;
                }
            }
            siftUp(a,j);
        }
    }
    return 0;
}