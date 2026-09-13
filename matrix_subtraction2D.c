#include <stdio.h>

int main() {
    int rows = 2, cols = 2;
    int A[2][2] = {{9, 8}, {7, 6}};
    int B[2][2] = {{1, 2}, {3, 4}};
    int C[2][2]; // Result matrix

    printf("Matrix Subtraction Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}