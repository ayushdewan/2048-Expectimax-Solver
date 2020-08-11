#include "matrix.h"
#include "expectimax.h"

double max(double a, double b) {
    return (a > b) * a + (a <= b) * b;
}

double value(matrix *state) {
    double sum1 = max(state->grid[0][0], state->grid[0][3]), sum2 = max(state->grid[0][0], state->grid[3][0]), 
           sum3 = max(state->grid[3][0], state->grid[3][3]), sum4 = max(state->grid[0][3], state->grid[3][3]);
    double top = max(sum1, sum3);
    for(int i = 0; i < 4; i++) {
        sum1 += state->grid[0][i];
        sum2 += state->grid[i][0];
        sum3 += state->grid[3][i];
        sum4 += state->grid[i][3];
    }
    double result = max(max(sum1, sum2), max(sum3, sum4)) + (top / 4) * state->zeroes;
    return result;
}

action expectimax(matrix *state, int depth, int max_depth) {
    action a = {-1, 0.0};
    if(depth == 2 * max_depth) {
        a.value = value(state);
    } else if(depth % 2 == 0) {
        a.value = -2048 * 2;
        matrix next_state[4] = {push_north(state), push_south(state), push_east(state), push_west(state)};
        for(int i = 0; i < 4; i++) {
            if(is_equal(state, next_state + i)) continue;
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


