#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        arr[++rear] = x;
    }

    int dequeue() {
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }
};

int main() {
    Queue q;
    Queue first;
    Queue second;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }
    int half = n / 2;
    for (int i = 0; i < half; i++)
        first.enqueue(q.dequeue());

    while (!q.isEmpty())
        second.enqueue(q.dequeue());

    cout << "Interleaved Queue: ";
    while (!first.isEmpty()) {
        cout << first.dequeue() << " ";
        if (!second.isEmpty())
            cout << second.dequeue() << " ";
    }
    cout << endl;

    return 0;
}