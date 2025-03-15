#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

void MorrisTraversal(Node* root){
    Node* curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            Node* pre=curr->left;
            while(pre->right!=nullptr&&pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==nullptr){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=nullptr;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris In-Order Traversal: ";
    MorrisTraversal(root);
    return 0;
}
