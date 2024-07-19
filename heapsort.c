#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to heapify a subtree rooted with node i which is an index in arr[]. n is the size of the heap.
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap arr[i] with arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    clock_t start, end;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Fill the array with random numbers
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    heapSort(arr, n);
    end = clock();

    printf("Sorted array:\n");
    printArray(arr, n);

    printf("\nTime taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
/*
/tmp/pJKd4LHF46.o
Enter the number of elements: 200
Unsorted array:
13 1 85 78 74 59 24 75 12 25 31 2 48 4 18 5 61 25 95 52 88 22 41 43 90 92 92 37 76 92 73 41 93 10 71 19 69 48 94 33 73 26 35 73 82 5 79 95 31 74 99 71 49 41 66 39 85 58 76 13 50 1 55 95 11 26 67 32 74 61 17 0 39 52 25 73 10 56 68 41 83 68 12 32 61 30 23 98 88 51 11 90 52 66 85 15 45 4 99 71 18 16 23 9 20 49 83 30 5 3 71 88 23 35 72 84 65 95 82 5 98 94 95 50 12 33 17 57 37 16 81 55 32 4 65 5 53 0 35 11 3 59 51 27 46 24 63 12 71 98 69 70 92 17 72 56 50 90 66 39 58 47 47 43 51 12 48 57 64 83 20 67 94 71 46 41 47 10 5 71 8 74 41 52 43 65 8 93 7 74 85 66 73 32 9 25 96 9 34 60 
Sorted array:
0 0 1 1 2 3 3 4 4 4 5 5 5 5 5 5 7 8 8 9 9 9 10 10 10 11 11 11 12 12 12 12 12 13 13 15 16 16 17 17 17 18 18 19 20 20 22 23 23 23 24 24 25 25 25 25 26 26 27 30 30 31 31 32 32 32 32 33 33 34 35 35 35 37 37 39 39 39 41 41 41 41 41 41 43 43 43 45 46 46 47 47 47 48 48 48 49 49 50 50 50 51 51 51 52 52 52 52 53 55 55 56 56 57 57 58 58 59 59 60 61 61 61 63 64 65 65 65 66 66 66 66 67 67 68 68 69 69 70 71 71 71 71 71 71 71 72 72 73 73 73 73 73 74 74 74 74 74 75 76 76 78 79 81 82 82 83 83 83 84 85 85 85 85 88 88 88 90 90 90 92 92 92 92 93 93 94 94 94 95 95 95 95 95 96 98 98 98 99 99 

Time taken: 0.000027 seconds


=== Code Execution Successful ===

*/
