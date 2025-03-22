#include<bits/stdc++.h>
#include<iostream>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    
    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// Approch 1 TC(n+m) and SC(n+m)
// // Function to perform inorder traversal and store the result in a vector
// void inOrder(TreeNode<int>* root, vector<int>& inOrderVal) {
//     if (root == NULL) return;
//     inOrder(root->left, inOrderVal);
//     inOrderVal.push_back(root->data);
//     inOrder(root->right, inOrderVal);
// }

// // Function to merge two sorted arrays into one sorted array
// vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
//     vector<int> ans(a.size() + b.size());
//     int i = 0, j = 0, k = 0;
//     while (i < a.size() && j < b.size()) {
//         if (a[i] < b[j]) {
//             ans[k++] = a[i++];
//         } else {
//             ans[k++] = b[j++];
//         }
//     }
//     while (i < a.size()) {
//         ans[k++] = a[i++];
//     }
//     while (j < b.size()) {
//         ans[k++] = b[j++];
//     }
//     return ans;
// }

// // Function to convert a sorted inorder traversal array to a balanced BST
// TreeNode<int>* inOrderToBST(int s, int e, vector<int>& inOrderVal) {
//     if (s > e) return NULL;
//     int mid = s + (e - s) / 2;
//     TreeNode<int>* root = new TreeNode<int>(inOrderVal[mid]);
//     root->left = inOrderToBST(s, mid - 1, inOrderVal);
//     root->right = inOrderToBST(mid + 1, e, inOrderVal);
//     return root;
// }

// // Function to merge two BSTs into one balanced BST
// TreeNode<int>* mergeBST(TreeNode<int>* root1, TreeNode<int>* root2) {
//     // Step 1: Store inorder traversals of both trees
//     vector<int> bst1, bst2;
//     inOrder(root1, bst1);
//     inOrder(root2, bst2);

//     // Step 2: Merge the two inorder vectors
//     vector<int> mergeSortedInorder = mergeArrays(bst1, bst2);

//     // Step 3: Convert the merged sorted inorder vector to a balanced BST
//     int s = 0, e = mergeSortedInorder.size() - 1;
//     TreeNode<int>* ans = inOrderToBST(s, e, mergeSortedInorder);
//     return ans;
// }

// Function to print the inorder traversal of a tree
void printInOrder(TreeNode<int>* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// approch 2 TC(n+m) and SC(1)
// 1. convert BST into sorted LL (Doubly linked used n this Approch you can do with Singly LL)
// 2. Merge 2 Sorted Linked List
// 3. sorted list --> BST 

// 1. convert BST into sorted LL (Doubly linked used n this Approch you can do with Singly LL)
void convertIntoSortedDLL(TreeNode<int>* root, TreeNode<int>*& head){
    // base case 
    if(root == NULL) return;
    convertIntoSortedDLL(root->right,head);
    root->right = head;
    if(head != NULL) 
        head->left = root;
    head = root;
    convertIntoSortedDLL(root->left,head);  
}
// 2. Merge 2 Sorted Linked List
TreeNode<int>* mergeLinkedList(TreeNode<int>* head1,TreeNode<int>* head2){
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;

    while(head1!= NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1= head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2= head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    } 
    while(head1!= NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }  
    while(head2!= NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;    
}
// 3. sorted list --> BST 
int countNodes(TreeNode<int>* head){
    int count =0;
    TreeNode<int>* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->right;
    }
    return count;
}
TreeNode<int>* sortedLLtoBST(TreeNode<int>* &head,int n){
    if(n<=0 || head == NULL) return NULL;

    TreeNode<int>* lefttree = sortedLLtoBST(head,n/2);
    TreeNode<int>* root = head;
    root->left = lefttree;
    head = head->right;
    root->right = sortedLLtoBST(head,(n-n/2)-1);
    return root;
}

TreeNode<int>* mergeBST(TreeNode<int>* root1, TreeNode<int>* root2) {
    TreeNode<int>* head1= NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    TreeNode<int>* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL; 

    TreeNode<int>* head = mergeLinkedList(head1,head2);

    int n = countNodes(head);
    TreeNode<int>* root = sortedLLtoBST(head,n);
    return root;
}

int main() {
    // Example: Creating two simple BSTs

    // BST 1
    TreeNode<int>* root1 = new TreeNode<int>(3);
    root1->left = new TreeNode<int>(1);
    root1->right = new TreeNode<int>(5);

    // BST 2
    TreeNode<int>* root2 = new TreeNode<int>(4);
    root2->left = new TreeNode<int>(2);
    root2->right = new TreeNode<int>(6);

    // Merging the two BSTs
    TreeNode<int>* mergedRoot = mergeBST(root1, root2);

    // Printing the inorder traversal of the merged BST
    cout << "Inorder traversal of the merged BST: ";
    printInOrder(mergedRoot);
    cout<<endl;

    return 0;
}
