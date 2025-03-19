#include<iostream>
#include<vector>
using namespace std;

int SecondLargest(vector<int>&arr){
    int largest=arr[0];
    for(int num:arr){
        if(num>largest)
            largest=num;
    }
    int second_largest=-1;
    for(int num:arr){
        if(num>second_largest&&num<largest)
            second_largest=num;
    }
    return second_largest;
}

int main() {
    vector<int> arr = {10, 20, 90, 35, 87, 1, 45, 99};
    cout << "Second largest number: " << SecondLargest(arr) << endl;
    return 0;
}
