#include<iostream>
#include<vector>
using namespace std;

void Merge(int arr[],int low,int mid,int high){
    vector<int>temp;

    int left=low;
    int right=mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
       temp.push_back(arr[left]);
            left++;
    }
    while(right<=high){
         temp.push_back(arr[right]);
            right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void MergeSort(int arr[],int low,int high){
    if(low==high) return;

    int mid=(low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

void mergeSort(int arr[],int n){
    MergeSort(arr,0,n-1);
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    printArray(arr,n);
    cout<<endl;
    mergeSort(arr,n);
    cout<<"Sorted array: ";
    printArray(arr,n);

    return 0;
}
