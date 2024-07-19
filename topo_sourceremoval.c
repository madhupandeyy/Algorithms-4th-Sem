#include <stdio.h>
#include <stdlib.h>

// Function to perform topological sorting using source removal algorithm
void topologicalSorting(int arr[10][10], int n) {
    // Arrays to keep the count of incoming edges, store the result, and simulate a stack
    int in[n], out[n], s[n], top = -1;
    int i, j, k = 0;

    // Initialize the in-degree array
    for (i = 0; i < n; i++) {
        in[i] = 0;
        for (j = 0; j < n; j++) {
            if (arr[j][i] == 1) {
                in[i]++;
            }
        }
    }

    while (1) {
        // Push all vertices with no incoming edges (in-degree 0) onto the stack
        for (i = 0; i < n; i++) {
            if (in[i] == 0) {
                s[++top] = i;
                in[i] = -1; // Mark this vertex as processed
            }
        }

        // If no vertices are left with in-degree 0, exit the loop
        if (top == -1) {
            break;
        }

        // Pop a vertex from the stack
        out[k] = s[top--];

        // Decrease the in-degree of all vertices adjacent to the popped vertex
        for (i = 0; i < n; i++) {
            if (arr[out[k]][i] == 1) {
                in[i]--;
            }
        }

        // Move to the next position in the output array
        k++;
    }

    // Print the topological sorting order
    printf("Topological sorting order is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", out[i] + 1); // +1 to convert 0-based index to 1-based
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int arr[10][10];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    topologicalSorting(arr, n);
    return 0;
}
/*
/tmp/jqmsp871H2.o
Enter the number of vertices in the graph: 5
Enter the adjacency matrix for the graph:
0 0 1 0 0
1 0 1 0 1
0 0 0 0 0
0 0 1 0 0
0 0 0 1 0
Topological sorting order is:
2 5 4 1 3 


=== Code Execution Successful ===

*/
