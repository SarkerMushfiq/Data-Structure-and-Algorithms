#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Iterative function to find max depth
int maxDepth(Node* root) {
    if (root == nullptr) return 0;

    queue<Node*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int size = q.size();
        depth++; // Increment depth for each level

        while (size--) {
            Node* node = q.front();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Max Depth: " << maxDepth(root) << endl;
    return 0;
}
