#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largestElement(vector<int>&arr){
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
int main(){
    vector<int>arr={10,5,20,8,25};
    cout<<"Largest element: "<<largestElement(arr)<<endl;
    return 0;
}

