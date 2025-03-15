#include<iostream>
using namespace std;

//preserves the relative order of eqal elements

void bubbleSort(int arr[],int n){
    for(int i=n-1;i>=0;i--){
            swapped=false;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                swapped=true;
            }
        }
        if(!swapped) break;
    }
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
    bubbleSort(arr,n);
    cout<<"Sorted array: ";
    printArray(arr,n);

    return 0;
}
