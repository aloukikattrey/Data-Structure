#include <bits/stdc++.h>
using namespace std;

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

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void DeleteatHead(Node *&head)
{

    // Node* temp = head;
    head = head->next;
    // free(temp);
}

void Deleteat_kth_position(Node *&head, int k)
{
    Node *temp = head;
    int i=0;
    while(i<k-2){
        temp=temp->next;
        i++;
    }
    Node* temp2= temp->next;
    temp->next=temp2->next;
    free(temp2);
}

void deleteAtTail(Node* &head){

    Node* temp = head;
    
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node* temp2= temp->next;
    temp->next=NULL;
    free(temp2);
}
int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(88);

    head->next = second;

    second->next = third;
    third->next = fourth;

    // display(head);
    // Deleteat_kth_position(head,3);
    display(head);
    deleteAtTail(head);
    deleteAtTail(head);


    display(head);

    return 0;
}