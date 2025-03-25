#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingNumbers(vector<int>& arr, int n) {
    vector<bool> hash(n + 1, false);
    vector<int> missing;

    // Mark numbers that exist in the array
    for (int num : arr) {
        hash[num] = true;
    }

    // Find missing numbers
    for (int i = 1; i <= n; i++) {
        if (!hash[i]) {
            missing.push_back(i);
        }
    }

    return missing;
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 8};  // Missing: 3, 5, 6
    int n = 8; // Expected range is from 1 to 8

    vector<int> missingNumbers = findMissingNumbers(arr, n);

    cout << "Missing numbers: ";
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
