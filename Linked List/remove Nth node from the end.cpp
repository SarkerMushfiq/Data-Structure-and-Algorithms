#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convert2LL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* deleteKthFromEnd(Node* head,int n){
    //brute force -----besi time complexity
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    if(cnt==n){
        Node* newHead=head->next;
        delete(head);
        return newHead;
    }

    temp=head;
    for(int i=0;i<cnt-n-1;i++){
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    free(deleteNode);
    return head;
}

Node* DeleteKthFromEnd(Node* head,int n){
    //optimal
    Node* fast=head;
    Node* slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==nullptr) return head->next;
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    Node* deleteNode=slow->next;
    slow->next=slow->next->next;
    delete(deleteNode);
    return head;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=convert2LL(arr);
    head=DeleteKthFromEnd(head,2);
    print(head);

    return 0;
}
