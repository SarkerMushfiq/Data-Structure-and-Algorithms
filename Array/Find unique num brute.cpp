#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        bool isUnique = true;

        // Check if arr[i] appears again in the array
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;  // No need to check further
            }
        }

        if (isUnique) return arr[i]; // Found unique number
    }

    return -1; // In case no unique number is found (shouldn't happen)
}

int main() {
    vector<int> arr = {4, 3, 2, 4, 1, 3, 2}; // Unique number is 1
    cout << "Unique number: " << findUnique(arr) << endl;
    return 0;
}
