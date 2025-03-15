#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

//insert into bst
/*Node* insertBST(Node* root,int val){
    if(!root) return new Node(val);
    if(val<root->data)
        root->left=insertBST(root->left,val);
    else
        root->right=insertBST(root->right,val);
    return root;
}*/

//construct bst from sorted inorder array
Node* constructBST(vector<int>&inorder,int start,int enD){
    if(start>enD) return nullptr;
    int mid=(start+enD)/2;
    Node* root=new Node(inorder[mid]);
    root->left=constructBST(inorder,start,mid-1);
    root->right=constructBST(inorder,mid+1,enD);
    return root;
}

Node* bstFromPreorder(vector<int>&preorder){
    vector<int>inorder=preorder;
    sort(inorder.begin(),inorder.end());
    return constructBST(inorder,0,inorder.size()-1);
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
