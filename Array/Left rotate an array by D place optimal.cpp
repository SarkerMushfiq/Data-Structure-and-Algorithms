#include<iostream>
#include<vector>
using namespace std;

void Reverse(int arr[],int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[],int n,int d){
    d=d%n;
    Reverse(arr,0,d-1);
    Reverse(arr,d,n-1);
    Reverse(arr,0,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cout<<"Enter d: ";
    cin>>d;
    leftRotate(arr,n,d);
     for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
