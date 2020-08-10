#include "matrix.h"
#include "expectimax.h"

double value(matrix *state) {
    return 1.0;
}

action expectimax(matrix *state, int depth, int max_depth) {
    action a;
    a.value = 0.0;
    a.move = -1;
    if(depth == 2 * max_depth) {
        a.value = value(state);
    } else if(depth % 2 == 0) {
        matrix next_state[4] = {push_north(state), push_south(state), push_east(state), push_west(state)};
        for(int i = 0; i < 4; i++) {
            double val = expectimax(next_state + i, depth + 1, max_depth).value;
            if(val > a.value) {
                a.value = val;
                a.move = i;
            }
        }
    } else {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(state->grid[i][j] == 0) {
                    matrix next_state2 = *state, next_state4 = *state;
                    next_state2.grid[i][j] = 2;
                    next_state4.grid[i][j] = 4;
                    next_state2.zeroes--, next_state4.zeroes--;
                    a.value += 0.9 / state->zeroes * expectimax(&next_state2, depth + 1, max_depth).value;
                    a.value += 0.1 / state->zeroes * expectimax(&next_state4, depth + 1, max_depth).value;
                }
            }
        }
    }
    return a;
}


