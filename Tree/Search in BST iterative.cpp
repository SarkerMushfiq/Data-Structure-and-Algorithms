#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
     Node* left;
     Node* right;
     Node(int val):data(val),left(nullptr),right(nullptr){}
};

//more efficient(constant space)

bool searchBST(Node* root,int key){
    while(root){
        if(root->data==key) return true;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    return false;
}

Node* insertBST(Node* root,int val){
    if(!root) return new Node(val);

    if(val<root->data)
        root->left=insertBST(root->left,val);
    else
        root->right=insertBST(root->right,val);

    return root;
}

int main() {
    Node* root = nullptr;
    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 15);
    root = insertBST(root, 2);
    root = insertBST(root, 7);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (searchBST(root, key))
        cout << "Value " << key << " found in BST.\n";
    else
        cout << "Value " << key << " not found in BST.\n";

    return 0;
}

