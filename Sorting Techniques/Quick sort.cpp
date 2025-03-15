#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<=high-1){
            i++;
        }
        while(arr[j]>pivot&&j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(vector<int>&arr,int low,int high){
    if(low<high){
        int pivot=Partition(arr,low,high);
        QuickSort(arr,low,pivot-1);
        QuickSort(arr,pivot+1,high);
    }
}

void qs(vector<int>&arr,int n){
    QuickSort(arr,0,n-1);
}

void printArray(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    printArray(arr,n);
    cout<<endl;
    qs(arr,n);
    cout<<"Sorted array: ";
    printArray(arr,n);

    return 0;
}
