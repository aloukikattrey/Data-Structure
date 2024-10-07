#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int prefixCalculation(string s)
{
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (s[i] >= '0' && s[i] <= '9') // if value is operand
        {
            st.push(s[i] - '0');
        }
        else // if value is operator
        {

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    cout << prefixCalculation("*a+bc");
    return 0;
}