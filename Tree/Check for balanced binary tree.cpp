#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
     Node* left;
     Node* right;
     Node(int val):data(val),left(nullptr),right(nullptr){}
};

int height(Node* root){
    if(root==nullptr) return 0;
    return 1+max(height(root->left),height(root->right));
}

bool isbalanced(Node* root){
    if(root==nullptr) return true;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    if(abs(leftheight-rightheight)>1) return false;
    return isbalanced(root->left)&&isbalanced(root->right);
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
