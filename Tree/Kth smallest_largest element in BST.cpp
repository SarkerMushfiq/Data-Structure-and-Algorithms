#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};
//morris traversal
int KthSmallest(Node* root,int k){
    int cnt=0;
    int result=-1;
    Node* current=root;

    while(current!=nullptr){
        if(current->left==nullptr){
            cnt++;
            if(cnt==k) result=current->data;
            current=current->right;
        }
        else{
            Node* temp=current->left;
            while(temp->right&&temp->right!=current){
                temp=temp->right;
            }
            if (temp->right == nullptr) {
                temp->right = current;
                current = current->left;
            } else {
                temp->right = nullptr;
                cnt++;
                if (cnt == k) result = current->data;
                current = current->right;
            }
        }
    }
    return result;
}

int KthLargest(Node* root,int k){
    int cnt=0;
    int result=-1;
    Node* current=root;

    while(current){
        if(current->right==nullptr){
            cnt++;
            if(cnt==k) result=current->data;
            current=current->left;
        }
        else{
            Node* succ=current->right;
            while(succ->left&&succ->left!=current){
                succ=succ->left;
            }
            if(succ->left==nullptr){
            succ->left=current;
            current=current->right;
        }
        else{
            succ->left=nullptr;
            cnt++;
            if(cnt==k) result=current->data;
            current=current->left;
        }
        }
    }
    return result;
}

// Insert function
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Driver Code
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int k = 3;
    cout << k << "-th Smallest Element: " << KthSmallest(root, k) << endl;

    cout<<k<<"-th largest element: "<<KthLargest(root,k)<<endl;
    return 0;
}

