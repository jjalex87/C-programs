#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

#define MAX_ARR_SIZE 6


int find_num_pair_having_sum(int *arr, int n, int sum, int *num1, int *num2)
{
    int left = 0, right = n-1;
    int local_sum = 0;
    
    while (left < right) {
        local_sum = arr[left] + arr[right];
        if (local_sum == sum) {
            *num1 = arr[left];
            *num2 = arr[right];
            return 1;
        } else if (local_sum < sum) {
            left++;
        } else {
            right--;
        }
    }
    return 0;
}

void print_result(int res, int sum, int num1, int num2)
{
    if (res) {
        printf("\nNumbers with sum %d are [ %d %d ]", sum, num1, num2);
    } else {
        printf("\nNo pair of numbers exists whose sum is %d", sum);
    }
}

void main()
{
    int arr[MAX_ARR_SIZE] = {1, 4, 45, 6, 10, -8};
    int sum, res;
    int num1 = 0, num2 = 0;
    
    merge_sort(arr, 0, MAX_ARR_SIZE - 1);
    printf("\nSorted array: [ ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    
    sum = 16;
    res = find_num_pair_having_sum(arr, MAX_ARR_SIZE, sum, &num1, &num2);
    print_result(res, sum, num1, num2);
    
    sum = 6;
    res = find_num_pair_having_sum(arr, MAX_ARR_SIZE, sum, &num1, &num2);
    print_result(res, sum, num1, num2);
    
    sum = 2;
    res = find_num_pair_having_sum(arr, MAX_ARR_SIZE, sum, &num1, &num2);
    print_result(res, sum, num1, num2);
    
}

Output:
Sorted array: [ -8 1 4 6 10 45 ]                                                                                                               
                                                                                                                                               
Numbers with sum 16 are [ 6 10 ]                                                                                                               
No pair of numbers exists whose sum is 6                                                                                                       
Numbers with sum 2 are [ -8 10 ]
