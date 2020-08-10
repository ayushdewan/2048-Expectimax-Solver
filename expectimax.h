#ifndef EXPECTIMAX_H
#define EXPECTIMAX_H

#include "matrix.h"

typedef struct action {
    int move;
    double value;
} action;


action expectimax(matrix *state, int depth, int max_depth);
double value(matrix *state);

#endif
