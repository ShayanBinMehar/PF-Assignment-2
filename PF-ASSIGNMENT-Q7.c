#include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLS 5

void printArray(char arr[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int searchString(char arr[][COLS], const char *str) {
    int len = strlen(str);
    for (int i = 0; i < ROWS - len + 1; i++) {
        for (int j = 0; j < COLS - len + 1; j++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (arr[i + k][j + k] != str[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                return 1; // Found
            }
        }
    }
    return 0; // Not found
}

int main() {
    char arr[ROWS][COLS];
    int score = 0;

  
    int seed = 12345;
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            seed = (seed * 16807) % 2147483647;
            arr[i][j] = 'A' + seed % 26;
        }
    }


    sprintf(arr[ROWS - 1], "1234");

    printArray(arr);

    char str[20];
    printf("Enter a string to search (or 'END' to quit): ");
    while (scanf("%s", str) == 1) {
        if (strcmp(str, "END") == 0) {
            break;
        }

        if (searchString(arr, str)) {
            score++;
            printf("%s is present. Score: %d\n", str, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", str, score);
        }

        printf("Enter a string to search (or 'END' to quit): ");
    }

    return 0;
}