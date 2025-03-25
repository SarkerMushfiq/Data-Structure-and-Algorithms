#include<iostream>
#include<vector>
using namespace std;

vector<int>MissingNumber(vector<int>&arr,int n){
    vector<int>missing;
    for(int i=1;i<n;i++){
         bool found=false;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==i){
                found=true;
                break;
            }
        }
        if(!found){
            missing.push_back(i);
        }
    }
    return missing;
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 8};  // Missing: 3, 5, 6
    int n = 8; // Expected range is from 1 to 8

    vector<int> missingNumbers =MissingNumber(arr, n);

    cout << "Missing numbers: ";
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
