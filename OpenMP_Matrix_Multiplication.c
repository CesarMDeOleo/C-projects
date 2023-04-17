#include <stdio.h>
#include <omp.h>

#define N 512
#define simulations 20

int main() {
    int i, j, k;
    double A[N][N], B[N][N], C[N][N];
    double start_time, end_time;
    double avg_time;
    double total_time = 0;

    // Initialize matrices
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    // Perform matrix multiplication and time the simulations
    for (i = 0; i < simulations; i++) {
        // Start timer
        start_time = omp_get_wtime();

        // Compute matrix multiplication
#pragma omp parallel for shared(A, B, C) private(i, j, k) default(none)
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                C[i][j] = 0.0;
                for (k = 0; k < N; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // End timer
        end_time = omp_get_wtime();

        total_time += (end_time - start_time);
    }

    avg_time = total_time / simulations;

    // Print elapsed time
    printf("Elapsed time: %f seconds\n", avg_time);

    return 0;
}`