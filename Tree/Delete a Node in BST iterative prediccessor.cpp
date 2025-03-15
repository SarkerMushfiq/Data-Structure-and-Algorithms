#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* deleteNode(Node* root,int key){
    Node* parent=nullptr;
    Node* current=root;

    while(current&&current->data!=key){
        parent=current;
        if(key<current->data){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    if(!current) return root;

    if(current->left==nullptr&&current->right==nullptr){
        if(!parent) return nullptr;
        if(parent->left==current) parent->left=nullptr;
        else parent->right=nullptr;
        delete current;
    }
    else if(current->left==nullptr||current->right==nullptr){
        Node* child=(current->left)? current->left:current->right;
        if(!parent) return child;
        if(parent->left==current) parent->left=child;
        else parent->right=child;
        delete current;
    }
    else{
        Node* successorParent=current;
        Node* successor= current->left;

        while(successor->right!=nullptr){
            successorParent=successor;
            successor=successor->right;
        }
        current->data=successor->data;

         if(successorParent->left==successor)
            successorParent->left=successor->right;
        else
            successorParent->right=successor->right;

        delete successor;
    }
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
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

    root = deleteNode(root, 50); // Delete node with key 50

    cout << "BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
