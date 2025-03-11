#include<bits/stdc++.h>
using namespace std;

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

vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;
    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }
    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;
    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it);
            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it);
            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
// Function to print the
// elements of a vector
/*void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}*/


Node* buildSampleTree() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main(){
   Node* root= buildSampleTree();
    vector<int>pre,in,post;
    vector<vector<int>>traversals=preInPostTraversal(root);
    pre=traversals[0];
    in=traversals[1];
    post=traversals[2];
    cout<<"pre: ";
    for(int val:pre){
        cout<<val<<" ";
    }
    cout<<endl;
     cout<<"In: ";
    for(int val:in){
        cout<<val<<" ";
    }
    cout<<endl;
     cout<<"post: ";
    for(int val:post){
        cout<<val<<" ";
    }
    return 0;
}
