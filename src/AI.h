#ifndef INC_1C_ENTRANCE_TASK_AI_H
#define INC_1C_ENTRANCE_TASK_AI_H

#include "solitaire.h"


class AI {
public:
    AI (const Solitaire &solitaire) {
        solitaire_ = solitaire;
    }

    bool play(int turn_cnt = 1000);

private:
    Move find_best_move(int depth = 5);

private:
    Solitaire solitaire_;
};

int find_best_move_support(Solitaire& solitaire, int depth);

int position_value(Solitaire& solitaire) {
    int answer = 72;
    for (int i = 0; i < 8; ++i) {
        CardStack current = solitaire.take_deck(i);
        answer -= current.find_value_function();
    }
    return answer;
}

#endif //INC_1C_ENTRANCE_TASK_AI_H
