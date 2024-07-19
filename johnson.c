#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations of the array
void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            generatePermutations(arr, start + 1, end);
            swap(&arr[start], &arr[i]); // backtrack
        }
    }
}

// Main function to drive the program
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int)); // Allocate memory for the array
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    generatePermutations(arr, 0, n - 1); // Generate permutations
    free(arr); // Free allocated memory
    return 0;
}

/*
/tmp/gRLWKi3H1T.o
Enter the number of elements: 4
Enter the elements: 1 2 3 4
1 2 3 4 
1 2 4 3 
1 3 2 4 
1 3 4 2 
1 4 3 2 
1 4 2 3 
2 1 3 4 
2 1 4 3 
2 3 1 4 
2 3 4 1 
2 4 3 1 
2 4 1 3 
3 2 1 4 
3 2 4 1 
3 1 2 4 
3 1 4 2 
3 4 1 2 
3 4 2 1 
4 2 3 1 
4 2 1 3 
4 3 2 1 
4 3 1 2 
4 1 3 2 
4 1 2 3 


=== Code Execution Successful ===

*/
