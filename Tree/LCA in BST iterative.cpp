#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* findLCA(Node* root,int p,int q){
    while(root){
        if(p<root->data&&q<root->data){
            root=root->left;
        }
        else if(p>root->data&&q>root->data){
            root=root->right;
        }
        else{
            return root;
        }
    }
    return nullptr;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    int p = 5, q = 15;
    Node* lca = findLCA(root, p, q);
    if (lca)
        cout << "LCA of " << p << " and " << q << " is: " << lca->data << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}
