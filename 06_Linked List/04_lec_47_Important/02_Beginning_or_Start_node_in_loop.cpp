

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

Node* floydsDetetionAlgo(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            cout<<" Node is "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* intersection = floydsDetetionAlgo(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Insert a data on tail
void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
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
    insertAtTail(tail, 22);
    cout<<" here my inked list "<<endl;
    print(head);
    tail->next = head->next;

    // Approch 2 time coplexity O(n)
    if (floydsDetetionAlgo(head) != NULL)
    {
        cout << " Cycle is present " << endl;
    }
    else
    {
        cout << " Cycle is not present " << endl;
    }

    // starting node in loop
    cout<<" Starting node is "<< getStartingNode(head)->data<<endl;

    return 0;
}