#include "solitaire.h"

Solitaire::Solitaire(const std::vector<CardStack>& decks)
    : decks_(decks) {
}

CardStack& Solitaire::take_deck(std::size_t deck_num) {
    return decks_.at(deck_num);
}

std::vector<Move> Solitaire::find_all_possible_moves() {
    std::vector<Move> possible_moves;
    for (std::size_t from_num = 0; from_num < DECK_COUNT; ++from_num) {
        CardStack current_deck = take_deck(from_num);
        for (std::size_t cnt = 1; cnt < current_deck.size(); ++cnt) {
            for (std::size_t to_num = 0; to_num < DECK_COUNT; ++to_num) {
                if (from_num == to_num) {
                    continue;
                }
                if (current_deck.is_possible_to_put(take_deck(to_num), cnt)) {
                    possible_moves.push_back(Move(from_num, to_num, cnt));
                }
            }
        }
    }
    return possible_moves;
}

Solitaire& Solitaire::make_move(const Move &move) {
    CardStack from = take_deck(move.deck_num_from);
    CardStack to = take_deck(move.deck_num_to);
    from.put_on_other_stack(to, move.cards_count);
    return *this;
}