#include <bits/stdc++.h>
using namespace std;

#define MAXVALUE 5

class Stack
{
    int s[MAXVALUE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isOverflow()
    {
        return top == MAXVALUE - 1;
    }

    bool isUnderflow()
    {
        return top == -1;
    }

    void push(int x)
    {
        if (isOverflow())
        {
            cout << "Stack is Full\n";
            return;
        }

        top++;
        s[top] = x;
        cout << "Element Pushed\n";
    }

    void pop()
    {
        if (isUnderflow())
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << s[top] << " is deleted\n";
        top--;
    }

    void peek()
    {
        if (isUnderflow())
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top Element = " << s[top] << endl;
    }

    void display()
    {
        if (isUnderflow())
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack S;
    int value, c;

    do
    {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter element: ";
            cin >> value;
            S.push(value);
            break;

        case 2:
            S.pop();
            break;

        case 3:
            S.peek();
            break;

        case 4:
            S.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (c != 5);

    return 0;
}
