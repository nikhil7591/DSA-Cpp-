#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this ->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
            cout<<" Memory for free for node with data "<<value<<endl;
    }

};

// print the linkedlist 
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Find the length of linked list
int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// create the function insertAtHead() for create a linked list
void insertAtHead(Node* &head,Node* &tail,int d){
    if(head==NULL){// EMPTY HEAD
        Node* temp = new Node(d);
        head = temp;     
        tail = temp;
    }    
    else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// 
void insertAtTail(Node* &head,Node* &tail,int d){
    if(tail==NULL){// EMPTY Tail
        Node* temp = new Node(d);
        head = temp;
        tail = temp; 
    }
    else{
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

// insert any position
void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    // insert at start
    if(position == 1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1 && temp!=NULL){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }

    //
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode; 
    newNode->prev = temp;
}

// DELETION     
void deleteNode(Node* &head,Node* &tail,int position){
    // delete at start
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        // memeory free start Node
        delete temp;
    }
    else{
        // deleting any middle and last Node
        Node* current = head;
        Node* prev1 = NULL;
        // Node* prev_tail = tail;
        int count = 1;
        while(count < position && current!=NULL){
            prev1 = current;
            current = current->next;
            count++;
        }
        // cout<<count;
        if(count == getLength(head)){
            prev1->next = NULL;
            tail = prev1;
            return;
        }

        prev1->next = current->next;
        current->next->prev = prev1;
        current->next=NULL;
        delete current;
    }
}

int main(){
    // create the first node
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,11);
    print(head);
    insertAtHead(head,tail,8);
    print(head);
    insertAtTail(head,tail,12);
    print(head);
    insertAtTail(head,tail,19);
    print(head);
    insertAtPosition(head,tail,3,22);
    print(head);
    insertAtPosition(head,tail,6,22);
    print(head);
    // linked list length
    int length = getLength(head);
    cout<<" Length of Linked list: "<<length<<endl;
    deleteNode(head,tail,5);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    print(head);
    
    return 0;
}