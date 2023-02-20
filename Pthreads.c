#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <time.h>



#define NUM_THREADS 2


#define NUM_NUMBERS 1000000



long numbers[NUM_NUMBERS];

long sum = 0;

void * add_numbers();



int main() {

    long i;

    double time_spent = 0.0;

    pthread_t th[NUM_THREADS];

    srand(time(NULL));

    clock_t begin = clock();



        for (i = 0; i < NUM_NUMBERS; i++) {

            numbers[i] = rand() % 1000 + 1;

        }



        for (i = 0; i < NUM_THREADS; i++) {

            pthread_create(&th[i], NULL, add_numbers, NULL);

        }

        for (i = 0; i < NUM_THREADS; i++) {

            pthread_join(th[i], NULL);
        }


        printf("\nSum of the numbers: %ld\n", sum);

        clock_t end = clock();

        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

        printf("The elapsed time is %f seconds", time_spent);

        pthread_exit(NULL);



    return 0;

}



void * add_numbers() {

    long thread_sum = 0;

    for (long i = 0; i < NUM_NUMBERS / NUM_THREADS; i++) {

        thread_sum += numbers[i];

    }

    sum += thread_sum;

    return 0;

}