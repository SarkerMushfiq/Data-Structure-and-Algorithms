#include <iostream>
#include <vector>
using namespace std;
int findMissingNumbers(vector<int>& arr, int n) {
    vector<bool> hash(n + 1, false);

    // Mark numbers that exist in the array
    for (int num : arr) {
        hash[num] = true;
    }

    // Find missing numbers
    for (int i = 1; i <= n; i++) {
        if (!hash[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 2, 4,5,6, 7, 8};  // Missing: 3, 5, 6
    int n = 8; // Expected range is from 1 to 8

    int missingNumber = findMissingNumbers(arr, n);

    cout << "Missing numbers: ";
    cout<<missingNumber;
    return 0;
}
