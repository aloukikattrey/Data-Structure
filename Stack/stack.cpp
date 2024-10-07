#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int top;
    int n;

public:
    stack(int size)
    {
        n = size;
        arr = new int[n]; // second way to create array in cpp is new int[n]
        top = -1;
        }

    void push(int value)
    {
        if (top == n - 1)
        {
            cout << "stack overflow, cant add " << value << " to stack"<<endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow, can't pop"<<endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            return -1;
        }
        return arr[top];
    }
    void empty()
    {
        if (top == -1)
        {
            cout << "Empty";
        }
        else
        {
            cout << "Not empty";
        }
    }
};

int main()
{
    stack st(7);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(15);
    st.push(55);
    cout << st.Top() << "\n";
    st.pop();
    st.pop();
 

    st.empty();
    return 0;
}