#include <stdio.h>
#include <omp.h>

int main() {
    int num = 1;

    #pragma omp parallel num_threads(8)
    {
        while (num <= 1000) {
            #pragma omp critical
            {
                printf("Thread %d: %d\n", omp_get_thread_num(), num);
                num++;
            }
        }
    }

    return 0;
}
