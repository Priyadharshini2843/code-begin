#include <iostream>
using namespace std;

// Function to sort array of 0s, 1s and 2s
void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    // Using Dutch National Flag Algorithm
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {2, 0, 2, 1, 1, 0, 2, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    sort012(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}