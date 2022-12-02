#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <stdbool.h>


void fill_random(int array[], int length, int max);

void bubble_sort (int array[], int length);



int main(void) {

    double time_spent = 0.0;

    int length = 100000;

    srand(time(NULL));

    int array[length];
    fill_random(array, length, 30000);



    clock_t begin = clock();

    bubble_sort(array, length);

    clock_t end = clock();


    for (int i = 0; i < length; i++)
        printf("a[%d]=%d\n", i, array[i]);


    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds", time_spent);

    return 0;
}

void fill_random(int array[], int length, int max)

{
    for (int i = 0; i < length; i++)
        array[i] = (rand() % max) + 1;

}

void bubble_sort (int array[], int length)
{
    bool swapped = false;
    int i = 0;
    do

    {
        swapped = false;
        for (int j = 0; j < (length - 1 - i ); j++)

        {
            if (array[j] > array[j + 1])

            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;

            }

        }
        i++;
    } while (swapped);

}
