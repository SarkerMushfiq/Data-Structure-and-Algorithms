#include<iostream>
#include<vector>
using namespace std;

vector<int>removeDuplicate(vector<int>&arr){
    vector<int>temp;
    for(int i=0;i<arr.size();i++){
        bool isDuplicate=false;
        for(int j=0;j<temp.size();j++){
            if(arr[i]==temp[j]){
                isDuplicate=true;
                break;
            }
        }
        if(!isDuplicate){
            temp.push_back(arr[i]);
        }
    }
    return temp;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 6, 6};
    vector<int> result = removeDuplicate(arr);

    cout << "Array after removing duplicates: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
