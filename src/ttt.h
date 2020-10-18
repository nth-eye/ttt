#include <cstring>
#include <cassert>
#include <sstream>
#include <iostream>
#include <array>
#include <vector>
#include <limits>

#pragma once

namespace ttt {

using Action = int;
using ActionList = std::vector<int>;
using State = std::array<int, 9>;

enum : int { EMPTY, X, O, BOTH };

class Game {
    int turn = X;
    State state = {};
public:
    Game() = default;
    Game(State state_) : state(std::move(state_)) {}

    void reset();
    void test();

    int result() const;
    int to_play() const     { return turn; }
    bool terminal() const   { return result() != EMPTY; }
    bool legal(Action move) const;
    float reward() const;
    float act(Action move);

    State get_state() const { return state; }
    Action ask_input() const;
    ActionList legal_actions() const;

    std::string str() const;
};

}