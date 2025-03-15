#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};
//function to find the inorder successor
Node* findMin(Node* root){
    while(root->left){
        root=root->left;
    }
    return root;
}
//func to delete a node in bst
Node* deleteNode(Node* root,int key){
    if(!root) return root;//base case

    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{//Node found
        if(!root->left){//case1&2: no child or one right child
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(!root->right){//case2: one left child
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //case3: two children,replace with inorder successor
        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
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
