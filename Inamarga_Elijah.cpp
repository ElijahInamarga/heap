#include <iostream>
using namespace std;

void heapify(int arr[], int n) {
    // Your code here
    // Build the heap
    for(int i = 0; i < n; i++) {
        int current = i;
        int parent = (current - 1) / 2;
        while(current != 0 && arr[current] < arr[parent]) {
            swap(arr[current], arr[parent]);
            current = parent;
            parent = (current - 1) / 2;
        }
    }
}

// Main function to perform heap sort on the array
void heapSort(int arr[], int n) {
    // Step 1: Build a min-heap
    heapify(arr, n);

    const int originalSize = n;
    int temp[originalSize];

    while(n > 0) {
        // Step 2: Extract elements from the heap one by one
        temp[originalSize - n] = arr[0];

        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        n--;

        // Step 3: Down Heapify
        int current = 0;
        int original;
        do {
            original = current;
            int smallest = original;
            int lChild = current * 2 + 1;
            int rChild = current * 2 + 2;

            // Find the smallest
            if(lChild < n && arr[lChild] < arr[smallest])
                smallest = lChild;
            if(rChild < n && arr[rChild] < arr[smallest])
                smallest = rChild;

            if(smallest != current) {
                int temp = arr[current];
                arr[current] = arr[smallest];
                arr[smallest] = temp;
                current = smallest;
            }
        } while(current != original);
    }

    // Copy temp back to array
    for(int i = 0; i < originalSize; i++)
        arr[i] = temp[i];
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
