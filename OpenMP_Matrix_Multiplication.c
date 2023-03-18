#include <stdio.h>

#include <omp.h>

#define N 512

int main() {

    int i, j, k;
    double A[N][N], B[N][N], C[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

#pragma omp parallel for shared(A, B, C) private(i, j, k) default (none)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Matrix result:\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}