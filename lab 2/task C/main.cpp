#include <iostream>
#include <vector>
int partition(std::vector<int>& arr, int low, int high)
{
  int pivot = arr[low];
  int i = low - 1, j = high + 1;

  while (true) {

    do {
      i++;
    } while (arr[i] < pivot);

    do {
      j--;
    } while (arr[j] > pivot);

    if (i >= j)
      return j;

    std::swap(arr[i], arr[j]);
  }
}
int partition_r(std::vector<int>& arr, int low, int high)
{
  srand(time(nullptr));
  int random = low + rand() % (high - low);

  std::swap(arr[random], arr[low]);

  return partition(arr, low, high);
}
void quickSort(std::vector<int>& arr, int low, int high)
{
  if (low < high) {

    int pi = partition_r(arr, low, high);


    quickSort(arr, low, pi);
    quickSort(arr, pi + 1, high);
  }
}


int main() {
   int n=0,m=0;
   int k;
   std::cin >> n >> m ;

   std::vector <int> mesk;
   std::vector <int> raft;
   for (int i=0;i < n; i++){
     for(int j=0;j<m;j++) {
       int x;
       std::cin >> x;
       raft.push_back(x);
     }
   }
   quickSort(raft,0,raft.size()-1);
   std::cin >> k;
   for (int i=0;i<k;i++){
        int x;
        std::cin >> x;
        mesk.push_back(x);
   }
   quickSort(mesk,0,k-1);

   int counter=0;

   int i=raft.size()-1;
   int j=mesk.size()-1;
   while ((i+1)*(j+1)>0){
     if(raft[i]>=mesk[j]){
       counter++;
       i--;
       j--;
     }
     else
       j--;
   }

   std::cout << counter;
   return 0;
}

































   // for (int c=0;c<=(n*m);c++) { //всего проходов по матрице
   //           //сортировка строк
    //    for (int i = 0; i < n; i++) {
    //        for (int j; j < m; j++) { //m-1
    //            if (raft[i][j] > raft[i][j + 1]) {
     //               temp=raft[i][j];
    //                raft[i][j]=raft[i][j+1];
     //               raft[i][j+1]=temp;
     //           }
     //   }
                          // столбцов
     //   for (int i = 0; i < m; i++) {
     //       for (int j; j < n; j++) { //n-1
      //          if(raft[j][i]>raft[j][i+1]){
      //              temp=raft[j][i];
      //              raft[j][i]=raft[j][i+1];
      //              raft[j][i+1]=temp;
     //           }
       //     }
      //  }
   // }
   // for ( int i=0;i < n; i++) {
   //     for (int j = 0; j < m; j++) {
   //         std::cout << raft[i][j] << " ";
   //     }
   //     std::cout << "\n";

  //  }


