#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

//function to find prediccessor
Node* findMax(Node* root){
    while(root->right){
        root=root->right;
    }
    return root;
}

//function to delete Node
Node* deleteNode(Node* root,int key){
    if(!root) return root;

    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(!root->left){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp=findMax(root->left);
            root->data=temp->data;
            root->left=deleteNode(root->left,temp->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "BST before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 70); // Delete node with key 50

    cout << "BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
