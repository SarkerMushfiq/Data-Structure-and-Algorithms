#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    public:
        Node(int data1,Node* next1){
            data=data1;
            next=next1;
        }
         public:
        Node(int data1){
            data=data1;
            next=nullptr;
        }
};

Node* convertArr2LL(vector<int>arr){
    Node* head=new Node(arr[0]);
   Node* mover=head;
   for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover=temp;
   }
   return head;
}

int lengthofLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int checkifPresent(Node* head, int val){
   Node* temp=head;
   while(temp){
    if(temp->data==val) return 1;
    temp=temp->next;
   }
   return 0;
}

Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL||head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}

Node* deleteKthPosition(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteValue(Node* head,int val){
    if(head==NULL) return head;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* insertHead(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
}

Node* insertTail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;

    return head;
}

Node* insertK(Node* head,int val,int k){
    if(head==NULL){
       if(k==1) return new Node(val);
    }
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head,int el,int val){
    if(head==NULL){
       return NULL;
    }
    if(head->data==val){
        Node* temp=new Node(el,head);
        return temp;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* newNode=new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* Addition2LL(Node* head1,Node* head2){
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
    if(!head||!head->next) return head;
    vector<int>arr={};
    Node* temp=head;
    while(temp!=nullptr&&temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp=head->next;
    while(temp!=nullptr&&temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    if(temp) arr.push_back(temp->data);
    int i=0;
    temp=head;
    while(temp!=nullptr){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
}


Node* ArrangeOddEven(Node* head){
    //no extra array
    if(head==nullptr||head->next==nullptr) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=even;
    while(even&&even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

//funtion to find middle node
Node* getMiddle(Node* head){
    if(!head||!head->next) return head;
    Node *slow=head,*fast=head->next;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//funtion to merge two sorted lists
Node* mergeSortedList(Node* left,Node* right){
    if(!left) return right;
    if(!right) return left;

    Node* result;
    if(left->data<=right->data){
        result=left;
        result->next=mergeSortedList(left->next,right);
    }
    else{
        result=right;
        result->next=mergeSortedList(left,right->next);
    }
    return result;
}

//mergesort function
Node* mergeSort(Node* head){
    if(!head||!head->next) return head;
    Node* middle=getMiddle(head);
    Node* nextToMiddle=middle->next;
    middle->next=nullptr;

    Node* left=mergeSort(head);
    Node* right=mergeSort(nextToMiddle);

    return mergeSortedList(left,right);
}

int main(){
    vector<int>arr1={10,90,58,32,82,13,51,24,1,5,6,11};
    Node* head=convertArr2LL(arr1);
    head=mergeSort(head);
    print(head);
    return 0;
}
