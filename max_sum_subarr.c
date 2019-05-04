#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a,b) ((a)>(b)?(a):(b))

int max_sum_subarr(int *arr, int size)
{
    int i, j, temp_sum = 0, final_sum = 0;
    
    temp_sum = arr[0];
    for (i = 1; i < size; i++) {
        temp_sum = max(temp_sum, arr[i]);
    }
    
    if (temp_sum < 0) {
        return (temp_sum);
    }
    
    temp_sum = 0;
    for (i = 0; i < size; i++) {
        temp_sum = temp_sum + arr[i];
        if (temp_sum < 0) {
            temp_sum = 0;
        }
        final_sum = max(final_sum, temp_sum);
    }
    return (final_sum);
}

#define MAX_ARR1_SIZE 4
#define MAX_ARR2_SIZE 10
#define MAX_ARR3_SIZE 6

void main()
{
    int arr1[MAX_ARR1_SIZE] = {3,-2,5,-1};
    int arr2[MAX_ARR2_SIZE] = {1,-3,2,-5,7,6,-1,-4,11,-23};
    int arr3[MAX_ARR3_SIZE] = {-2,-3,-6,-1,-12,-52};
    int i;
    
    printf("\nArray 1: [ ");
    for (i = 0; i < MAX_ARR1_SIZE; i++) {
        printf("%d ", arr1[i]);
    }
    printf("]");
    
    printf("\nMaximum subarray sum of Array1: %d", max_sum_subarr(arr1, MAX_ARR1_SIZE));
    
    printf("\nArray 2: [ ");
    for (i = 0; i < MAX_ARR2_SIZE; i++) {
        printf("%d ", arr2[i]);
    }
    printf("]");
    
    printf("\nMaximum subarray sum of Array2: %d", max_sum_subarr(arr2, MAX_ARR2_SIZE));
    
    printf("\nArray 3: [ ");
    for (i = 0; i < MAX_ARR3_SIZE; i++) {
        printf("%d ", arr3[i]);
    }
    printf("]");
    
    printf("\nMaximum subarray sum of Array3: %d", max_sum_subarr(arr3, MAX_ARR3_SIZE));
}

Output:
Array 1: [ 3 -2 5 -1 ]                                                                                                                         
Maximum subarray sum of Array1: 6                                                                                                              
Array 2: [ 1 -3 2 -5 7 6 -1 -4 11 -23 ]                                                                                                        
Maximum subarray sum of Array2: 19                                                                                                             
Array 3: [ -2 -3 -6 -1 -12 -52 ]                                                                                                               
Maximum subarray sum of Array3: -1
