#include <iostream>
using namespace std;

struct Node
{
    int key;
    int left;
    int right;
    int height;
};

int height(Node *arr, int index)
{
    if (index == -1)
    {
        return 0;
    }

    return arr[index].height;
}

int balance_factor(Node *arr, int index)
{
    return height(arr, arr[index].right) - height(arr, arr[index].left);
}

int main()
{

    int n;
    int key, left, right;
    cin >> n;

    Node *arr = new Node[n];

    if (n == 0)
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> key >> left >> right;
            arr[i].key = key;
            arr[i].left = left - 1;
            arr[i].right = right - 1;
            arr[i].height = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].height = max(height(arr, arr[i].left), height(arr, arr[i].right)) + 1;
    }



    for (int i = 0; i < n; i++)
    {

        int temp = balance_factor(arr, i);
        if (i == 0){
            cout << temp + 1 << "\n";
        }
        cout << temp << "\n";

    }

    delete[] arr;
    return 0;
}