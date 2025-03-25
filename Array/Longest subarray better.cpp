#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubArray(vector<int>&arr,int k){
    unordered_map<int,int>prefixSumIndex;
    int maxLength=0,prefixSum=0;

    for(int i=0;i<arr.size();i++){
        prefixSum+=arr[i];

        if(prefixSum==k){
            maxLength=i+1;
        }
        if(prefixSumIndex.find(prefixSum-k)!=prefixSumIndex.end()){
            maxLength=max(maxLength,i-prefixSumIndex[prefixSum-k]);
        }
        if(prefixSumIndex.find(prefixSum)==prefixSumIndex.end()){
            prefixSumIndex[prefixSum]=i;
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
