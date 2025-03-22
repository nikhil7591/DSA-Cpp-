#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // Constuctor
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        // Destructor 
        ~Node(){
            int value = this->data;
            // memory free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<" Memory for free for node with data "<<value<<endl;
        }
};

void InsertionAtHead(Node* &head,int d){ 
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node* &head){
    
    Node* temp = head;

    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* removeDuplicate(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data ){
            Node* next_next = curr->next->next;
            delete curr->next;
            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }
    } 
    return head;
}

int main(){
    Node* head  = NULL;
    InsertionAtHead(head,5);
    InsertionAtHead(head,4);
    InsertionAtHead(head,4);
    InsertionAtHead(head,3);
    InsertionAtHead(head,2);
    InsertionAtHead(head,2);
    InsertionAtHead(head,1);
    print(head);

    Node* result = removeDuplicate(head);
    print(result);
    
    return 0;
}