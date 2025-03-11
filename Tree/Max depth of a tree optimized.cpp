#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
     Node* left;
     Node* right;
     Node(int val):data(val),left(nullptr),right(nullptr){}
};

int checkBalance(Node* root){
    if(root==nullptr) return 0;

    int leftheight=checkBalance(root->left);
    if(leftheight==-1) return -1;

    int rightheight=checkBalance(root->right);
    if(rightheight==-1) return -1;

    if(abs(leftheight-rightheight)>1) return -1;
    return 1+max(leftheight,rightheight);
}

bool isbalanced(Node* root){
    return checkBalance(root)!=-1;
    }

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    if (isbalanced(root))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is NOT Balanced" << endl;

    return 0;
}
