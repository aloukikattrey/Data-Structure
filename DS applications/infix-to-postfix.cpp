#include <bits/stdc++.h>
using namespace std;

int precedence(char p)
{
    if (p == '*' || p == '/')
    {
        return 3;
    }
    if (p == '+' || p == '-')
    {
        return 2;
    }
    return 0;
}
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}

void Postfix(string infix)
{
    int count = infix.size();
    stack<char> st;
    string postfix[count];
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        if (precedence(infix[i]) > precedence(st.top()))
        {
            st.push(infix[i]);
        }
        else
        {

            postfix[j] = st.top();
            st.pop();
            j++;
        }
        while (!st.empty())
        {
            postfix[j] = st.top();
            st.pop();
            j++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << postfix[i];
    }
}
int main()
{
    string s = "x-y/z-k*d";

    Postfix(s);
    return 0;
}