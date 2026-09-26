#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string prefix;
    stack<int> st;

    cout << "Enter prefix expression: ";
    getline(cin, prefix);

    stringstream ss(prefix);
    string token;
    vector<string> tokens;

    while (ss >> token)
    {
        tokens.push_back(token);
    }

    for (int i = tokens.size() - 1; i >= 0; i--)
    {
        token = tokens[i];

        if (isdigit(token[0]))
        {
            st.push(stoi(token));
        }
        else
        {
            int a = st.top();
            st.pop();

            int b = st.top();
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