#include <stdio.h>
#include <time.h>

#define ROWS 256
#define COLS 512
#define TILE_SIZE 32


void initializeMatrix(int matrix[ROWS][COLS], int rows, int cols, int value);

void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int result[ROWS][COLS], int rowsA, int colsA, int colsB);

void displayMatrix(int matrix[ROWS][COLS], int rows, int cols);


int main() {

    int matrixA[ROWS][COLS];
    int matrixB[ROWS][COLS];
    int result[ROWS][COLS] = {0};

    initializeMatrix(matrixA, ROWS, COLS, 1);
    initializeMatrix(matrixB, ROWS, COLS, 2);

    clock_t start = clock();

    multiplyMatrices(matrixA, matrixB, result, ROWS, COLS, COLS);

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Result matrix:\n");
//    displayMatrix(result, ROWS, COLS);

    printf("Execution time: %.6f seconds\n", executionTime);

    return 0;
}

void initializeMatrix(int matrix[ROWS][COLS], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
}

void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int result[ROWS][COLS], int rowsA, int colsA, int colsB) {
    for (int ii = 0; ii < rowsA; ii += TILE_SIZE) {
        for (int jj = 0; jj < colsB; jj += TILE_SIZE) {
            for (int kk = 0; kk < colsA; kk += TILE_SIZE) {
                for (int i = ii; i < ii + TILE_SIZE; i++) {
                    for (int j = jj; j < jj + TILE_SIZE; j++) {
                        for (int k = kk; k < kk + TILE_SIZE; k++) {
                            result[i][j] += matrixA[i][k] * matrixB[k][j];
                        }
                    }
                }
            }
        }
    }
}


void displayMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}