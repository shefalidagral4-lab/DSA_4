#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = value;

        cout << "Element inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted element: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is Not Empty\n");
            break;

        case 4:
            cout << (q.isFull() ? "Queue is Full\n" : "Queue is Not Full\n");
            break;

        case 5:
            q.peek();
            break;

        case 6:
            q.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}