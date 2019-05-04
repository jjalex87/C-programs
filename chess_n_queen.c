#include <stdio.h>
#include <stdlib.h>

typedef int bool;

#define N  4

#define TRUE    1
#define FALSE   0

void display(int arr[N][N])
{
    int i, j;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

bool is_safe(int arr[N][N], int row, int col)
{
    int i, j;
    
    /* Check the current row left of the given position */
    for (i = 0; i < col; i++) {
        if (arr[row][i]) {
            return (FALSE);
        }
    }
    
    /* Check the upper left diagonal*/
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j]) {
            return (FALSE);
        }
    }
    
    /* Check the lower left diagonal*/
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (arr[i][j]) {
            return (FALSE);
        }
    }
    
    return (TRUE);
}

bool solve_n_queen(int arr[N][N], int row, int col)
{
    int i, j;
    
    if (col >= N) {
        return (TRUE);
    }
    
    for (i = 0; i < N; i++) {
        if (is_safe(arr, i, col)) {
            arr[i][col] = 1;
            
            if (solve_n_queen(arr, i, col+1)) {
                return (TRUE);
            }
            
            arr[i][col] = FALSE;
        }
    }
    return (FALSE);
}

void main()
{
    int arr[N][N] = {{0}}, rc;
    
    solve_n_queen(arr, 0, 0);
    display(arr);
}

Output:
0 0 1 0                                                                                                                                        
1 0 0 0                                                                                                                                        
0 0 0 1                                                                                                                                        
0 1 0 0 
