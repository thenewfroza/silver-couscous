#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
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

int count_various_elements(std::vector<long long>& v){
  int count =1;
  for (int i=1;i<v.size();i++){
    if (v[i] !=v[i-1]){
      count++;
    }
  }
  return count;
}

int main() {
  bool F;
  int n;
  std::cin >> n;
  std::vector <long long> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  int m;
  std::cin >> m;
  std::vector <long long> b(m);
  for (int i = 0; i < m; i++)
    std::cin >> b[i];
  mergesort(a, 0, n - 1);

  // mergesort(b,0,m - 1);
  int count1 = count_various_elements(a);
  int count2 = count_various_elements(b);
  a.insert(a.end(),b.begin(),b.end());
  mergesort(a,0,a.size()-1);
  int count3 = count_various_elements(a);
  if  (count1 < count2) {
    if (count1 == count3) {
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
  } else {
      if (count2 == count3) {
        std::cout << "YES";
      } else {
        std::cout << "NO";
      }
    }
  return 0;
}