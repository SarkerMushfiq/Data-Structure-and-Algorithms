#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to take tree input in Preorder manner
Node* takeInputRecursive() {
    int data;
    cout << "Enter node value (-1 for NULL): ";
    cin >> data;

    if (data == -1) return nullptr;

    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = takeInputRecursive();

    cout << "Enter right child of " << data << endl;
    root->right = takeInputRecursive();

    return root;
}

// Function to print inorder traversal (for verification)
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = takeInputRecursive();
    cout << "Inorder Traversal of the tree: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
