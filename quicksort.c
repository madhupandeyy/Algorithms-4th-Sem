#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using only while loops
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high + 1;

    while (1) {
        // Move i to the right as long as arr[i] <= pivot
        while (arr[++i] <= pivot && i <= high);

        // Move j to the left as long as arr[j] > pivot
        while (arr[--j] > pivot && j >= low);

        if (i >= j) break;

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

// Main function
int main() {
    clock_t start, end;
    int n;

    // Prompt user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = malloc(n * sizeof(int));

    // Prompt user for the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();

    // Output sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr); // Free allocated memory
    return 0;
}


/*
/tmp/Pdr56IYvGb.o
Enter the number of elements: 8
Enter 8 elements:
Element 1: 19
Element 2: 32
Element 3: 18
Element 4: 24
Element 5: 30
Element 6: 12
Element 7: 28
Element 8: 14
Sorted array:
12 14 18 19 24 28 30 32 
Time taken: 0.000002 seconds


=== Code Execution Successful ===

*/
