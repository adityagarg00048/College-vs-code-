#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7};
    int n1 = 3, n2 = 4;
    int merged[10]; // Ensure this is large enough

    // Copy elements of first array
    for (int i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }

    // Copy elements of second array
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i];
    }

    printf("Merged Array: ");
    for (int i = 0; i < (n1 + n2); i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}