#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* constructBST(Node* root,int val){
    if(!root) return new Node(val);
    if(val<root->data)
        root->left=constructBST(root->left,val);
    else
        root->right=constructBST(root->right,val);
    return root;
}

//construct bst by inserting one by one
Node* bstFromPreorder(vector<int>&preorder){
    if(preorder.empty()) return nullptr;
    Node* root=nullptr;
    for(int val:preorder){
        root=constructBST(root,val);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Node* root = bstFromPreorder(preorder);
    cout << "Inorder Traversal of Constructed BST: ";
    inorderTraversal(root);
    return 0;
}
