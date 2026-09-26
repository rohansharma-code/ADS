#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp){}
    stack<int> st;

    for (char ch : exp) {
        if (ch == ' ')
            continue;

}// If operand
        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        // If operator
        else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch (ch) {
                case '+':
                    st.push(val1 + val2);
                    break;
                case '-':
                    st.push(val1 - val2);
                    break;
                case '*':
                    st.push(val1 * val2);
                    break;
                case '/':
                    st.push(val1 / val2);
                    break;
                case '%':
                    st.push(val1 % val2);
                    break;
            
        }
    }

    return st.top();
}

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    getline(cin, postfix);

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}