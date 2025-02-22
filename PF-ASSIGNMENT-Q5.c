#include <stdio.h>

void printHorizontalHistogram(int values[], int n) {
    
	for (int i = 0; i < n; ++i) {
        printf("%d: ", values[i]);
        for (int j = 0; j < values[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

void printVerticalHistogram(int values[], int n) {
    int maxValue = values[0];
    for (int i = 1; i < n; ++i) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }

    for (int i = maxValue; i > 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    
	int values[] = {3, 5, 1, 4};
	int n = sizeof(values)/sizeof(values[0]);
    printf("Horizontal Histogram:\n");
    printHorizontalHistogram(values, n);

    printf("\nVertical Histogram:\n");
    printVerticalHistogram(values, n);

    return 0;
}