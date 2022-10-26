#include <iostream>
#include <vector>


struct student {
    int id;
    int points;
};

int main() {

 int n;
 std::cin >> n;
 student *arr= new student[n];
    for (int i=0;i<n;i++){
     std::cin >> arr[i].id >> arr[i].points;
 }
    for (int i = 1; i < n; i++) {
        struct student key = arr[i];
        int j = i - 1;
        while (j>=0 && ((arr[j].points < key.points) || (arr[j].points == key.points && arr[j].id > key.id))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
   for (int i=0;i<n;i++){
       std::cout << arr[i].id << " " << arr[i].points << "\n";
   }
    return 0;
}
