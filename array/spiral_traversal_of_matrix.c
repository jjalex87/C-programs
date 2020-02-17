#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 6

void print_spiral(int arr[ROW][COL])
{
    int row_start = 0, row_end = ROW, col_start = 0, col_end = COL;
    int i;
    
    while (row_start < row_end && col_start < col_end) {
        /*printf("row_start:%d row_end:%d col_start:%d col_end:%d\n", 
            row_start, row_end, col_start, col_end); */
        //Traverse first row
        for (i = col_start; i < col_end; i++) {
            printf("%d ", arr[row_start][i]);
        }
        row_start++;
        
        //Traverse last col
        for (i = row_start; i < row_end; i++) {
            printf("%d ", arr[i][col_end - 1]);
        }
        col_end--;
        
        //Traverse last row
        if (row_start < row_end) {
            for (i = col_end - 1; i >= col_start; i--) {
                printf("%d ", arr[row_end - 1][i]);
            }
            row_end--;
        }
        
        //Traverse first col
        if (col_start < col_end) {
            for (i = row_end - 1; i >= row_start; i--) {
                printf("%d ", arr[i][col_start]);
            }
            col_start++;
        }
    }
}

void main()
{
    int arr[ROW][COL] = {
        {1,2,3,4,5,6},
        {5,6,7,8,9,0},
        {9,0,1,2,3,4},
        {3,4,5,6,7,8},
        {9,0,1,2,3,4}
    };
    
    print_spiral(arr);
}

Output:
1 2 3 4 5 6 0 4 8 4 3 2 1 0 9 3 9 5 6 7 8 9 3 7 6 5 4 0 1 2
