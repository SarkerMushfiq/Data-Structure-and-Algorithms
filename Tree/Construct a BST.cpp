#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data1):data(data1),left(nullptr),right(nullptr){}
};

Node* insertBST(Node* root,int val){
    if(!root) return new Node(val);

    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

Node* buildBST(){
    Node* root=nullptr;
    int n,val;

    cout<<"Enter number of elements in BST: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>val;
        root=insertBST(root,val);
    }
    return root;
}

void inorderTraversal(Node* root){
    if(!root) return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    Node* root=buildBST();

    cout<<"Inorder traversal(sorted BST): ";
    inorderTraversal(root);
    cout<<endl;
    return 0;
}
