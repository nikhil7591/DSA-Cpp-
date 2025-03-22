#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* reverse1(Node* &head){
    // Method 3
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* chottahead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return chottahead;
}

void reverse(Node* &head, Node* &prev, Node* &curr){
    // Method 2
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverse(head,curr,forward);
    curr ->next = prev;
}

Node* reverseLinkedList(Node *head)
{
    // method 3
    return reverse1(head);

    /*
    // recurison method 2
    Node* prev = NULL;
    Node* curr = head;

    reverse(head,prev,curr);
    return head;
    */

    /*
    // method 1
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;*/
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void InsertionAtHead(Node* &head,int d){
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}      

int main(){
    Node* head = NULL;
    InsertionAtHead(head,9);
    InsertionAtHead(head,3);
    InsertionAtHead(head,2);
    InsertionAtHead(head,10);
    InsertionAtHead(head,5);
    print(head);
    Node* ch = reverseLinkedList(head);
    print(ch);

    
    return 0;
}