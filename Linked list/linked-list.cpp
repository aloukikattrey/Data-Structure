#include <bits/stdc++.h>
using namespace std;
// defining structure of linked list
// we can use struct also insted of class
class Node
{

public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

int main()
{
    // here we are creating 3 Nodes

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // linking these linked list with earch other

    head->next = second; // head is linked to second

    second->next = third;
    cout << head->data;

    /* head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+     +---+---+     +----+----+ */

    return 0;
}