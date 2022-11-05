#include <iostream>


using namespace std;

int left_bin_search(int array[], int x[], int length, int i) {
    int left = 0;
    int middle = 0;
    int right = length - 1;
    while (right > left + 1) {
        middle = (left + right) / 2;
        if (array[middle] < x[i]) {
            left = middle - 1;
        } else {
            right = middle + 1;
        }
    }
    int b = middle + 1;
    return b ;
}

int right_bin_search(int array[], int x[], int length, int i) {
    int left = 0;
    int middle = 0;
    int right = length - 1;
    while (right >= left) {
        middle = (left + right) / 2;
        if (array[middle] <= x[i]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return middle + 1;
}

int main() {
    int length;
    cin >> length;
    int *array = new int[length];
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }

    int counts_of_numbers;
    cin >> counts_of_numbers;
    int *array_counts = new int[counts_of_numbers];
    for (int i = 0; i < counts_of_numbers; i++) {
        cin >> array_counts[counts_of_numbers];
    }

    for (int i = 0; i < counts_of_numbers; i++) {
        cout << left_bin_search(array, array_counts, length, i);
        cout << " ";
        cout << right_bin_search(array, array_counts, length, i) << "\n";
    }

    delete [] array;
    delete [] array_counts;
    return 0;
}