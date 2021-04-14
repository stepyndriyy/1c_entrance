#include "CardStack.h"
#include  <stdexcept>


std::size_t CardStack::size() {
    return stack_.size();
}

Card CardStack::watch_at(std::size_t pos) {
    if (!is_opened(pos)) {
        throw std::invalid_argument("closed card");
        //maybe better to return empty card
    }
    return stack_.at(pos).card;
}

Card CardStack::top() {
    return stack_.at(0).card;
}

CardStack& CardStack::put_on_other_stack(CardStack &other, std::size_t count) {
    if (!is_possible_to_put(other, count)) {
        throw std::invalid_argument("invalid move");
    }
    move_cards(other, count);
    other.clear_folded();
    return *this;
}

bool CardStack::is_possible_to_put(CardStack &other, std::size_t count) {
    if (!is_opened(count - 1)) {
        return false;
    }
    if (!rowed(count) || watch_at(count - 1) >= other.top()) {
        return false;
    }
    return true;
}

void CardStack::move_cards(CardStack &other, std::size_t count) {
    for (std::size_t i = count - 1; i >= 0; --i) {
        other.add_top(stack_.at(i));
    }
    for (std::size_t i = 0; i < count; ++i) {
        pop_top();
    }
    open(0);
}

void CardStack::open(std::size_t pos) {
    stack_.at(pos).opened = true;
}

void CardStack::add_top(const DeckCard &card) {
    stack_.push_front(card);
}

void CardStack::pop_top() {
    stack_.pop_front();
}

CardStack::CardStack(const std::vector<Card> &cards) {
    stack_.push_front(DeckCard(cards[0], true));
    for (std::size_t i = 1; i < cards.size(); ++i) {
        stack_.push_front(DeckCard(cards[i], false));
    }
}

bool CardStack::is_opened(std::size_t pos) {
    return stack_.at(pos).opened;
}

bool CardStack::rowed(std::size_t count) {
    for (int pos = 1; pos < count; ++pos) {
        if (!is_opened(pos)) {
            return false;
        }
        if (watch_at(pos) <= watch_at(pos - 1)) {
            return false;
        }
    }
    return true;
}


bool CardStack::folded() {
    return rowed(DIFF_CARDS_CNT);
}

void CardStack::clear_folded() {
    if (!folded()) {
        return;
    }
    for (int pos = 0; pos < DIFF_CARDS_CNT; ++pos) {
        pop_top();
    }
    open(0);
}

int CardStack::find_value_function() {
    int answer;
    for (std::size_t i = 1; i < size(); ++i) {
        if (!is_opened(i)) {
            answer += size() - i;
            return answer;
        }
        if (stack_[i].card <= stack_[i-1].card) {
            answer++;
        }
    }
    return answer;
}