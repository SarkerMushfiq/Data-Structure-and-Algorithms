#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();

    // Find the maximum value in the array
    int maxElement = *max_element(arr.begin(), arr.end());

    // Create a count array of size (maxElement + 1) and initialize to 0
    vector<int> count(maxElement + 1, 0);

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Compute prefix sum (cumulative sum)
    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store sorted elements
    vector<int> output(n);

    // Place elements in sorted order (traverse original array in reverse to maintain stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr);

    countingSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
