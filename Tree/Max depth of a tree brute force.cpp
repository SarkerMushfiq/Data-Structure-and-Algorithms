#include<bits/stdc++.h>
using namespace std;
//recursive approach
class Node{
public:
    int data;
    Node* left;
    Node* right;
public:
    Node(int data1){
        data=data1;
        left=right=nullptr;
    }
};

int maxDepth(Node* root){
    if(root==nullptr) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}

int main(){
    Node* root=new Node(1);
     root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Max Depth: " << maxDepth(root) << endl;
    return 0;
}
