#include <iostream>
using namespace std;


void heapify(int arr[], int n) {
    // Your code here
    // Build the heap

    // Start at second element because root does not have a parent
    for(int i = 1; i < n; i++) {
        int currentIndex = i;
        while(true) {
            int parentIndex = (currentIndex - 1) / 2;
            int parent = arr[parentIndex];
            int child = arr[currentIndex];

            // No need to swap if parent < child
            if(parent > child)  {
                arr[parentIndex] = child;
                arr[currentIndex] = parent;
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }
}

// Main function to perform heap sort on the array
void heapSort(int arr[], int n) {
    // Step 1: Build a min-heap
    heapify(arr, n);

    int temp[n];
    int originalSize = n;
    while(n > 0) {
        // Step 2: Extract elements from the heap one by one
        temp[originalSize - n] = arr[0]; // Populate temp[] 1 by 1 with heap's new roots

        int tempSwapVar = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = tempSwapVar;
        n--;

        // Step 3: Down Heapify
        int currentIndex = 0;
        while(true) {
            int indexOfSmallest = currentIndex;
            int lChildIndex = currentIndex * 2 + 1;
            int rChildIndex = currentIndex * 2 + 2;

            // Find the smallest
            if(lChildIndex < n && arr[lChildIndex] < arr[indexOfSmallest])
                indexOfSmallest = lChildIndex;
            if(rChildIndex < n && arr[rChildIndex] < arr[indexOfSmallest])
                indexOfSmallest = rChildIndex;

            // Swap the parent with smallest
            if(indexOfSmallest != currentIndex) {
                int tempSwapVar2 = arr[currentIndex];
                arr[currentIndex] = arr[indexOfSmallest];
                arr[indexOfSmallest] = tempSwapVar2;
                currentIndex = indexOfSmallest; // Keep checking if swapped element's new children > swapped element
            } else {
                break; // Stop checking if no swap was needed
            }
        }
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