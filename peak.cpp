#include <iostream>
using namespace std;

int queue[5];
int front = -1;
int rear = -1;
int n = 5;

void insert() {
    int x;
    if (rear == n - 1) {
        cout << "Queue is Full" << endl;
    } else {
        if (front == -1) {
            front = 0;
        }
        cout << "Insert element in Queue: ";
        cin >> x;
        rear++;
        queue[rear] = x;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Front element is: " << queue[front] << endl;
    }
}

int main() {
    insert();
    insert();
    insert();
    display();
    peek();
    return 0;
}
