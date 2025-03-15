#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

bool validateBST(Node* root,int miN,int maX){
    if(!root) return true;
    if(root->data<=miN||root->data>=maX)return false;
    return validateBST(root->left,miN,root->data)&&validateBST(root->right,root->data,maX);
}

bool isBST(Node* root){
    return validateBST(root,INT_MIN,INT_MAX);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    cout << (isBST(root) ? "Yes, it's a BST" : "No, it's not a BST") << endl;
    return 0;
}
