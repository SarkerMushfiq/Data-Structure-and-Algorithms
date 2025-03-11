#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* previous;
public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        previous=prev1;
    }
public:
    Node(int data1){
        data=data1;
        next=nullptr;
        previous=nullptr;
    }
};
Node* convert2DLL(vector<int>&arr){
    if(arr.empty()){
        return nullptr;
    }
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* deleteHead(Node* head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }
    Node* prev=head;
    head=head->next;
    head->previous=nullptr;
    prev->next=nullptr;
    delete(prev);
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->previous;
    temp->previous=nullptr;
    prev->next=nullptr;
    delete(temp);
    return head;
}

Node* deleteKelement(Node* head,int k){
    if(head==nullptr){
        return nullptr;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->previous;
    Node* frontt=temp->next;
    if(prev==nullptr&&frontt==nullptr){
        return nullptr;
    }
    else if(prev==nullptr){
        return deleteHead(head);
    }
    else if(frontt==nullptr){
        return deleteTail(head);
    }
    prev->next=frontt;
    frontt->previous=prev;

    temp->next=nullptr;
    temp->previous=nullptr;
    delete(temp);
    return head;
}

Node* deleteNode(Node* head,int el){
    if(head==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp!=nullptr&&temp->data!=el){
        temp=temp->next;
    }
    if(temp==nullptr) return head;
    Node* prev=temp->previous;
    Node* frontt=temp->next;
   if (prev == nullptr && frontt == nullptr) {
        delete temp;
        return nullptr;  // List becomes empty
    }

    // Case 2: Deleting the head node
    if (prev == nullptr) {
        head = frontt;  // Move head forward
        head->previous = nullptr;  // New head should not have a previous node
    }
    // Case 3: Deleting the tail node
    else if (frontt == nullptr) {
        prev->next = nullptr;  // Remove the link to the last node
    }
    // Case 4: Deleting a middle node
    else {
        prev->next = frontt;
        frontt->previous = prev;
    }

    delete temp; // Free memory
    return head;
}

Node* insertBeforeHead(Node* head,int val){
    Node* newhead=new Node(val,head,nullptr);
    head->previous=newhead;
    return newhead;
}

Node* insertAfterHead(Node* head,int val){
    Node* frontt=head->next;
    Node* newhead=new Node(val,frontt,head);
    head->next=newhead;
    frontt->previous=newhead;
    return head;
}

Node* insertBeforeTail(Node* head,int val){
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->previous;
    Node*newtail=new Node(val,temp,prev);
    prev->next=newtail;
    temp->previous=newtail;
    return head;
}

Node* insertAfterTail(Node* head,int val){
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->previous;
    Node* newtail=new Node(val,nullptr,temp);
    temp->next=newtail;
    return head;
}

Node* insertBeforeKposition(Node* head,int val,int k){
    if(head==nullptr){
        return new Node(val);
    }
    if(k==1){
       return insertBeforeHead(head,val);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->previous;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->previous=newNode;
    return head;
}

Node* insertAfterKposition(Node* head,int val,int k){
    if(head==nullptr) return new Node(val);
    if(k==1) return insertAfterHead(head,val);
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* frontt=temp->next;
    Node* newNode=new Node(val,frontt,temp);
    temp->next=newNode;
    frontt->previous=newNode;
    return head;
}

Node* insertBeforeNode(Node* head,int val,int el){
    if(head==nullptr) return new Node(val);
    Node* temp=head;
    while(temp!=nullptr&&temp->data!=el){
        temp=temp->next;
    }
    if(temp==nullptr) return head;
    Node* prev=temp->previous;
    Node* frontt=temp->next;
    if(prev==nullptr&&frontt==nullptr){
        Node* newNode=new Node(val,temp,nullptr);
        temp->previous=newNode;
        return newNode;
    }
    else if(prev==nullptr){
        return insertBeforeHead(head,val);
    }
    else if(frontt==nullptr){
        return insertBeforeTail(head,val);
    }
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->previous=newNode;
    return head;
}

Node* insertAfterNode(Node* head,int val,int el){
    if(head==nullptr) return new Node(val);
    Node* temp=head;
    while(temp!=nullptr&&temp->data!=el){
        temp=temp->next;
    }
    if(temp==nullptr) return head;
    Node* prev=temp->previous;
    Node* frontt=temp->next;
    if(prev==nullptr&&frontt==nullptr){
        Node* newNode=new Node(val,nullptr,temp);
        temp->next=newNode;
        return head;
    }
    else if(prev==nullptr){
        return insertAfterHead(head,val);
    }
    else if(frontt==nullptr){
        return insertAfterTail(head,val);
    }
    Node* newNode=new Node(val,frontt,temp);
    frontt->previous=newNode;
    temp->next=newNode;
    return head;
}

Node* reverseDDL(Node* head){
    /*using stack*/
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    stack<Node*>s;
    Node* temp=head;
    while(temp!=nullptr){
        s.push(temp);
        temp=temp->next;
    }
    head=s.top();
    s.pop();
    Node* curr=head;
    while(!s.empty()){
        curr->next=s.top();
        s.top()->previous=curr;
        curr=s.top();
        s.pop();
    }
    curr->next=nullptr;
    return head;
}

Node* ReverseDDL(Node* head){
    /*only 1 traversal*/
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    Node* prev=nullptr;
    Node* temp=head;
    while(temp!=nullptr){
        prev=temp->previous;
        temp->previous=temp->next;
        temp->next=prev;
        temp=temp->previous;
    }
    return prev->previous;
}

Node* Addition2DDL(Node* head1,Node* head2){
    Node* dummyhead=new Node(-1);
    Node* curr=dummyhead;
    Node* temp1=head1;
    Node* temp2=head2;
    int carry=0;
    while(temp1!=nullptr||temp2!=nullptr){
        int sum= carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;
        Node* newNode=new Node(sum%10);
        carry=sum/10;

        curr->next=newNode;
        curr=curr->next;

        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    if(carry){
        Node* newNode=new Node(carry);
        curr->next=newNode;
    }
    return dummyhead->next;
}

Node* arrangeOddEven(Node* head){
  //using vector
  if(head==nullptr||head->next==nullptr) return head;
  vector<Node*>nodes;
  Node* temp=head;
  //store in a array
  while(temp){
    nodes.push_back(temp);
    temp=temp->next;
  }
  //split into odd and even
  vector<Node*>oddNodes,evenNodes;
  for(int i=0;i<nodes.size();i++){
    if((i+1)%2!=0) oddNodes.push_back(nodes[i]);
    else evenNodes.push_back(nodes[i]);
  }
  //merge odd and even in oder
  vector<Node*>newOder;
  newOder.insert(newOder.end(),oddNodes.begin(),oddNodes.end());
  newOder.insert(newOder.end(),evenNodes.begin(),evenNodes.end());
  //reconstruct the dll
  for(int i=0;i<newOder.size();i++){
    newOder[i]->next=(i+1<newOder.size())?newOder[i+1]:nullptr;
    newOder[i]->previous=(i-1>=0)?newOder[i-1]:nullptr;
  }
  return newOder[0];
}

Node* ArrangeOddEven(Node* head){
    //no extra array
    if(head==nullptr||head->next==nullptr) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=even;
    while(even!=nullptr&&even->next!=nullptr){
        odd->next=odd->next->next;
        odd->next->previous=odd;
        odd=odd->next;

        even->next=even->next->next;
        if(even->next) even->next->previous=even;
        even=even->next;
    }
    odd->next=evenHead;
    if(evenHead) evenHead->previous=odd;
    return head;
}

int getUserInput(string message) {
    int val;
    cout << message;
    cin >> val;
    return val;
}

// Function to perform the operation
Node* performOperation(Node* head, int choice) {
    int val, k, el;

    switch (choice) {
        case 1: return deleteHead(head);
        case 2: return deleteTail(head);
        case 3:
            k = getUserInput("Enter kth position: ");
            return deleteKelement(head, k);
        case 4:
            el = getUserInput("Enter any element present in the list: ");
            return deleteNode(head, el);
        case 5:
            val = getUserInput("Enter the value: ");
            return insertBeforeHead(head, val);
        case 6:
            val = getUserInput("Enter the value: ");
            return insertAfterHead(head, val);
        case 7:
            val = getUserInput("Enter the value: ");
            return insertBeforeTail(head, val);
        case 8:
            val = getUserInput("Enter the value: ");
            return insertAfterTail(head, val);
        case 9:
            val = getUserInput("Enter the value: ");
            k = getUserInput("Enter the Kth position: ");
            return insertBeforeKposition(head, val, k);
        case 10:
            val = getUserInput("Enter the value: ");
            k = getUserInput("Enter the Kth position: ");
            return insertAfterKposition(head, val, k);
        case 11:
            val = getUserInput("Enter the value: ");
            el = getUserInput("Enter any element on the list: ");
            return insertBeforeNode(head, val, el);
        case 12:
            val = getUserInput("Enter the value: ");
            el = getUserInput("Enter any element on the list: ");
            return insertAfterNode(head, val, el);
        case 13: return ReverseDDL(head);
        case 14:{
            int m=getUserInput("Enter the number of elements for the second list: ");
            vector<int>arr2(m);
            cout<<"Enter the elements: ";
            for(int &x : arr2) cin>>x;
            Node* head2=convert2DLL(arr2);
            cout<<"Second list: ";
            print(head2);
            cout<<endl;

            return Addition2DDL(head,head2);
        }
        case 15: return ArrangeOddEven(head);
        default:
            cout << "Invalid choice!\n";
            return head;
    }
}

int main() {
    int n = getUserInput("Enter the number of elements: ");

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int &x : arr) cin >> x;

    Node* head = convert2DLL(arr);
    cout << "The list is: ";
    print(head);
    cout << endl;

    cout << "Choose any operation below:\n";
    cout << "1. Delete head of the list\n"
         << "2. Delete tail of the list\n"
         << "3. Delete Kth element of the list\n"
         << "4. Delete any element of the list\n"
         << "5. Insert before head of the list\n"
         << "6. Insert after head of the list\n"
         << "7. Insert before tail of the list\n"
         << "8. Insert after tail of the list\n"
         << "9. Insert before Kth element of the list\n"
         << "10. Insert after Kth element of the list\n"
         << "11. Insert a node before any element of the list\n"
         << "12. Insert a node after any element of the list\n"
         << "13. Reverse the list\n"
         << "14.Add tow linkedlist\n"
         << "15.Arrange the list odd then even node\n";

    int choice = getUserInput("Enter choice: ");
    head = performOperation(head, choice);

    cout << "The new list is: ";
    print(head);
    cout << endl;

    return 0;
}
