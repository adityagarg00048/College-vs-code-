#include <stdio.h>

int main() {
    int rows = 2, cols = 3;
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int Transpose[3][2];

    // Compute Transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Transpose[j][i] = A[i][j];
        }
    }

    printf("Transposed Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", Transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}