#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize){

    int *result = malloc(numsSize * sizeof(int));
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        result[i] = sum;
    }

    *returnSize = numsSize;
    return result;
}

int main() {
    int size = 4;
    int nums[size];
    int return_size = size;

    printf("Enter the following array: ");

    for (int i = 0; i < size; i++) {
        scanf("%i", &nums[i]);
    }

    int *final = runningSum(nums, size, &return_size);

    printf("\nRunning Sum: ");
    for (int i = 0; i < size; i++) {
        printf("%i ", final[i]);
    }

    free(final);

    return 0;
}