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
    //step-1: search for the node to delete
    while(current&&current->data!=key){
        parent=current;
        if(key<current->data){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    //if not found
    if(!current)return root;

    //step-2: handle the deletion case
    //case-1: Node has no children(leaf)
    if(!current->left&&!current->right){
        if(!parent) return nullptr;//if deleting root
        if(parent->left==current) parent->left=nullptr;
        else parent->right=nullptr;
        delete current;
    }
    //case-2: Node has one child
    else if(!current->left||!current->right){
        Node* child=(current->left)?current->left:current->right;
        if(!parent)return child;//if deleting the root
        if(parent->left==current) parent->left=child;
        else parent->right=child;
        delete current;
    }
    //case-3: Node has two children
    else{
        Node* successorParent=current;
        Node* successor=current->right;

        //find inorder successor
        while(successor->left){
            successorParent=successor;
            successor=successor->left;
        }
        //replace data
        current->data=successor->data;
        //delete successor
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
