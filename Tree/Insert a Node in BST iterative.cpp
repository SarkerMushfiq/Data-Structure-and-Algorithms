#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* insertIntoBST(Node* root, Node* newNode){
    if(!root) return newNode;

    Node* parent=nullptr;
    Node* curr=root;

    while(curr){
        parent=curr;
        if(newNode->data<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(newNode->data<parent->data)
        parent->left=newNode;
    else
        parent->right=newNode;
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
