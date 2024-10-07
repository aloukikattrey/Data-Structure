#include <iostream>
using namespace std;
//#define n 5

class queue
{
    int *arr;
    int front;
    int back;
    int n;

public:
    queue(int size)
    {

        n = size;
        arr = new int[size];
        front = -1;
        back = -1;
    }
    bool isEmpty()
    {
        if (front == -1 || front > back)
        {

            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (back == n - 1)
        {
            return true;
        }
        return false;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "queue overflow, cant add " << value << endl;
            return;
        }
        back++;
        arr[back] = value;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Cant pop, queue empty" << endl;
        }
        front++;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Peek cant perform, queue empty";
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    queue q(6);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(1);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    // q.pop();
    //  q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.isEmpty() << endl;
    q.push(6);
    q.push(1);
    cout << q.peek();

    return 0;
}

/*

using array as queue has limitation that after deque array cant shift
all elements as its compexity would be o(n).

so if we make our queue full and then completey empty our array,
then we would not be able to add any elements, as out  front only
going to right side

*/