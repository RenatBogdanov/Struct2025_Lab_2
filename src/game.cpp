#include "game.h"
#include <iostream>
#include <vector>
#include <cstdint>

#include "game.h"

namespace game {

    
    Game::Game() {
    }

    Game::~Game() {
    }

    RenderGame::RenderGame() {
    }

    RenderGame::~RenderGame() {
    }

    Node::Node() {
    }

    Node::~Node() {
    }

    void Node::set_number(int number) {
        number_ = number;
    }

    void Node::set_strength(int strength) {
        strength_ = strength;
    }

    void Node::set_transitions(std::vector<int> transitions) {
        transitions_ = transitions;
    }

    int Node::get_number() {
        return number_;
    }

    int Node::get_strength() {
        return strength_;
    }

    std::vector<int> Node::get_transitions() {
        return transitions_;
    }

    Hero::Hero() {
    }

    Hero::~Hero() {
    }

}
