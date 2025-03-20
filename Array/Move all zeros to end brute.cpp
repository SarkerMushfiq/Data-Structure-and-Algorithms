#include<iostream>
#include<vector>
using namespace std;

vector<int>MoveZeros(vector<int>&arr){
    vector<int>temp;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0)
            temp.push_back(arr[i]);
    }
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    int non_zero=temp.size();
    for(int i=non_zero;i<arr.size();i++){
        arr[i]=0;
    }
    return arr;
}

int main(){
    vector<int>arr={1,0,2,3,2,0,0,4,5,1};
    vector<int>newArray=MoveZeros(arr);
    for(int num:arr){
        cout<<num<<" ";
    }
    return 0;
}
