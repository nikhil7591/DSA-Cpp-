#include <bits/stdc++.h>
using namespace std;

// Structure of a node of BST
struct Node {
    int data;
    Node *left, *right;
};

// Helper function to create a new node
struct Node* getNode(int data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal and store data in a priority queue
void storeInMinHeap(Node* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (root == NULL)
        return;

    // Recur on the left subtree
    storeInMinHeap(root->left, minHeap);

    // Push the node's data into the min-heap
    minHeap.push(root->data);

    // Recur on the right subtree
    storeInMinHeap(root->right, minHeap);
}

// Function to replace BST node values with Min Heap values in preorder fashion
void convertToMinHeap(Node* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (root == NULL)
        return;

    // Replace current node's data with the smallest value in min-heap
    root->data = minHeap.top();
    minHeap.pop();

    // Recur on the left and right subtrees
    convertToMinHeap(root->left, minHeap);
    convertToMinHeap(root->right, minHeap);
}

// Function to convert BST to Min Heap
void convertBSTToMinHeap(Node* root) {
    // Priority queue to act as a min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Store all BST nodes into the min-heap
    storeInMinHeap(root, minHeap);

    // Replace BST values with Min Heap values
    convertToMinHeap(root, minHeap);
}

// Function for preorder traversal
void preorderTraversal(Node* root) {
    if (!root)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Driver program to test the code
int main() {
    // BST formation
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    cout << "Preorder Traversal before conversion:" << endl;
    preorderTraversal(root);
    cout << endl;

    // Convert BST to Min Heap
    convertBSTToMinHeap(root);

    cout << "Preorder Traversal after conversion to Min Heap:" << endl;
    preorderTraversal(root);
    cout << endl;

    return 0;
}
