#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"

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

    void TraverseFromHead()
    {

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ->";
            temp = temp->next;
        }
        el;
    }
    void TraverseFromTail()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        el;
    }

    void InsertatHead(int val)
    {

        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void InsertatTail(int val)
    {

        Node *new_node = new Node(val);

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void InsertatKthPosition(int val, int k)
    {

        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        int i = 0;
        Node *temp = head;

        while (i < k - 2)
        {
            temp = temp->next;
            i++;
        }

        temp->next->prev = new_node;
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next=new_node;
    }
};

int main()
{

    DblyLinkedList dll;
    dll.InsertatHead(22);
    dll.InsertatHead(23);
    dll.InsertatTail(89);
    dll.InsertatTail(90);
    dll.InsertatHead(67);
    dll.TraverseFromHead();

    dll.InsertatKthPosition(12, 8);

    dll.TraverseFromHead();
    // dll.TraverseFromTail();

    return 0;
}