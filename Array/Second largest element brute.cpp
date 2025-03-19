#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SecondLargest(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int largest=arr[arr.size()-1];
    int second_largest=-1;
    for(int i=arr.size()-2;i>=00;i--){
        if(arr[i]!=largest)
            second_largest=arr[i];
            break;
    }
    return second_largest;
}

int main(){
    vector<int>arr={10,20,90,35,87,1,45,99};
    cout<<"Second largest num: "<<SecondLargest(arr)<<endl;
    return 0;
}
