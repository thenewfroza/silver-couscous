#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
void merge(std::vector <long long>& a, int left, int medium, int right);
void mergesort(std::vector <long long>& a, int left, int right){
    if (left < right) {
        int medium = (left + right) / 2;
        mergesort(a, left, medium);
        mergesort(a, medium + 1, right);
        merge(a, left, medium, right);
    }
}

void merge(std::vector <long long>& a, int left, int medium, int right) {
    int sizeL = medium - left + 1, sizeR = right - medium;
    std::vector <long long> L(sizeL);
    std::vector <long long> R(sizeR);
    for (int i = 0; i < sizeL; i++)
        L[i] = a[i + left];
    for (int i = 0; i < sizeR; i++)
        R[i] = a[medium+1 + i];
    int i = 0, j = 0;
    for(int currentIndex = left; currentIndex <= right; ++currentIndex)
        if (i < sizeL && j < sizeR)
            if (L[i] < R[j]) {
                a[currentIndex] = L[i];
                i++;
            }
            else {
                a[currentIndex] = R[j];
                j++;
            }
        else {
            if (i < sizeL) {
                a[currentIndex] = L[i];
                i++;
            }
            else
            if (j < sizeR) {
                a[currentIndex] = R[j];
                j++;
            }
        }

}

int main() {

    int n;
    std::cin >> n;
    std::vector <long long> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    return 0;
}