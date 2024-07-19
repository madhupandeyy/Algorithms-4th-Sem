#include <stdio.h>

#define INF 999 // A value to represent infinity

// Function to find the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int a[n][n]; // Adjacency matrix
    int d[n][n]; // Distance matrix

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            // Initialize distance matrix, set INF for no direct path except for diagonal elements
            if (a[i][j] == 0 && i != j) {
                d[i][j] = INF;
            } else {
                d[i][j] = a[i][j];
            }
        }
    }

    // Floyd-Warshall algorithm to compute shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Print the resulting distance matrix
    printf("The distance matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF)
                printf("%s ", "INF");
            else
                printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*

/tmp/OhgfMSGLpI.o
Enter the number of vertices: 4
Enter adjacency matrix:
0 0 3 0
2 0 0 0
0 6 0 1
7 0 0 0
The distance matrix of the graph:
0 9 3 4 
2 0 5 6 
8 6 0 1 
7 16 10 0 


=== Code Execution Successful ===

*/
