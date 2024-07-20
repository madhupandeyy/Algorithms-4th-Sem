#include <stdio.h>
#include <stdlib.h>

void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

int generateNextPermutation(int perm[], int dir[], int n) {
    int mobile = -1;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        if ((dir[i] == 1 && i < n - 1 && perm[i] > perm[i + 1]) || 
            (dir[i] == -1 && i > 0 && perm[i] > perm[i - 1])) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    if (mobileIndex == -1) {
        return 0;
    }

    if (dir[mobileIndex] == 1) {
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[mobileIndex + 1];
        perm[mobileIndex + 1] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[mobileIndex + 1];
        dir[mobileIndex + 1] = temp;
    } else {
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[mobileIndex - 1];
        perm[mobileIndex - 1] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[mobileIndex - 1];
        dir[mobileIndex - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (perm[i] > mobile) {
            dir[i] = -dir[i];
        }
    }

    return 1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int perm[n];
    int dir[n];

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1;
    }

    printPermutation(perm, n);
    while (generateNextPermutation(perm, dir, n)) {
        printPermutation(perm, n);
    }

    return 0;
}
