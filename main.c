#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));

    matrix mat;
    init_matrix(&mat, 0);
    spawn_tile(&mat);
    spawn_tile(&mat);
    print_matrix(&mat);
    printf("Tree level: %d\n", mat.level);
    printf("Zeroes: %d\n", mat.zeroes);
    return 0;
}
