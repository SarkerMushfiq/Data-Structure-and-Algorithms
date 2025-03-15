#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

//helper to store info about subtree
struct SubTreeInfo{
    int size;
    int minval;
    int maxval;
    bool isBST;
};

SubTreeInfo findLargestBST(Node* root,int &maxSize){
    if(!root) return{0,INT_MAX,INT_MIN,true};

    //postorder traversal
    SubTreeInfo left=findLargestBST(root->left,maxSize);
    SubTreeInfo right=findLargestBST(root->right,maxSize);

    //check if current subtree is a bst
    if(left.isBST&&right.isBST&&root->data>left.maxval&&root->data<right.minval){
        int currSize=left.size+right.size+1;
        maxSize=max(maxSize,currSize);
        return{currSize,min(root->data,left.minval),max(root->data,right.maxval),true};
    }
    return{0,0,0,false};
}

int largestBST(Node* root){
    int maxSize=0;
    findLargestBST(root,maxSize);
    return maxSize;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);  // Violates BST property

    cout << "Size of the largest BST in BT: " << largestBST(root) << endl;

    return 0;
}
