#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));

    matrix mat;
    init_matrix(&mat, 0);
    //spawn_tile(&mat);
    //spawn_tile(&mat);
    mat.grid[0][0] = 4;
    mat.grid[1][0] = mat.grid[2][0] = mat.grid[3][0] = 2;
    mat.grid[1][3] = mat.grid[2][3] = 2;
    mat.grid[0][3] = 8;
    mat.grid[3][3] = 4;
    mat.zeroes = 8;
    print_matrix(&mat);
    printf("%d\n", mat.zeroes);    
    
    matrix north = push_south(&mat);
    print_matrix(&north);
    printf("%d\n", north.zeroes);
    
    matrix north2 = push_south(&north);
    print_matrix(&north2);
    printf("%d\n", north2.zeroes);

    matrix north3 = push_south(&north2);
    print_matrix(&north3);
    printf("%d\n", north3.zeroes);
    return 0;
}
