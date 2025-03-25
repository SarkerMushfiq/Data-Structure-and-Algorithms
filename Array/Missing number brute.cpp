#include<iostream>
#include<vector>
using namespace std;

int MissingNumber(vector<int>&arr,int n){
    for(int i=1;i<n;i++){
         bool found=false;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                found=true;
                break;
            }
        }
        if(!found) return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};  // N = 5, Missing = 3
    int n = 5; // Expected range is from 1 to 5

    cout << "Missing number: " << MissingNumber(arr, n) << endl;
    return 0;
}
