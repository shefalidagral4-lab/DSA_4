#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);

        cout << "Element pushed\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Popped element: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top element: " << q1.front() << endl;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK USING TWO QUEUES ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. isEmpty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.top();
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is Not Empty\n");
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}