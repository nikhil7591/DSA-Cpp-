#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class  Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
// Level Order Traversal (BFS)
void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){// purana level complete traverse ho chuka hai
            cout<<endl;
            // queue still has some child Node
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* insertBST(Node* &root,int data){
    if(root== NULL) {
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertBST(root->right,data);
    }
    else{
        root->left = insertBST(root->left,data); 
    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertBST(root,data);
        cin>>data;
    }
}

Node* minVal(Node* root){
    if(root == NULL) return NULL;
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    if(root == NULL) return NULL;
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFormBST(Node* root,int val){
    // base case
    if(root == NULL) return root;

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFormBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFormBST(root->left,val);
        return root;
    }
    else{
        root->right = deleteFormBST(root->right,val);
        return root;
    }

}

int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST: ";
    takeinput(root);

    cout<<"Printing the BST: "<<endl;
    LevelOrderTraversal(root);
    
    cout<<"Min value in BST: "<<minVal(root)->data <<endl;
    cout<<"Max value in BST: "<<maxVal(root)->data <<endl;

    // delete node
    root = deleteFormBST(root,30);

    cout<<"Printing the BST: "<<endl;
    LevelOrderTraversal(root);
    
    cout<<"Min value in BST: "<<minVal(root)->data <<endl;
    cout<<"Max value in BST: "<<maxVal(root)->data <<endl;
    
    return 0;
}