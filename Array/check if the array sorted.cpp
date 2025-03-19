#include<iostream>
#include<vector>
using namespace std;

bool ifSorted(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<int>arr={1,2,3,4,6,5};
    if(ifSorted(arr)){
        cout<<"Array is sorted";
    }
    else{
        cout<<"Array is not sorted!";
    }
    return 0;
}
