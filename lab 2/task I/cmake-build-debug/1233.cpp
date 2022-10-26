#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  int mass1[x];
  for (int i = 0; i<x; i++)
    cin >> mass1[i];
  int y;
  cin >> y;
  int mass2[x];
  for (int i = 0; i<y; i++)
    cin >> mass2[i];

  int aa, bb;
  if (x == 0){
    aa = 0;
  }else
    aa = 1;

  if (y == 0){
    bb = 0;
  }else
    bb = 1;


  for(int i=1;i<x;i++){
    for(int j=i; j>0 && mass1[j-1]>mass1[j]; j--)
      swap(mass1[j-1], mass1[j]);
  }
  for(int i=1;i<y;i++) {
    for (int j = i; j > 0 && mass2[j - 1] > mass2[j]; j--)
      swap(mass2[j - 1], mass2[j]);
  }

  for(int i=1;i<x;i++){
    if (mass1[i-1] != mass1[i])
      aa += 1;
  }
  for(int i=1;i<y;i++){
    if (mass2[i-1] != mass2[i])
      bb += 1;
  }
  int un1[aa];
  int un2[bb];
  un1[0] = mass1[0];
  un2[0] = mass2[0];
  int k = 1;
  for (int i = 1; i < x; i ++){
    if (mass1[i-1] != mass1[i]){
      un1[k] = mass1[i];
      k += 1;
    }
  }
  k = 1;
  for (int i = 1; i < y; i++){
    if (mass2[i-1] != mass2[i]){
      un2[k] = mass2[i];
      k += 1;
    }
  }
  bool f = true;
  for (int i = 0; i < aa; i++){
    if (un1[i] != un2[i]) {
      f = false;
    }
  }

  /*for (int i = 0; i < x; i++){
      cout << mass1[i];
  }*/


  if (f && aa == bb){
    cout << "YES";
  }else
    cout << "NO";

  return 0;
}