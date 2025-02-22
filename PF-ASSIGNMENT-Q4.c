#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_STRING_LEN 20

//sorting of the string so we can compare and adjust the single character easily
void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}


void group(char transactions[][MAX_STRING_LEN], int n, int groups[][MAX_TRANSACTIONS], int *groupSizes) {
    
    int numGroups = 10; 

    // Sort each transaction
    for (int i = 0; i < n; i++) {
        sortString(transactions[i]);
    }

   
    int groupIndex = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < groupIndex; j++) {
            if (strcmp(transactions[i], transactions[groups[j][0]]) == 0) {
                groups[j][groupSizes[j]++] = i;
                break;
            }
        }
        if (j == groupIndex) {
            groups[groupIndex][0] = i;
            groupSizes[groupIndex] = 1;
            groupIndex++;
        }
    }

    // Print the grouped transactions
    for (int i = 0; i < groupIndex; i++) {
        printf("[");
        for (int j = 0; j < groupSizes[i]; j++) {
            printf("'%s', ", transactions[groups[i][j]]);
        }
        printf("]\n");
    }
}

int main() {
    char transactions[][MAX_STRING_LEN] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(transactions) / sizeof(transactions[0]);

    int groups[MAX_TRANSACTIONS][MAX_TRANSACTIONS];
    int groupSizes[MAX_TRANSACTIONS];

    group(transactions, n, groups, groupSizes);

    return 0;
}