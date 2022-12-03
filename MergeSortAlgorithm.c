#include <stdio.h>

#include <stdlib.h>

#include <time.h>


void fill_random(int array[], int length, int max);
void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);


int main(void)
{

    double time_spent = 0.0;

    int length = 1000000;

    srand(time(NULL));

    int array[length];
    fill_random(array, length, 30000);



    clock_t begin = clock();

    merge_sort(array, length);

    clock_t end = clock();

    for (int i = 0; i < length; i++) {
        printf("a[%d]=%d\n", i, array[i]);
    }

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds", time_spent);

    return 0;
}

void fill_random(int array[], int length, int max)

{
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % max) + 1;
    }
}


void merge_sort(int a[], int length)
{

    merge_sort_recursion(a, 0, length - 1);
}


void merge_sort_recursion(int a[], int l, int r)
{
  
    if (l < r)
    {

        int m = l + (r - l) / 2;


        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);
        merge_sorted_arrays(a, l, m, r);
    }
}


void merge_sorted_arrays(int a[], int l, int m, int r)
{

    int left_length = m - l + 1;
    int right_length = r - m;


    int temp_left[left_length];
    int temp_right[right_length];


    int i, j, k;


    for ( i = 0; i < left_length; i++) {
        temp_left[i] = a[l + i];
    }


    for ( i = 0; i < right_length; i++) {
        temp_right[i] = a[m + 1 + i];
    }

    for (i = 0, j = 0, k = l; k <= r; k++)
    {

        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }

        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }
}
