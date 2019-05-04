/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef int bool;

#define ROW 3
#define COL 5

#define EMPTY   0
#define FRESH   1
#define ROTTEN  2

#define MAX_QUEUE_SIZE  (100)
#define TRUE            1
#define FALSE           0

// Queue element  
typedef struct q_elem_ { 
    int r;    
    int c; /* Lower values indicate higher priority */
} q_elem_t; 

q_elem_t queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;

bool is_queue_full()
{
    return (rear == MAX_QUEUE_SIZE);
}

bool is_queue_empty()
{
    return (front == rear);
}

bool enqueue(q_elem_t obj)
{
    if (!is_queue_full()) {
        queue[rear++] = obj;
        return (TRUE);
    } else {
        printf("\nERROR: Queue is full!");
        return (FALSE);
    }
}

q_elem_t dequeue()
{
    int i;
    q_elem_t obj;
    if (!is_queue_empty()) {
        obj = queue[front];
        for (i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
    } else {
        printf("\nERROR: Queue is empty!");
    }
    return obj;
}

int is_valid_index(int r, int c)
{
    if (r >= 0 && r < ROW && c >= 0 && c < COL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int is_rotting_complete(int arr[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (arr[i][j] == FRESH) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

int time_to_rot(int arr[][COL])
{
    int i, j, r, c;
    q_elem_t q_elem;
    int time = 0;
    int new_rot = 0;
    
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (arr[i][j] == ROTTEN) {
                q_elem.r = i;
                q_elem.c = j;
                enqueue(q_elem);
            }
        }
    }
    
    /* enqueue a delimiter */ 
    q_elem.r = -1;
    q_elem.c = -1;
    enqueue(q_elem);
    
    while (!is_queue_empty()) {
        q_elem = dequeue();
        r = q_elem.r;
        c = q_elem.c;
        
        
        
        /* If it is a delimiter, then one cycle of rotting is complete */
        if (r == -1 && c == -1) {
            printf("\nDelimiter dequeued");
            new_rot = 0;
            if (!is_queue_empty) {
                enqueue(q_elem);
            }
            continue;
        }
        
        printf("\nDequeued element arr[%d][%d]:%d", r,c,arr[r][c]);
        
        /* Rot the orange above this orange */
        if (is_valid_index(r-1, c) && arr[r-1][c] == FRESH) {
            if (!new_rot) {
                new_rot = 1;
                time++;
            }
            printf("\nRotting [%d,%d]", r-1, c);
            arr[r-1][c] = ROTTEN;
            q_elem.r = r-1;
            q_elem.c = c;
            enqueue(q_elem);
        }
        /* Rot the orange below this orange */
        if (is_valid_index(r+1, c) && arr[r+1][c] == FRESH) {
            if (!new_rot) {
                new_rot = 1;
                time++;
            }
            printf("\nRotting [%d,%d]", r+1, c);
            arr[r+1][c] = ROTTEN;
            q_elem.r = r+1;
            q_elem.c = c;
            enqueue(q_elem);
        }
        /* Rot the orange on the left of this orange */
        if (is_valid_index(r, c-1) && arr[r][c-1] == FRESH) {
            if (!new_rot) {
                new_rot = 1;
                time++;
            }
            printf("\nRotting [%d,%d]", r, c-1);
            arr[r][c-1] = ROTTEN;
            q_elem.r = r;
            q_elem.c = c-1;
            enqueue(q_elem);
        }
        /* Rot the orange on the right of this orange */
        if (is_valid_index(r, c+1) && arr[r][c+1] == FRESH) {
            if (!new_rot) {
                new_rot = 1;
                time++;
            }
            printf("\nRotting [%d,%d]", r, c+1);
            arr[r][c+1] = ROTTEN;
            q_elem.r = r;
            q_elem.c = c+1;
            enqueue(q_elem);
        }
    }
    
    return(is_rotting_complete(arr)?time:-1);
}

int main()
{
    int oranges[ROW][COL] = {{2, 1, 0, 2, 1},
                             {1, 0, 1, 2, 1},
                             {1, 0, 0, 2, 1}};
    /*                        
    int oranges[ROW][COL] = {{2, 0, 0, 2, 0},
                             {0, 0, 2, 0, 0},
                             {2, 0, 0, 2, 0}};
    */
    
    int time = time_to_rot(oranges);
    if (time != -1) {
        printf("\nTime taken to rot the box: %d", time);
    } else {
        printf("\nThe box is not completely rotten");
    }

    return 0;
}

Output:
Dequeued element arr[0][0]:2                                                                                                                     
Rotting [1,0]                                                                                                                                    
Rotting [0,1]                                                                                                                                    
Dequeued element arr[0][3]:2                                                                                                                     
Rotting [0,4]                                                                                                                                    
Dequeued element arr[1][3]:2                                                                                                                     
Rotting [1,2]                                                                                                                                    
Rotting [1,4]                                                                                                                                    
Dequeued element arr[2][3]:2                                                                                                                     
Rotting [2,4]                                                                                                                                    
Delimiter dequeued                                                                                                                               
Dequeued element arr[1][0]:2                                                                                                                     
Rotting [2,0]                                                                                                                                    
Dequeued element arr[0][1]:2                                                                                                                     
Dequeued element arr[0][4]:2                                                                                                                     
Dequeued element arr[1][2]:2                                                                                                                     
Dequeued element arr[1][4]:2                                                                                                                     
Dequeued element arr[2][4]:2                                                                                                                     
Dequeued element arr[2][0]:2                                                                                                                     
Time taken to rot the box: 2  
