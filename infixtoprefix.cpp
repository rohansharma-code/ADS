#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPrefix(string infix)
{
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' and ')'
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert reversed infix to postfix
    string postfix = "";
    stack<char> st;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() &&
                    (precedence(st.top()) > precedence(ch) ||
                    (precedence(st.top()) == precedence(ch) && ch == '^')))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    // Step 4: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;

    return 0;
}