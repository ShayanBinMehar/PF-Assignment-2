#include <stdio.h>

#define SIZE 5

void displayGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void updatePosition(char grid[SIZE][SIZE], int *playerX, int *playerY, int newX, int newY) {
    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
        if (grid[newX][newY] == 'X') {
            printf("Obstacle! You can't move there.\n");
        } else {
            if (grid[newX][newY] == 'I') {
                printf("Item collected!\n");
            }
            grid[*playerX][*playerY] = ' '; // Clear old position
            *playerX = newX;
            *playerY = newY;
            grid[*playerX][*playerY] = 'P'; // Update player position
        }
    } else {
        printf("Invalid move! Out of bounds.\n");
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {',', ',', 'I', 'X', ','},
        {',', 'X', ',', ',', ','},
        {'I', ',', 'X', 'X', ','},
        {',', ',', 'I', 'X', ','},
        {',', 'X', ',', ',', 'P'}
    };

    int playerX = 4, playerY = 4; // Initial player position

    char move;
    int newX, newY;
    
    while (1) {
        displayGrid(grid);
        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        switch (move) {
            case 'W': case 'w':
                newX = playerX - 1;
                newY = playerY;
                break;
            case 'S': case 's':
                newX = playerX + 1;
                newY = playerY;
                break;
            case 'A': case 'a':
                newX = playerX;
                newY = playerY - 1;
                break;
            case 'D': case 'd':
                newX = playerX;
                newY = playerY + 1;
                break;
            case 'Q': case 'q':
                printf("Quitting the game.\n");
                return 0;
            default:
                printf("Invalid input! Use W, A, S, D, or Q.\n");
                continue;
        }

        updatePosition(grid, &playerX, &playerY, newX, newY);
    }

    return 0;
}
