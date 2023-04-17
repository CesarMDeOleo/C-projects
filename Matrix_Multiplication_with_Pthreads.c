#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define N 512
#define NUM_THREADS 4
#define simulations 20

double A[N][N], B[N][N], C[N][N];

pthread_t threads[NUM_THREADS];
int thread_ids[NUM_THREADS];

double total_time = 0;

void* matrix_mult(void* arg);

int main() {
    int i, j;
    clock_t start_time, end_time;
    double avg_time;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    for (i = 0; i < simulations; i++) {
        start_time = clock();

        for (j = 0; j < NUM_THREADS; j++) {
            thread_ids[j] = j;
            pthread_create(&threads[j], NULL, matrix_mult, (void*) &thread_ids[j]);
        }

        for (j = 0; j < NUM_THREADS; j++) {
            pthread_join(threads[j], NULL);
        }

        end_time = clock();
        total_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }

    avg_time = total_time / simulations;

    printf("Matrix result:\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    printf("Average time taken: %f seconds\n", avg_time);

    return 0;
}

void* matrix_mult(void* arg) {

    int tid = *(int*)arg;
    int i, j, k;

    int start = tid * N / NUM_THREADS;
    int end = (tid + 1) * N / NUM_THREADS;

    for (i = start; i < end; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_exit(NULL);
}