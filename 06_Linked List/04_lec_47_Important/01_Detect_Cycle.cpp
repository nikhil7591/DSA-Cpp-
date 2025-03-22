

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

// Approch 1 to find Cycle is present in Linked list
bool isDetected(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << " Which element " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Approch 2 to find Cycle is present in linked list

bool floydsDetetionAlgo(Node *head)
{
    if (head == NULL)
    {
        return false;
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
            return true;
        }
    }
    return false;
}

// Insertion a data on head

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

// Insert a data on Middle/ Poisition

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

    // created a new node
    Node *node1 = new Node(10);
    // cout<< node1 -> data<<endl;
    // cout<< node1 -> next<<endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 22);
    insertionAtMiddle(head, tail, 3, 15);
    cout<<" here my inked list "<<endl;
    print(head);
    tail->next = head->next;
    //  Approch 1 time coplexity O(n)
    if (isDetected(head))
    {
        cout << " Cycle is present " << endl;
    }
    else
    {
        cout << " Cycle is not present " << endl;
    }

    // Approch 2 time coplexity O(n)
    if (floydsDetetionAlgo(head))
    {
        cout << " Cycle is present " << endl;
    }
    else
    {
        cout << " Cycle is not present " << endl;
    }

    return 0;
}