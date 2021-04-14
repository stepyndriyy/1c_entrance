#ifndef INC_1C_ENTRANCE_TASK_CARDSTACK_H
#define INC_1C_ENTRANCE_TASK_CARDSTACK_H

#include "card.h"
#include <vector>
#include <deque>


class CardStack {
public:

    //for debug
    CardStack() {}

    CardStack(const std::vector<Card> &cards);

    std::size_t size();
    Card watch_at(std::size_t pos);
    Card top();

    bool is_possible_to_put(CardStack &other, std::size_t count);
    CardStack& put_on_other_stack(CardStack &other, std::size_t count);

    // not enough time
    int find_value_function();

private:
    struct DeckCard {
        DeckCard(Card c, bool a) : card(c), opened(a) {}
        Card card;
        bool opened=false;
    };

    void move_cards(CardStack &other, std::size_t count);
    void add_top(const DeckCard &card);
    void pop_top();
    bool is_opened(std::size_t pos);
    bool folded();
    void clear_folded();
    void open(std::size_t pos);
    bool rowed(std::size_t count);
private:
    std::deque<DeckCard> stack_;

};


#endif //INC_1C_ENTRANCE_TASK_CARDSTACK_H
