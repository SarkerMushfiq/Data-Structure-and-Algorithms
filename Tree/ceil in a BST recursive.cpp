#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findCeil(Node* root,int X){
    if(!root) return -1;

    if(root->data==X) return X;

    if(root->data>X){
        int ceilLeft=findCeil(root->left,X);
        return (ceilLeft==-1)?root->data:ceilLeft;
    }
    return findCeil(root->right,X);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int X = 5;
    cout << "Ceil of " << X << " is: " << findCeil(root, X) << endl;

    return 0;
}
