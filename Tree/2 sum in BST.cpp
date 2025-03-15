#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

class BSTtwoSum{
    void inorder(Node* root,vector<int>&result){
        if(!root) return;
        inorder(root->left,result);
        result.push_back(root->data);
        inorder(root->right,result);
    }
public:
    bool findTarget(Node* root,int k){
        vector<int>inorderTraversal;
        inorder(root,inorderTraversal);

        int left=0,right=inorderTraversal.size()-1;

        while(left<right){
            int sum=inorderTraversal[left]+inorderTraversal[right];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};

int main() {
    // Construct a simple BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    BSTtwoSum solution;
    int target = 9;
    if (solution.findTarget(root, target)) {
        cout << "Found two numbers in the BST that sum up to " << target << ".\n";
    } else {
        cout << "No two numbers in the BST sum up to " << target << ".\n";
    }

    return 0;
}
