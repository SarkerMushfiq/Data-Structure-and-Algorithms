#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

class BSTiterator{
    stack<Node*>st;
    void pushleft(Node* node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
public:
    BSTiterator(Node* root){
        pushleft(root);
    }

    int next(){
        if(!hasnext())return -1;

        Node* topNode=st.top();
        st.pop();

        if(topNode->right){
            pushleft(topNode->right);
        }
        return topNode->data;
    }

    bool hasnext(){
        return !st.empty();
    }
};

int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTiterator iterator(root);
    while (iterator.hasnext()) {
        cout << iterator.next() << " ";
    }
    return 0;
}
