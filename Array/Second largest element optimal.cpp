#include<iostream>
#include<vector>
using namespace std;

int SecondLargest(vector<int>&arr){
    int largest=arr[0],second_largest=-1;


    for(int i=0;i<arr.size();i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]>second_largest&&arr[i]!=largest){
            second_largest=arr[i];
        }
    }
    return second_largest;
}

int main() {
    vector<int> arr = {10, 20, 90, 35, 87, 1, 45, 99};
    cout << "Second largest number: " << SecondLargest(arr) << endl;
    return 0;
}
