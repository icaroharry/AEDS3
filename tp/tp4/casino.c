#include "casino.h"

void play_game(int S, int sum, int X, int M, int *sequence, int element, int k, int *bigger) {
    if(sum + element <= X && k < S) {
        play_game(S, sum + element, X, M, sequence, sequence[k + 1], k + 1, bigger);
    }
    if(sum - element >= 0 && k < S) {
        play_game(S, sum - element, X, M, sequence, sequence[k + 1], k + 1, bigger);
    }
    if(k == S) {
        (*bigger) = sum > (*bigger) ? sum : (*bigger);
    }
}
