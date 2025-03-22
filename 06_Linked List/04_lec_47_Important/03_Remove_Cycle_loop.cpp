

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Basic Linked list how to creat a linked list
class Node
{
public:
    int data;
    Node *next;

    // Constuctor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " Memory for free for node with data " << value << endl;
    }
};

// Approch 2 to find Cycle is present in linked list

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}

void InsertionAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert a data on tail
void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertionAtMiddle(Node *&head, Node *&tail, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        InsertionAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1; // it is Index of linkedlist

    while (cnt < position - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if (cnt == position)
    {
        insertAtTail(tail, d);
        return;
    }
    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


// print a data LinkedList
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertionAtMiddle(head,tail,4,22);
    cout<<" here my inked list "<<endl;
    print(head);
    tail->next = head->next;

    // Approch 2 time coplexity O(n)
    if (floydDetectLoop(head) != NULL)
    {
        cout << " Cycle is present " << endl;
    }
    else
    {
        cout << " Cycle is not present " << endl;
    }

    // starting node in loop
    cout<<" Starting node is "<< getStartingNode(head)->data<<endl;

    // removing loop
    removeLoop(head);
    print(head);

    return 0;
}