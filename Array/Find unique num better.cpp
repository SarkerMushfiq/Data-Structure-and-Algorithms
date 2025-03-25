#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int>& arr) {
    int unique = 0; // Initialize with 0

    for (int num : arr) {
        unique ^= num; // XOR all numbers
    }

    return unique; // The remaining number is the unique one
}

int main() {
    vector<int> arr = {4, 3, 2, 4, 1, 3, 2}; // Unique number is 1
    cout << "Unique number: " << findUnique(arr) << endl;
    return 0;
}
