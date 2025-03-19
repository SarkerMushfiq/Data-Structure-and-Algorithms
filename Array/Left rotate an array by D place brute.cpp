#include<iostream>
#include<vector>
using namespace std;

vector<int>rorateDplace(vector<int>&arr,int d,int n){
    d=d%n;

    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }

    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cout<<"Enter d: ";
    cin>>d;
    vector<int>newArray=rorateDplace(arr,d,n);
     for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
