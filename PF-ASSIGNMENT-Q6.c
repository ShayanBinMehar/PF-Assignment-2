#include <stdio.h>

int winningMove(int N) {

    if (N % 5 == 0) {
        return -1;
    }

    return N % 5;
}

int main() {
    int N;

    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    int move = winningMove(N);

    if (move == -1) {
        printf("A cannot win.\n");
    } else {
        printf("A should pick %d matchsticks on his first turn to win.\n", move);
    }

    return 0;
}