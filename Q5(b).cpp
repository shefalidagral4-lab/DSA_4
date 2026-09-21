#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:

    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << "Element pushed\n";
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Popped element: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top element: " << q.front() << endl;
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK USING ONE QUEUE ---\n";
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