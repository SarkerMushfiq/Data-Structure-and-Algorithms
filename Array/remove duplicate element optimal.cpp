#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicate(vector<int>&arr){
    if(arr.size()==0) return 0;

    int j=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[j]){
            j++;
            arr[j]=arr[i];
        }
    }
    return j+1;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 6, 6};
    sort(arr.begin(), arr.end()); // Ensure array is sorted first

    int newSize = removeDuplicate(arr);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
