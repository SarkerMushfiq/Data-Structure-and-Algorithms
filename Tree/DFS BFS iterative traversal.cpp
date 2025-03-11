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

void preOrder(Node* root){
    if(root==nullptr) return;

    stack<Node*>st;
    st.push(root);

    while(!st.empty()){
        Node* temp=st.top();
        st.pop();
        cout<<temp->data<<" ";

        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}

void inOrder(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    Node* temp=root;

    while(temp!=nullptr||!st.empty()){
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

void postOrder(Node* root){
    //two stack
    if(!root) return;
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node* temp=s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
  }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void PostOrder(Node* root){
    //using 1 stack---more optimized
    if(!root) return;
    stack<Node*>st;
    Node* lastvisited=nullptr;
    Node* temp=root;
    while(!st.empty()||temp){
        if(temp){
            st.push(temp);
            temp=temp->left;
        }
        else{
            Node* node=st.top();
            if(node->right&&node->right!=lastvisited){
                temp=node->right;
            }
            else{
                cout<<node->data<<" ";
                lastvisited=node;
                st.pop();
            }
        }
    }
}

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
    Node* root=buildSampleTree();
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    PostOrder(root);
    return 0;
}
