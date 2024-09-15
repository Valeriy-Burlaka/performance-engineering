#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4096

// Function prototypes
void multiplyMatrices(double A[N][N], double B[N][N], double C[N][N]);
void initializeMatrix(double matrix[N][N]);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare matrices
    double (*A)[N] = malloc(N * sizeof(*A));
    double (*B)[N] = malloc(N * sizeof(*B));
    double (*C)[N] = malloc(N * sizeof(*C));

    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize matrices
    initializeMatrix(A);
    initializeMatrix(B);

    // Perform matrix multiplication
    multiplyMatrices(A, B, C);

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}

void multiplyMatrices(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void initializeMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}
