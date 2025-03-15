#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* bstFromPreorder(vector<int>&preorder){
    if(preorder.empty())return nullptr;

    Node* root=new Node(preorder[0]);
    stack<Node*>st;
    st.push(root);

    for(int i=1;i<preorder.size();i++){
        Node* temp=nullptr;

        while(!st.empty()&&preorder[i]>st.top()->data){
            temp=st.top();
            st.pop();
        }
        Node* newNode=new Node(preorder[i]);
        if(temp==nullptr){
            st.top()->left=newNode;
        }
        else{
            temp->right=newNode;
        }
        st.push(newNode);
    }
    return root;
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
