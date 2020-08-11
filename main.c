#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "expectimax.h"

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));
    
    int event = 0;
    for(int i = 0; i < 10; i++) {
        matrix mat;
        init_matrix(&mat);
        spawn_tile(&mat);
        spawn_tile(&mat);
        //print_matrix(&mat);
        printf("%d\n", i + 1);
        
        while(1) {
            action a = expectimax(&mat, 0, 4);
            if(a.move == 0) mat = push_north(&mat);
            else if(a.move == 1) mat = push_south(&mat);
            else if(a.move == 2) mat = push_east(&mat);
            else if(a.move == 3) mat = push_west(&mat);
            else { puts("done"); break; };
            spawn_tile(&mat);
            //print_matrix(&mat);
            //printf("");
        }
        
        int solved = 0;
        for(int j = 0; j < 4 && !solved; j++) {
            for(int k = 0; k < 4 && !solved; k++) {
                if(mat.grid[j][k] >= 2048) {
                    solved = 1;
                }
            }
        }
        event += solved;
        if(solved) puts("+");
    }
    printf("%d\n", event);
    return 0;
}
