#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to insert a node into BST iteratively
Node* insertBST(Node* root, int val) {
    Node* newNode = new Node(val);
    if (!root) return newNode;

    Node* curr = root;
    Node* parent = NULL;

    while (curr) {
        parent = curr;
        if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Iteratively construct BST by inserting elements one by one
Node* bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty()) return NULL;
    Node* root = NULL;

    for (int val : preorder) {
        root = insertBST(root, val);  // Insert elements iteratively
    }

    return root;
}

// Inorder traversal to verify BST structure
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
