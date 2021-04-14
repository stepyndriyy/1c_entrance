#include "AI.h"


Move AI::find_best_move(int depth) {
    int best_value = -1;
    Move best_move;
    auto moves = solitaire_.find_all_possible_moves();
    Solitaire copy = solitaire_;
    for (auto move : moves) {
        int current = find_best_move_support(copy.make_move(move), depth - 1);
        if (current < best_value) {
            best_value = current;
            best_move = move;
        }
    }
    return best_move;
}


int find_best_move_support(Solitaire& solitaire, int depth) {
    if (depth == 0) {
        return position_value(solitaire);
    }
    int best_value = -1;
    auto moves = solitaire.find_all_possible_moves();
    Solitaire copy = solitaire;
    for (auto move : moves) {
        int current = find_best_move_support(solitaire.make_move(move), depth - 1);

        if (current < best_value) {
            best_value = current;
        }
        solitaire = copy;
    }
    return best_value;
}

bool AI::play(int turn_cnt) {
    for (int i  = 0; i < turn_cnt; ++i) {
        auto all_moves = solitaire_.find_all_possible_moves();
        if (all_moves.size() == 0) {
            return false;
        }
        Move move = find_best_move();
        solitaire_.make_move(move);
        if (position_value(solitaire_) == 0) {
            return true;
        }
    }
    return false;
}

