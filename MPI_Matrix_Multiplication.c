#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define SIZE 512

int main(int argc, char** argv) {

    int rank, size;
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE], result[SIZE][SIZE];
    int i, j, k, sum;
    double start_time, end_time;
    MPI_Status status;

    // Initialize MPI environment
    MPI_Init(&argc, &argv);

    // Get rank and size of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Initialize matrices
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            mat1[i][j] = 1;
            mat2[i][j] = 2;
            result[i][j] = 0;
        }
    }

    // Start timer
    start_time = MPI_Wtime();

    // Distribute rows of mat1 to each process
    int rows_per_proc = SIZE / size;
    int start_row = rank * rows_per_proc;
    int end_row = start_row + rows_per_proc;

    // Calculate partial results for each process
    for(i=start_row; i<end_row; i++) {
        for(j=0; j<SIZE; j++) {
            sum = 0;
            for(k=0; k<SIZE; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
        }
    }

    // Collect results from all processes
    if (rank == 0) {
        for (i = 0; i < size; i++) {
            if (i != 0) {
                MPI_Recv(result[i * rows_per_proc], rows_per_proc*SIZE, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            }
        }
    } else {
        MPI_Send(result[start_row], rows_per_proc*SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    // Stop timer
    end_time = MPI_Wtime();

    // Print results
    if (rank == 0) {
        printf("Time taken by process %d: %f seconds\n", rank, end_time - start_time);
          for(i=0; i<SIZE; i++) {
              for(j=0; j<SIZE; j++) {
                  printf("%d ", result[i][j]);
              }
              printf("\n");
          }
    }

    // Finalize MPI environment
    MPI_Finalize();

    return 0;
}
