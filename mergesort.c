#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two sorted subarrays
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int n = high - low + 1;  // Size of the temporary array
    int* c = (int*)malloc(n * sizeof(int));
    
    // Merge the two halves into temporary array c
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }
    
    // Copy remaining elements of the left half, if any
    while (i <= mid) {
        c[k++] = a[i++];
    }
    
    // Copy remaining elements of the right half, if any
    while (j <= high) {
        c[k++] = a[j++];
    }
    
    // Copy the sorted elements from c back to a
    for (k = 0, i = low; i <= high; i++, k++) {
        a[i] = c[k];
    }
    
    // Free the temporary array
    free(c);
}

// Function to sort array using merge sort
void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    clock_t start, end;
    int n;
    
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Get the array elements from user input
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    start = clock();
    mergesort(arr, 0, n - 1);
    end = clock();
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    free(arr);
    return 0;
}
