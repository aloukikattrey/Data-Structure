#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        if (s[i] == ')')
        {
            st.pop();
        }
    }
    if (st.empty())
    {
        cout << s << " is balanced";
    }
    else
    {
        cout << s << " is not balanced";
    }
}
int main()
{
    string s = "((2+3)*(5))";
    solve(s);

    return 0;
}