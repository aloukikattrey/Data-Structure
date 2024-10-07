#include <bits/stdc++.h>
using namespace std;

// for starter head node
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DblyLinkedList
{
public:
    Node *head;
    Node *tail;

    DblyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
};

void TraverseFromHead(Node* head){

    Node* temp = head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void TraverseFromTail(Node* tail){
    Node* temp = tail;
    while(temp->prev!=NULL){
        cout<<temp->data;
        temp=temp->prev;
    }
}


int main()
{
    // for starting node
    Node* new_node= new Node(3);

    DblyLinkedList dll;
    dll.head= new_node;
    dll.tail = new_node;



    return 0;
}