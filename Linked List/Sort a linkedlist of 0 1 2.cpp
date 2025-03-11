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
        Node* temp=new Node(arr[i],nullptr);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* sort012(Node* head){
    //traverse 2 times
   Node* temp=head;
  int cnt0=0,cnt1=0,cnt2=0;
  while(temp){
   if(temp->data==0) cnt0++;
   else if(temp->data==1) cnt1++;
   else if(temp->data==2) cnt2++;
   temp=temp->next;
  }
  temp=head;
  while(temp){
    if(cnt0){
        temp->data=0;
        cnt0--;
    }
    else if(cnt1){
        temp->data=1;
        cnt1--;
    }
    else{
        temp->data=2;
        cnt2--;
    }
    temp=temp->next;
  }
  return head;
}

Node* Sort012(Node* head){
    //traverse 1 time
    if(head==nullptr||head->next==nullptr) return head;
    Node* zerohead=new Node(-1);
    Node* onehead=new Node(-1);
    Node* twohead=new Node(-1);
    Node* zero=zerohead;
    Node* one=onehead;
    Node* two=twohead;
    Node* temp=head;
    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else if(temp->data==2){
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(onehead->next)? onehead->next:twohead->next;
    one->next=twohead->next;
    two->next=nullptr;
    Node* newhead=zerohead->next;
    free(zerohead);
    free(onehead);
    free(twohead);
    return newhead;
}

int main(){
    vector<int>arr={1,1,2,1,2,1};
    Node* head=convert2LL(arr);
    head=Sort012(head);
    print(head);

    return 0;
}
