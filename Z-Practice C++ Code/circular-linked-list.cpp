#include <bits/stdc++.h>
using namespace std;
#define el cout<<"\n"


class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Circularlinkedlist
{

public:
    Node *head;
    Circularlinkedlist()
    {
        head = NULL;
    }

    void display()
    {
        Node *temp = head;
        // we use do while for the case if there is only one element is in list
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        el;
    }

    void InsertatHead(int val)
    {
        Node *new_node = new Node(val);

        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        Node *tail = head;

        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void InsertatLast(int val)
    {

        Node *new_node = new Node(val);
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = head;
    }

    void InsertatKthPosition(int val, int k)
    {
        Node *new_node = new Node(val);
        Node *temp = head;

        int i = 0;
        while (i < k - 2)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void deleteatHead(){
        Node* temp= head;
        Node* tail= head;
        while(tail->next!=head){
            tail=tail->next;
        }
        
        head= head->next;
        tail->next= head;
        free(temp);
    }
};

int main()
{
    Circularlinkedlist cll;

    cll.InsertatHead(13);
    cll.InsertatHead(12);
    cll.InsertatHead(11);
    cll.InsertatLast(99);
    cll.InsertatKthPosition(69,2);

    cll.display();
    cll.deleteatHead();
    cll.display();


    return 0;
}
boil