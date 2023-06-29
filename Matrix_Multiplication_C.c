#include <stdio.h>
#include <time.h>

#define ROWS 128
#define COLS 128

void matrixMultiplication(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]);


int main() {
    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int result[ROWS][COLS];


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            A[i][j] = 1;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            B[i][j] = 2;
        }
    }

    clock_t start_time = clock();
    matrixMultiplication(A, B, result);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Matrix multiplication result:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Runtime: %.4f seconds\n", elapsed_time);

    return 0;
}


void matrixMultiplication(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}