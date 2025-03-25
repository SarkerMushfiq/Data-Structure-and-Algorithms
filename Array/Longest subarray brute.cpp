#include<iostream>
#include<vector>
using namespace std;

int longestSubArray(vector<int>&arr,int k){
    int n=arr.size();
    int maxLength=0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                maxLength=max(maxLength,j-i+1);
            }
        }
    }
    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 5, 2};
    int K = 5;
    cout << "Longest subarray length: " << longestSubArray(arr, K) << endl;
    return 0;
}
