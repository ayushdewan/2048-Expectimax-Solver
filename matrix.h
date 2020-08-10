#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    int grid[4][4]; // grid: 2048 grid, level: 0 = probabilistic (max of children), 1 = expected value summation of children
    int level;
    int zeroes; // number of zeroes in the grid
} matrix;

void init_matrix(matrix *mat, int level);
void spawn_tile(matrix *mat);
void print_matrix(matrix *mat);
matrix push_north(matrix *mat);
matrix push_south(matrix *mat);
matrix push_east(matrix *mat);
matrix push_west(matrix *mat);

#endif
