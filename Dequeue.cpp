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
    if (front == -1 || front > rear) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Element deleted from queue is: " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

int main() {
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    dequeue();
    display();
    return 0;
}
