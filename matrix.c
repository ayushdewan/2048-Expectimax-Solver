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

matrix push_north(matrix *mat) {
    matrix result;
    init_matrix(&result, 1);
    result.zeroes = mat->zeroes;
    for(int j = 0; j < 4; j++) {
        int i = 0;
        for(i = 0; i < 4; i++) {
            if(mat->grid[i][j] != 0) {
                result.grid[0][j] = mat->grid[i][j];
                i++;
                break;
            }
        }
        int combs = 0;
        for(int k = 0; k < 3 && i < 4; k++) {
            for(; i < 4; i++) {
                if(mat->grid[i][j] != 0) {
                    if(mat->grid[i][j] == result.grid[k][j]) {
                        result.grid[k][j] <<= 1;
                        combs++;
                    } else {
                        result.grid[k + 1 - combs][j] = mat->grid[i][j];
                    }
                    i++;
                    break;
                }
            }
        }
        result.zeroes += combs;
    }
    return result;
}

matrix push_south(matrix *mat) {
    matrix result;
    init_matrix(&result, 1);
    result.zeroes = mat->zeroes;
    for(int j = 0; j < 4; j++) {
        int i = 3;
        for(i = 3; i >= 0; i--) {
            if(mat->grid[i][j] != 0) {
                result.grid[3][j] = mat->grid[i][j];
                i--;
                break;
            }
        }
        int combs = 0;
        for(int k = 3; k >= 0 && i >= 0; k--) {
            for(; i >= 0; i--) {
                if(mat->grid[i][j] != 0) {
                    if(mat->grid[i][j] == result.grid[k][j]) {
                        result.grid[k][j] <<= 1;
                        combs++;
                    } else {
                        result.grid[k - 1 + combs][j] = mat->grid[i][j];
                    }
                    i--;
                    break;
                }
            }
        }
        result.zeroes += combs;
    }
    return result;
}

matrix push_east(matrix *mat) {
    matrix result;
    init_matrix(&result, 1);
    result.zeroes = mat->zeroes;
    for(int i = 0; i < 4; i++) {
        int j = 3;
        for(j = 3; j >= 0; j--) {
            if(mat->grid[i][j] != 0) {
                result.grid[i][3] = mat->grid[i][j];
                j--;
                break;
            }
        }
        int combs = 0;
        for(int k = 3; k >= 0 && j >= 0; k--) {
            for(; j >= 0; j--) {
                if(mat->grid[i][j] != 0) {
                    if(mat->grid[i][j] == result.grid[i][k]) {
                        result.grid[i][k] <<= 1;
                        combs++;
                    } else {
                        result.grid[i][k - 1 + combs] = mat->grid[i][j];
                    }
                    j--;
                    break;
                }
            }
        }
        result.zeroes += combs;
    }
    return result;
}

matrix push_west(matrix *mat) {
    matrix result;
    init_matrix(&result, 1);
    result.zeroes = mat->zeroes;
    for(int i = 0; i < 4; i++) {
        int j = 0;
        for(j = 0; j < 4; j++) {
            if(mat->grid[i][j] != 0) {
                result.grid[i][0] = mat->grid[i][j];
                j++;
                break;
            }
        }
        int combs = 0;
        for(int k = 0; k < 3 && j < 4; k++) {
            for(; j < 4; j++) {
                if(mat->grid[i][j] != 0) {
                    if(mat->grid[i][j] == result.grid[i][k]) {
                        result.grid[i][k] <<= 1;
                        combs++;
                    } else {
                        result.grid[i][k + 1 - combs] = mat->grid[i][j];
                    }
                    j++;
                    break;
                }
            }
        }
        result.zeroes += combs;
    }
    return result;
}

