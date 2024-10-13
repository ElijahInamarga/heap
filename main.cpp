#include <iostream>
using namespace std;

void heapify(int arr[], int n) {
    // Your code here
    int i = n / 2 - 1; // Initialize with largest internal node
    // Build the heap
    while(i >= 0) {
        int smallest = i;
        int lChild = i * 2 + 1;
        int rChild = i * 2 + 2;

        // Find the smallest
        if(lChild < n && arr[lChild] < arr[smallest])
            smallest = lChild;
        if(rChild < n && arr[rChild] < arr[smallest])
            smallest = rChild;

        // Swap smallest with parent
        if(smallest != i) {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            i = smallest;
        } else {
            i--;
        }
    }
}

// Main function to perform heap sort on the array
void heapSort(int arr[], int n) {
    // Step 1: Build a min-heap
    heapify(arr, n);
    int size = n;

    while(n > 0) {
        // Step 2: Extract elements from the heap one by one
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        n--;

        // Step 3: Down Heapify
        int i = 0;
        while(true) {
            int smallest = i;
            int lChild = i * 2 + 1;
            int rChild = i * 2 + 2;

            if(lChild < n && arr[lChild] < arr[smallest]) {
                smallest = lChild;
            }
            if(rChild < n && arr[rChild] < arr[smallest]) {
                smallest = rChild;
            }

            if(smallest != i) {
                int temp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = temp;
                i = smallest;
            } else {
                break;
            }
        }
    }

    /* Using a min-heap, swapping the root with the last leaf sorts the array in descending order
     * Reversing the sorted array is necessary to get an ascending array
     */
    int  j = size - 1;
    for(int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test array
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    // Call the heapSort function
    heapSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}