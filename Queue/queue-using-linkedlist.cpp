#include <iostream>
using namespace std;
// create a linked list structure where elements are stored as nodes
class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {

        node *n = new node(x);
        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop()
    {

        if (front == NULL)
        {
            cout << "queue is empty" << endl;
            return;
        }
        node *temp = front;
        front = front->next;

        delete temp; // or we can use -> free(temp); in STL
    }

    int peek()
    {

        if (front == NULL)
        {
            cout << "Cant peek, queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }

    // there is no isfull as using linked list we have no limit
};
int main()
{
    queue q;
    q.push(7);
    q.push(8);
    q.push(9);
    q.pop();
    q.pop();
    q.pop();
    cout << q.isEmpty() << endl;

    cout << q.peek() << endl;

    return 0;
}