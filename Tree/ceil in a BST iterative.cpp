#include <iostream>
using namespace std;

// Definition for a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find Ceil in BST
int findCeil(Node* root, int X) {
    int ceil = -1;  // Default if no ceil exists

    while (root) {
        if (root->data == X)
            return root->data;  // Found exact match

        if (root->data > X) {
            ceil = root->data;  // Possible ceil found
            root = root->left;  // Move left to find smaller valid ceil
        } else {
            root = root->right;  // Move right to find a larger value
        }
    }
    return ceil;
}

// Sample usage
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
