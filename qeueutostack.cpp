#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:

    // Push element
    void push(int x) {
        // Put new element in q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Pop element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Deleted: " << q1.front() << endl;
        q1.pop();
    }

    // Top element
    void top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top: " << q1.front() << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.top();

    s.pop();
    s.pop();

    s.top();

    return 0;
}