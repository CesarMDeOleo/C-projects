#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

#include <pthread.h>

#define amount 1000000
#define Num_Threads 4

double rand_double_x() {
  return ((double) rand()) / ((double) RAND_MAX);
}

double rand_double_y() {
  return ((double) rand()) / ((double) RAND_MAX);
}

struct thread_data {
  double length;
  double number_in_circle;
  double number_in_square;
};

void * throw_darts(void * darts);

int main() {

  const double pi = 3.1416;
  double circle_radius = 0.5;
  double area_square = 1;
  double area_circle = pi * (circle_radius * circle_radius);
  double area = (area_circle / area_square) * 4;
  double number_in_circle = 0;
  double number_in_square = 0;

  pthread_t threads[Num_Threads];
  struct thread_data thread_data_array[Num_Threads];

  double length_per_thread = amount / Num_Threads;

  for (int i = 0; i < Num_Threads; i++) {
    thread_data_array[i].length = length_per_thread;
    thread_data_array[i].number_in_circle = 0;
    thread_data_array[i].number_in_square = 0;
    pthread_create( & threads[i], NULL, throw_darts, (void * ) & thread_data_array[i]);
  }

  for (int i = 0; i < Num_Threads; i++) {
    pthread_join(threads[i], NULL);
    number_in_circle += thread_data_array[i].number_in_circle;
    number_in_square += thread_data_array[i].number_in_square;
  }

  number_in_square = number_in_circle + number_in_square;
  printf("\nNumber in circle: ");
  printf("%.1f\n", number_in_circle);
  printf("Number in square: ");
  printf("%.1f\n", number_in_square);

  double inside_dart = (number_in_circle) / number_in_square;
  double the_pie = (inside_dart * 4);
  printf("\n%0.4f\n", the_pie);
  printf("%0.4f\n", area);

  return 0;
}

void * throw_darts(void * darts) {

  srand(time(NULL));

  struct thread_data * my_data;
  my_data = (struct thread_data * ) darts;

  double distance;
  double cx = 0;
  double cy = 0;
  double diameter = 1;

  for (int i = 0; i < my_data -> length; i++) {

    distance = sqrt(pow((rand_double_x() - cx), 2) + pow((rand_double_y() - cy), 2));

    if (distance < diameter) {

      my_data -> number_in_circle += 1;

    } else if (distance > diameter) {

      my_data -> number_in_square += 1;

    } else {

      my_data -> number_in_circle += 1;
    }
  }

  pthread_exit(NULL);
}
