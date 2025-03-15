#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

void inOrderTraversal(Node* root,Node* &prev,Node* &first,Node* &second){
    if(!root) return;

    inOrderTraversal(root->left,prev,first,second);

    if(prev&&prev->data>root->data){
        if(!first){
            first=prev;
        }
        second=root;
    }
    prev=root;

    inOrderTraversal(root->right,prev,first,second);
}

void fixBST(Node* root){
    Node* first=nullptr;
    Node* second=nullptr;
    Node* prev=nullptr;
    inOrderTraversal(root,prev,first,second);
    if(first&&second){
        swap(first->data,second->data);
    }
}

void inorderPrint(Node* root) {
    if (root) {
        inorderPrint(root->left);
        cout << root->data << " ";
        inorderPrint(root->right);
    }
}

int main() {
    // Constructing a simple BST with two swapped nodes
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    // Swapping two nodes to simulate the error
    swap(root->left->data, root->right->left->data);  // Swap 8 and 12

    cout << "Before fixing the BST: ";
    inorderPrint(root);
    cout << endl;

    fixBST(root);

    cout << "After fixing the BST: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
