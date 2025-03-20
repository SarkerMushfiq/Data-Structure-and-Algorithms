#include<iostream>
#include<vector>
using namespace std;

int LinearSearch(vector<int>&arr,int num){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num){
            return 1;
            break;
        }
    }
    return 0;
}

int main(){
    vector<int>arr={1,3,5,7,9,2,4};
    int num;
    cin>>num;
    if(LinearSearch(arr,num)){
        cout<<"Num found!";
    }
    else{
        cout<<"Num not found!";
    }
    return 0;
}
