#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void init_matrix(matrix *mat, int level) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            mat->grid[i][j] = 0;
        }
    }
    mat->level = level;
    mat->zeroes = 16;
}

void spawn_tile(matrix *mat) {
    int pos = rand() % mat->zeroes, num = 2 + 2 * (rand() % 10 == 0), curr = -1;
    for(int i = 0; i < 4 && curr < pos; i++) {
        for(int j = 0; j < 4 && curr < pos; j++) {
            if(mat->grid[i][j] == 0) {
                curr++;
                if(curr == pos) {
                    mat->grid[i][j] = num;
                }
            }
        }
    }
    mat->zeroes--;
}

void print_matrix(matrix *mat) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", mat->grid[i][j]);
        }
        printf("\n");
    }
}

    
