#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int array[SIZE];


void merge(int start, int mid, int end);

void *mergeSort(void *arg);


int main() {

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {

        array[i] = rand() % 30000;
    }

    int data[2] = {0, SIZE - 1};

    pthread_t sort_thread;

    pthread_create(&sort_thread, NULL, mergeSort, data);

    pthread_join(sort_thread, NULL);

    printf("Sorted array: ");

    for (int i = 0; i < SIZE; i++) {
        printf("\nnumber[%d] = %d", i, array[i]);
    }

    printf("\n");

    return 0;

}




void merge(int start, int mid, int end) {

    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) {

        left[i] = array[start + i];

    }


    for (int j = 0; j < n2; j++) {

        right[j] = array[mid + 1 + j];

    }


    int i = 0, j = 0, k = start;


    while (i < n1 && j < n2) {

        if (left[i] <= right[j]) {

            array[k++] = left[i++];

        }
        else {

            array[k++] = right[j++];
        }
    }

    while (i < n1) {

        array[k++] = left[i++];
    }

    while (j < n2) {

        array[k++] = right[j++];
    }
}



void *mergeSort(void *arg) {

    int *data = (int *)arg;
    int start = data[0];
    int end = data[1];

    if (start < end) {

        int mid = (start + end) / 2;

        int left[2] = {start, mid};

        int right[2] = {mid + 1, end};

        pthread_t left_thread, right_thread;

        pthread_create(&left_thread, NULL, mergeSort, left);

        pthread_create(&right_thread, NULL, mergeSort, right);

        pthread_join(left_thread, NULL);

        pthread_join(right_thread, NULL);

        merge(start, mid, end);

    }

    return NULL;

}