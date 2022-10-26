#include <bits/stdc++.h>
using namespace std;

struct QueueNode {
    int data;
    struct QueueNode *next;
};

struct QueueNode* head= NULL;
struct QueueNode* tail = NULL;
struct QueueNode* temp;

void Insert(int val) {
    if (tail == NULL) {
        tail = (struct QueueNode *)malloc(sizeof(struct QueueNode));
        tail->next = NULL;
        tail->data = val;
        head = tail;
    } else {
        temp=(struct QueueNode *)malloc(sizeof(struct QueueNode));
        tail->next = temp;
        temp->data = val;
        temp->next = NULL;
        tail = temp;
    }
}

int Delete() {
    temp = head;
    if (head == NULL) {
        cout<<"Underflow"<<endl;
        exit(1);
    }
    else if (temp->next != NULL) {
        temp = temp->next;
        int deleted = head->data;
        delete (head);
        head = temp;
        return deleted;
    } else {
        int deleted = head->data;
        delete (head);
        head = NULL;
        tail = NULL;
        return deleted;
    }
}

void Display() {
    temp = head;
    if ((head == NULL) && (tail == NULL)) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue elements are: ";
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    char sign;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> sign;
        if (sign == '+') {
            cin >> x;
            Insert(x);
        }
        else {
            cout << Delete() << "\n";
        }
    }
    return 0;
}
