#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // 1. Insert elements
    dq.push_back(10);      // Insert at back
    dq.push_back(20);
    dq.push_front(5);      // Insert at front
    dq.push_front(1);

    // Deque: 1 5 10 20

    // 2. Display deque
    cout << "Deque elements: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // 3. Access elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;
    cout << "Element at index 2: " << dq.at(2) << endl;

    // 4. Remove elements
    dq.pop_front();        // Removes 1
    dq.pop_back();         // Removes 20

    cout << "After pop operations: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // 5. Size
    cout << "Size: " << dq.size() << endl;

    // 6. Check if empty
    if (dq.empty())
        cout << "Deque is empty" << endl;
    else
        cout << "Deque is not empty" << endl;

    // 7. Insert at a particular position
    dq.insert(dq.begin() + 1, 100);

    cout << "After insert: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // 8. Erase an element
    dq.erase(dq.begin() + 1);

    cout << "After erase: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // 9. Clear entire deque
    dq.clear();

    cout << "Size after clear: " << dq.size() << endl;

    return 0;
}