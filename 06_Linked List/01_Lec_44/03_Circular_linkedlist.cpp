#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

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

void insertNode(Node* &tail,int element, int d){
    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // Non-empty list
        // assuming that the element is present in list

        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        // element Found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// print the list from tail
void print(Node* &tail){
    if(tail == NULL){
        cout<<" Your list empty "<<endl;
        return;
    }
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

// Deletion
void deleteNode(Node* &tail,int value){
    if(tail == NULL){
        cout<<" Your list empty"<<endl;
        return;
    }
    else{
        // non-empty list
        // assuming that "Value" is present in the list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if(curr == prev){// for 1 Node in linked list
            tail = NULL;
        }
        // >=2 Node
        else if(tail == curr){
            tail = prev;    
        }
        curr->next = NULL;
        delete curr;
    }
}

int main(){

    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    insertNode(tail,3,4);
    print(tail);
    insertNode(tail,6,7);
    print(tail);
    deleteNode(tail,4);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,6);
    print(tail);
    deleteNode(tail,5);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    
    return 0;
}