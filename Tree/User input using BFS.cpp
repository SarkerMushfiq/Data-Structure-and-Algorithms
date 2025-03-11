#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data1):data(data1),left(nullptr),right(nullptr){}
};

Node* takeInputBFS(){
    int rootdata;
    cout<<"Enter root data(-1 for NULL): ";
    cin>>rootdata;

    if(rootdata==-1) return nullptr;

    Node* root=new Node(rootdata);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        int leftdata,rightdata;
        cout<<"Enter left child of "<<temp->data<<"(-1 for NULL): ";
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right child of "<<temp->data<<"(-1 for NULL): ";
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}

void inOrder(Node* root){
    if(root==nullptr) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    Node* root=takeInputBFS();
    cout<<"Inorder traversal of the tree: ";
    inOrder(root);
    cout<<endl;
    return 0;
}
