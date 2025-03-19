#include<iostream>
#include<vector>
using namespace std;

vector<int>rotateArray(vector<int>&arr){
    int temp=arr[0];
    for(int i=1;i<arr.size();i++){
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    vector<int>newArray=rotateArray(arr);

    for(int i=0;i<arr.size();i++){
        cout<<newArray[i]<<" ";
    }
    return 0;
}
