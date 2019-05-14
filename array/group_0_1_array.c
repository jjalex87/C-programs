#include <stdio.h>

void swap (int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void my_grouping (int *arr, int size)
{
    int left = 0, right = size - 1;
    
    while (1) {
        while (left < size && arr[left] == 0) {
            left++;
        }
        while (right >= 0 && arr[right] == 1) {
            right--;
        }
        
        if (left >= right) {
            break;
        } else {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

void disp_arr (int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr1[] = {1,1,0,0,1,0,0,1};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    
    printf("\nGiven array : [ ");
    disp_arr(arr1, size);
    printf("]");
    
    my_grouping(arr1, size);
    
    printf("\nRe-grouped array : [ ");
    disp_arr(arr1, size);
    printf("]");
    
    return 0;
}

Output:
Given array : [ 1 1 0 0 1 0 0 1 ]                                                                                                              
Re-grouped array : [ 0 0 0 0 1 1 1 1 ]
