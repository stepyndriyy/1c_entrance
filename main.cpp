//#include "CardStack.h"
#include <iostream>
#include <vector>
#include "src/AI.h"


using namespace std;

int main() {
    CardStack empty;
    vector<Card> tmp
        = {six, seven, eight, nine, ten, jack, lady, king, ace};
    CardStack deque(tmp);
    vector<CardStack> input = {empty, empty, empty, empty, empty,
                               empty, empty, deque};
    Solitaire solitaire(input);
    AI ai(solitaire);
    cout << ai.play() << '\n';
    return 0;
}
