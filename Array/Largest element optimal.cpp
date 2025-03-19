#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int>&arr){
    int max_val=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max_val)
            max_val=arr[i];
    }
    return max_val;
}


int main(){
    vector<int>arr={10,5,20,8,15};
    cout<<"Largest element: "<<largestElement(arr)<<endl;
    return 0;
}
