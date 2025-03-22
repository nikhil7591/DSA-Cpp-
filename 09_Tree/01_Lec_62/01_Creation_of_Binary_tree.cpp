#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// creation of Binary tree
class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildTree(node* root){
    cout<<" Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<" Enter the data for inserting in left: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<" Enter the data for inserting in right: "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

// Level Order Traversal (BFS)
void LevelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){// purana level complete traverse ho chuka hai
            cout<<endl;
            // queue still has some child nodes
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
}

void display(node* root){
    if(root == NULL){
        return;
    }
    // pree Order
    // cout<<root->data<<" ";
    display(root->left);
    // inOrder
    // cout<<root->data<<" ";
    display(root->right);
    // post Order
    cout<<root->data<<" "; 
}

// Buil from level Order
void buildFromLevelOrder(node* &root){
    queue<node* >q;
    cout<<" Enter the data for root "<<endl;
    int data ;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(  ! q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<" Enter left node data "<<temp->data<<endl;   
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp ->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<" Enter right node data "<<temp->data<<endl;   
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp ->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    
    node* root = NULL;
    // root = buildTree(root);
    
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1  
    // // Level Order traversal
    // cout<<" Printing the LevelOrderTraveral Tree (BFS) right to left : "<<endl;
    // LevelOrderTraversal(root);
    // cout<<endl;
    // cout<<"Display the PostOrder Tree : "<<endl;
    // display(root);

    // Build from Level order
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    LevelOrderTraversal(root);

    return 0;
}