#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE  100
#define MAX_CHAR        26
#define TRUE            1
#define FALSE           0

// Array element  
typedef struct q_elem_ { 
    char ch;    
    int freq; /* key of the priority queue */
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

bool enqueue(char ch, int freq)
{
    int i, j;
    
    if (is_queue_full()) {
        printf("\nERROR: Queue is full!");
        return (FALSE);
    }
    
    if (is_queue_empty()) {
        queue[rear].ch = ch;
        queue[rear].freq = freq;
        rear++;
        return (TRUE);
    }
    
    for (i = 0; i < rear; i++) {
        if (queue[i].freq < freq) {
            /* i is the index where the new element should be inserted 
             * All existing elements starting from index i should be 
             * shifted by one position right */
            for (j = rear; j > i; j--) {
                queue[j].ch = queue[j-1].ch;
                queue[j].freq = queue[j-1].freq;
            }
            queue[j].ch = ch;
            queue[j].freq = freq;
            rear++;
            return (TRUE);
        }
    }
    queue[i].ch = ch;
    queue[i].freq = freq;
    rear++;
    return (TRUE);
}

void dequeue(char *ch, int *freq)
{
    int i;
    
    if (is_queue_empty()) {
        printf("\nERROR: Queue is empty!");
        return;
    }
    
    *ch = queue[front].ch;
    *freq = queue[front].freq;
    
    for (i = 0; i < rear - 1; i++) {
        queue[i].ch = queue[i + 1].ch;
        queue[i].freq = queue[i + 1].freq;
    }
    rear--;
}

int rearrange_str(char *str)
{
    int len = strlen(str);
    int i;
    int count[MAX_CHAR] = {0};
    char ch;
    q_elem_t q_elem, prev_elem;
    
    for (i = 0; i < len; i++) {
        ch = str[i];
        count[ch - 'a']++;
    }
    
    for (i = 0; i < MAX_CHAR; i++) {
        if (count[i] > 0) {
            enqueue(i + 'a', count[i]);
        }
    }
    
    memset(str, 0, len);
    i = 0;
    prev_elem.ch = '#';
    prev_elem.freq = -1;
    while (!is_queue_empty()) {
        
        dequeue(&q_elem.ch, &q_elem.freq);
        str[i++] = q_elem.ch;
        q_elem.freq--;
        
        if (prev_elem.freq > 0) {
            enqueue(prev_elem.ch, prev_elem.freq);
        }
        memcpy(&prev_elem, &q_elem, sizeof(prev_elem));
    }
    
    return(i == len);
}

void main()
{
    char str[] = "ababbbbcc";
    
    printf("\nGiven string: %s", str);
    if (rearrange_str(str)) {
        printf("\nRearranged string: %s", str);
    } else {
        printf("\nCould not rearrange string");
    }
    
    strcpy(str, "aabbccaaaa");
    printf("\nGiven string: %s", str);
    if (rearrange_str(str)) {
        printf("\nRearranged string: %s", str);
    } else {
        printf("\nCould not rearrange string");
    }
}

Output:
Given string: ababbbbcc                                                                                                                          
Rearranged string: babcbabcb                                                                                                                     
Given string: aabbccaaaa                                                                                                                         
Could not rearrange string 
