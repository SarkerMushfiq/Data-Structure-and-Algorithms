#include<iostream>
#include<vector>
using namespace std;

//do not work for negative numbers
int longestSubArray(vector<int>&arr,int k){
    int left=0,right=0,sum=0,maxLength=0;

    while(right<arr.size()){
        sum+=arr[right];

        while(sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLength=max(maxLength,right-left+1);
        }
        right++;
    }
    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 5, 2};
    int K = 5;
    cout << "Longest subarray length: " << longestSubArray(arr, K) << endl;
    return 0;
}
