#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* constructBST(vector<int>&preorder,int &index,int min,int max){
    if(index>=preorder.size())return nullptr;

    int val=preorder[index];
    if(val<min||val>max) return nullptr;

    Node* root=new Node(val);
    index++;

    root->left=constructBST(preorder,index,min,val);
    root->right=constructBST(preorder,index,val,max);

    return root;
}

Node* bstFromPreorder(vector<int>&preorder){
    int index=0;
    return constructBST(preorder,index,INT_MIN,INT_MAX);
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
