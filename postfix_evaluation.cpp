#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string postfix;
    stack<int> st;

    cout << "Enter postfix expression: ";
    getline(cin, postfix);

    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            st.push(stoi(token));
        }
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else if (token == "/")
                st.push(a / b);
        }
    }

    cout << "Result = " << st.top();

    return 0;
}