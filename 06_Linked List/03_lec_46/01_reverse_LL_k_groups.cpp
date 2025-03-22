#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

int length(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* reversed(Node* &head, int k, int len) {
    // Base case
    if (head == NULL || k <= 0) {
        return head;
    }
    if (len < k) {
        return head;
    }
    
    // Step 1: Reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Step 2: Recursion will handle the rest
    if (next != NULL) {
        head->next = reversed(next, k, len - k);
    }
    
    // Step 3: Return head of reversed list
    return prev;
}

Node* kReverse(Node* head, int k) {
    int len = length(head);
    return reversed(head, k, len);
}

void insertionAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int value;

    cout << "Enter values for the linked list (enter -1 to stop):" << endl;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        insertionAtHead(head, value);
    }

    cout << "Original List: ";
    print(head);

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Node* ans = kReverse(head, k);
    cout << "Reversed List: ";
    print(ans);

    return 0;
}
