#include <pthread.h>

#include <stdio.h>

#define Num_Threads 100
#define increment 1

int Value_number = 0;

pthread_mutex_t lock;

void * add_numbers(void * arg);

int main() {

  pthread_t threads[Num_Threads];

  pthread_mutex_init( & lock, NULL);

  for (int i = 0; i < Num_Threads; i++) {
    pthread_create( & (threads[i]), NULL, add_numbers, NULL);
  }

  for (int i = 0; i < Num_Threads; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy( & lock);

  printf("\nThe final value of the number is %d.\n", Value_number);

  return 0;
}

void * add_numbers(void * arg) {

  for (int i = 0; i < increment; i++) {

    pthread_mutex_lock( & lock);

    Value_number++;

    pthread_mutex_unlock( & lock);

  }

  return NULL;
}
