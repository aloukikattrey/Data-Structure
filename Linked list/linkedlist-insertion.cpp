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
void display(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertatHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next= head;
    head=temp;
}

void InsertatLast(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next= new_node;
}
// 0>1>2>3>4>5
void Insertat_kth_position(Node* &head, int val, int k){
    if(k==1){
        insertatHead(head,val);
        return;
    }
    Node* new_node = new Node(val);
    Node* temp= head;
    int i=0;
    while(i<k-2){
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;

}


int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(88);


    head->next = second;

    second->next = third;
    third->next=fourth;
    

    display(head);
    insertatHead(head,12);
    display(head);
    InsertatLast(head,99);
    display(head);
    Insertat_kth_position(head,69,1);
    display(head);


    return 0;
}