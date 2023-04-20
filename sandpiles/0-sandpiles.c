#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sandpiles.h"

void add_sandpiles(int sandpile1[3][3], int sandpile2[3][3]);
void topple_sandpile(int sandpile[3][3]);
bool is_unstable(int sandpile[3][3]);
void print_sandpile(int sandpile[3][3]);
void print_grid(int grid[3][3]);

int j;
int i;

void sandpiles_sum(int sandpile1[3][3], int sandpile2[3][3]) {
    add_sandpiles(sandpile1, sandpile2);

    while (is_unstable(sandpile1)) {
        topple_sandpile(sandpile1);
    }
}

void add_sandpiles(int sandpile1[3][3], int sandpile2[3][3]) {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sandpile1[i][j] += sandpile2[i][j];
        }
    }
}

void topple_sandpile(int sandpile[3][3]) {
    int temp_sandpile[3][3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            temp_sandpile[i][j] = sandpile[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (temp_sandpile[i][j] >= 4) {
                sandpile[i][j] -= 4;
                if (i > 0) sandpile[i - 1][j]++;
                if (i < 3 - 1) sandpile[i + 1][j]++;
                if (j > 0) sandpile[i][j - 1]++;
                if (j < 3 - 1) sandpile[i][j + 1]++;
            }
        }
    }
}

bool is_unstable(int sandpile[3][3]) {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (sandpile[i][j] >= 4) return true;
        }
    }
    return false;
}

void print_sandpile(int sandpile[3][3]) {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", sandpile[i][j]);
        }
        printf("\n");
    }
}

void print_grid(int grid[3][3]) {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}




