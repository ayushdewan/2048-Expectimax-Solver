#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "matrix.h"
#include "expectimax.h"

matrix mat;

void *compute_move(void *arg) {
    matrix *mat2 = (matrix *) arg;
    double *value_ptr = (double *) malloc(sizeof(double));
    if(is_equal(&mat, mat2)) *value_ptr = -4096;
    else *value_ptr = expectimax(mat2, 1, 4).value;
    return value_ptr;
}

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));
    
    init_matrix(&mat);
    spawn_tile(&mat);
    spawn_tile(&mat);
    print_matrix(&mat);
    puts("");
    
    while(1) {
        pthread_t *thread_group = malloc(sizeof(pthread_t) * 4);
        matrix next_state[4] = {push_north(&mat), push_south(&mat), push_east(&mat), push_west(&mat)};
        for(int i = 0; i < 4; i++) {
            pthread_create(&thread_group[i], NULL, compute_move, next_state + i);
        }

        double *values[4];
        action a = {-1, -4096};
        for(int i = 0; i < 4; i++) {
            pthread_join(thread_group[i], (void *)(values + i));
        }

        for(int i = 0; i < 4; i++) {
            if(*values[i] > a.value) {
                a.value = *values[i];
                a.move = i;
            }
            free(values[i]);
        }
        free(thread_group);
        
        if(a.move == -1) { puts("done"); break; }
        else mat = next_state[a.move];
        spawn_tile(&mat);
        print_matrix(&mat);
    }
    return 0;
}
