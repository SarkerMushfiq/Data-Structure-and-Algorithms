#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* insertIntoBST(Node* root,Node* key){
    if(!root) return key;

    if(key->data<root->data){
        root->left=insertIntoBST(root->left,key);
    }
    else if(key->data>root->data){
        root->right=insertIntoBST(root->right,key);
    }
    return root;
}

void inOrder(Node* root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main() {
    // Creating an existing BST
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout << "Before Insertion: ";
    inOrder(root);
    cout << endl;

    // Create a new node and insert it into BST
    Node* newNode = new Node(4);
    root = insertIntoBST(root, newNode);

    cout << "After Insertion: ";
    inOrder(root);
    cout << endl;

    return 0;
}
