#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

int findFloor(Node* root,int x){
    int floor=-1;

    while(root){
        if(root->data==x) return x;

        if(root->data<x){
            floor=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
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
    cout << "Floor of " << X << " is: " << findFloor(root, X) << endl;

    return 0;
}
