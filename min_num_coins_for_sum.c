#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_min_coins(int coins[], int num_coins, int value)
{
    if (value == 0) {
        return 0;
    }
    
    int table[value + 1], i, j;
    table[0] = 0;
    
    for (i = 1; i <= value; i++) {
        table[i] = INT_MAX;
    }
    
    for (i = 1; i <= value; i++) {
        for (j = 0; j < num_coins; j++) {
            if (coins[j] <= i) {
                int temp = table[i-coins[j]];
                if (temp != INT_MAX && (temp + 1) < table[i]) {
                    table[i] = temp + 1;
                }
            }
        }
    }
    return (table[value]);
}

void main()
{
    int coins[] = {9,6,5,1};
    int num_coins = sizeof(coins)/sizeof(coins[0]);
    int value = 11;
    
    int min_coins = find_min_coins(coins, num_coins, value);
    printf("\nMinimum num of coins required for amount:%d is %d", value, min_coins);
}

Output:
Minimum num of coins required for amount:11 is 2
