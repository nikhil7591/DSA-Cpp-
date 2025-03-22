#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Basic Linked list how to creat a linked list 
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


// Insertion a data on head

void InsertionAtHead(Node* &head,int d){
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

// Insert a data on tail
void insertAtTail(Node* &tail,int d){
    // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail-> next;
}

// Insert a data on Middle/ Poisition

void insertionAtMiddle(Node* &head,Node* &tail,int position,int d){
    // insert at start 
    if(position == 1){
        InsertionAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1; // it is Index of linkedlist

    while(cnt<position-1 && temp!=NULL){
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if(cnt == position){
        insertAtTail(tail,d);
        return;
    }
    // creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp ->next;
    temp-> next = nodeToInsert;

}


// print a data LinkedList
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// DELETION OF LINKED LIST
void deleteNode(int position,Node* &head, Node* &tail){
    // deleting first or start Node
    if(position==1){
        Node* temp = head;
        head = head->next;
        // memeory free start Node
        temp->next = NULL;
        delete temp;
    }else{
        // deleting any middle and last Node
        Node* current = head;
        Node* prev = NULL;
        // Node* prev_tail = tail;
        int count = 1;
        while(count < position && current != NULL){
            prev = current;
            current = current->next;
            count++;
        }
        // cout<<count;
        if(count == 6){
            prev->next = NULL;

            tail = prev;
            return;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;

    }
}

int main(){

    // created a new node
    Node* node1 = new Node(10);
    // cout<< node1 -> data<<endl;
    // cout<< node1 -> next<<endl;
   
    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout<<" Isert at Head in Node "<<endl;
    InsertionAtHead(head,9);
    print(head);
    InsertionAtHead(head,8);
    print(head);

    cout<<" Insert at Tail in Node "<<endl;
    insertAtTail(tail,13);
    print(head);
    insertAtTail(tail,14);
    print(head);

    cout<<" Isert at Position in Node "<<endl;
    insertionAtMiddle(head,tail,1,11);
    print(head);
    insertionAtMiddle(head,tail,3,12);
    print(head);

    // cout<< head nad tail data for testing
    cout<<" Head "<< head -> data<<endl;
    cout<<" Tail "<< tail -> data<<endl;

    // Deletion in Linkedlist
    deleteNode(7,head,tail);
    print(head);
    cout<<" Head "<< head -> data<<endl;
    cout<<" Tail "<< tail -> data<<endl;
    return 0;
}