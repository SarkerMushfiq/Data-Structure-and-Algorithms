#include<iostream>
using namespace std;

void recursiveInsertionSort(int arr[], int n) {
    // Base case: If array size is 1, return
    if (n <= 1) return;

    // Recursively sort first (n-1) elements
    recursiveInsertionSort(arr, n - 1);

    // Insert the last element at its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements to the right to create space
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n);
    cout << endl;

    recursiveInsertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
