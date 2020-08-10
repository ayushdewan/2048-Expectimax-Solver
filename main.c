#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "expectimax.h"

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));
    
    // testing code
    matrix mat;
    init_matrix(&mat);
    //spawn_tile(&mat);
    //spawn_tile(&mat);
    mat.grid[0][0] = 4;
    mat.grid[1][0] = mat.grid[2][0] = mat.grid[3][0] = 2;
    mat.grid[1][3] = mat.grid[2][3] = 2;
    mat.grid[0][3] = 8;
    mat.grid[3][3] = 4;
    mat.zeroes = 8;
    print_matrix(&mat);
    puts("");
    
    action a = expectimax(&mat, 0, 4);
    printf("%d %.2f\n", a.move, a.value);
    return 0;
}
