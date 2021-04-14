#ifndef INC_1C_ENTRANCE_TASK_SOLITAIRE_H
#define INC_1C_ENTRANCE_TASK_SOLITAIRE_H

#include "CardStack.h"

struct Move {
public:
    Move(std::size_t a, std::size_t b, std::size_t c)
        : deck_num_from(a), deck_num_to(b), cards_count(c) {}
    Move(){}
    std::size_t deck_num_from;
    std::size_t deck_num_to;
    std::size_t cards_count;
};


class Solitaire {
public:
    Solitaire() {};
    Solitaire(const std::vector<CardStack>& decks);

    CardStack& take_deck(std::size_t deck_num);
    Solitaire& make_move(const Move& move);
    std::vector<Move> find_all_possible_moves();
private:

private:
    static const std::size_t DECK_COUNT = 8;
    std::vector<CardStack> decks_;
};


#endif //INC_1C_ENTRANCE_TASK_SOLITAIRE_H
